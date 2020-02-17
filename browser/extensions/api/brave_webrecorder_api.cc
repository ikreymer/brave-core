#include "brave/browser/extensions/api/brave_webrecorder_api.h"

#include <map>
#include <memory>
#include <string>
#include <utility>

#include "base/bind.h"
#include "base/strings/string_number_conversions.h"
#include "brave/common/extensions/extension_constants.h"
#include "brave/browser/infobars/webrecorder_infobar_delegate.h"
#include "chrome/browser/extensions/api/tabs/tabs_constants.h"
#include "chrome/browser/extensions/chrome_extension_function_details.h"
#include "chrome/browser/extensions/extension_tab_util.h"
#include "chrome/browser/profiles/profile.h"
#include "components/infobars/core/infobar_delegate.h"
#include "components/infobars/core/infobar.h"
#include "content/public/browser/web_contents.h"

#include "chrome/browser/infobars/infobar_service.h"
#include "brave/common/extensions/api/brave_webrecorder.h"

namespace extensions {
namespace api {


ExtensionFunction::ResponseAction BraveWebrecorderShowInfoBarFunction::Run() {
  std::unique_ptr<brave_webrecorder::ShowInfoBar::Params> params(
      brave_webrecorder::ShowInfoBar::Params::Create(*args_));
  EXTENSION_FUNCTION_VALIDATE(params.get());

  Profile* profile = Profile::FromBrowserContext(browser_context());

  // Get web contents for this tab
  content::WebContents* contents = nullptr;
  if (!ExtensionTabUtil::GetTabById(
        params->tab_id,
        profile,
        false,
        nullptr,
        nullptr,
        &contents,
        nullptr)) {
    return RespondNow(Error(tabs_constants::kTabNotFoundError,
                            base::NumberToString(params->tab_id)));
  }

  if (contents) {
    InfoBarService* infobar_service =
        InfoBarService::FromWebContents(contents);

    if (infobar_service) {
      WebrecorderInfoBarDelegate::Create(infobar_service);
    }
  }

  return RespondNow(NoArguments());
}



ExtensionFunction::ResponseAction BraveWebrecorderSetSizeMsgFunction::Run() {
  std::unique_ptr<brave_webrecorder::SetSizeMsg::Params> params(
      brave_webrecorder::SetSizeMsg::Params::Create(*args_));
  EXTENSION_FUNCTION_VALIDATE(params.get());

  Profile* profile = Profile::FromBrowserContext(browser_context());

  // Get web contents for this tab
  content::WebContents* contents = nullptr;
  if (!ExtensionTabUtil::GetTabById(
        params->tab_id,
        profile,
        false,
        nullptr,
        nullptr,
        &contents,
        nullptr)) {
    return RespondNow(Error(tabs_constants::kTabNotFoundError,
                            base::NumberToString(params->tab_id)));
  }


  if (contents) {
    InfoBarService* infobar_service =
        InfoBarService::FromWebContents(contents);

    if (infobar_service) {
      for (size_t i = 0; i < infobar_service->infobar_count(); i++) {
        infobars::InfoBarDelegate* delegate =
          infobar_service->infobar_at(i)->delegate();
        if (delegate->GetIdentifier() == WebrecorderInfoBarDelegate::WEBRECORDER_INFOBAR_DELEGATE) {
            (static_cast<WebrecorderInfoBarDelegate*>(delegate))->SetSizeMsg(params->size_msg);
        }
      }
    }
  }

  return RespondNow(NoArguments());
}



}  // namespace api
}  // namespace extensions


