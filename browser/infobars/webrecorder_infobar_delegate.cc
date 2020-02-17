/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/browser/infobars/webrecorder_infobar_delegate.h"
#include "brave/browser/infobars/webrecorder_infobar.h"

#include <memory>
#include <utility>

#include "base/strings/utf_string_conversions.h"
#include "brave/browser/ui/brave_pages.h"
#include "brave/common/extensions/extension_constants.h"
#include "brave/common/pref_names.h"
#include "brave/common/url_constants.h"
#include "brave/grit/brave_generated_resources.h"
#include "chrome/browser/infobars/infobar_service.h"
#include "chrome/browser/ui/browser_finder.h"
#include "chrome/grit/chromium_strings.h"
#include "components/infobars/core/infobar.h"
#include "components/prefs/pref_service.h"
#include "components/strings/grit/components_strings.h"
#include "components/user_prefs/user_prefs.h"
#include "content/public/browser/browser_context.h"
#include "ui/base/l10n/l10n_util.h"
#include "ui/views/vector_icons.h"

#include "chrome/browser/profiles/profile.h"
#include "content/public/browser/web_contents.h"


#if BUILDFLAG(ENABLE_EXTENSIONS)
#include "brave/common/extensions/api/brave_webrecorder.h"
#include "chrome/browser/extensions/extension_tab_util.h"
#include "extensions/browser/event_router.h"
//#include "extensions/browser/extension_api_frame_id_map.h"

using extensions::Event;
using extensions::EventRouter;
#endif




// static
void WebrecorderInfoBarDelegate::Create(InfoBarService* infobar_service) {
  std::unique_ptr<WebrecorderInfoBarDelegate> delegate(new WebrecorderInfoBarDelegate());

  infobar_service->AddInfoBar(
    std::make_unique<WebrecorderInfoBar>(
      std::move(delegate)));
}

WebrecorderInfoBarDelegate::WebrecorderInfoBarDelegate() {
  set_infobar(nullptr);
  SetSizeMsg("0");
}

WebrecorderInfoBarDelegate::~WebrecorderInfoBarDelegate() {}

void WebrecorderInfoBarDelegate::SetSizeMsg(const std::string& sizeMsg) {
  fullMsg = l10n_util::GetStringFUTF16(IDS_WEBRECORDER_RECORDING_STATUS, base::UTF8ToUTF16(sizeMsg));

  WebrecorderInfoBar* theInfoBar = static_cast<WebrecorderInfoBar*>(infobar());
  if (theInfoBar) {
    theInfoBar->SetLabelText(fullMsg);
  }
}

infobars::InfoBarDelegate::InfoBarIdentifier
WebrecorderInfoBarDelegate::GetIdentifier() const {
  return WEBRECORDER_INFOBAR_DELEGATE;
}

bool WebrecorderInfoBarDelegate::ShouldExpire(const NavigationDetails& details) const {
  return false;
}


void WebrecorderInfoBarDelegate::InfoBarDismissed() {
  content::WebContents* web_contents =
      InfoBarService::WebContentsFromInfoBar(infobar());

  if (web_contents) {
    Profile* profile =
      Profile::FromBrowserContext(web_contents->GetBrowserContext());

    EventRouter* event_router = EventRouter::Get(profile);
    if (profile && event_router) {
      extensions::api::brave_webrecorder::OnCanceled::Details details;
      details.tab_id = extensions::ExtensionTabUtil::GetTabId(web_contents);
      std::unique_ptr<base::ListValue> args(
        extensions::api::brave_webrecorder::OnCanceled::Create(details)
          .release());

      std::unique_ptr<Event> event(
        new Event(extensions::events::BRAVE_START,
          extensions::api::brave_webrecorder::OnCanceled::kEventName,
            std::move(args)));

      event_router->BroadcastEvent(std::move(event));
    }
  }
}

base::string16 WebrecorderInfoBarDelegate::GetMessageText() const {
  return fullMsg;
}

base::string16 WebrecorderInfoBarDelegate::GetButtonLabel() const {
  return base::UTF8ToUTF16("Cancel Recording");
}

bool WebrecorderInfoBarDelegate::Cancel() {
  InfoBarDismissed();
  return true;
}


bool WebrecorderInfoBarDelegate::EqualsDelegate(
    infobars::InfoBarDelegate* delegate) const {
  return GetIdentifier() == delegate->GetIdentifier();
}

