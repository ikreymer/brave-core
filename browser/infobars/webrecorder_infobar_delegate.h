/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_BROWSER_INFOBARS_WEBRECORDER_INFOBAR_DELEGATE_H_
#define BRAVE_BROWSER_INFOBARS_WEBRECORDER_INFOBAR_DELEGATE_H_

#include "base/compiler_specific.h"
#include "base/macros.h"
#include "base/strings/string16.h"
#include "components/infobars/core/infobar_delegate.h"
#include "url/gurl.h"

class WebrecorderInfoBar;

class InfoBarService;
class PrefService;

class WebrecorderInfoBarDelegate : public infobars::InfoBarDelegate {
 public:
  static void Create(InfoBarService* infobar_service);

  void SetSizeMsg(const std::string& sizeMsg);

  ~WebrecorderInfoBarDelegate() override;

 private:
  explicit WebrecorderInfoBarDelegate();

  friend class WebrecorderInfoBar;

  bool ShouldExpire(const NavigationDetails& details) const override;

  infobars::InfoBarDelegate::InfoBarIdentifier GetIdentifier() const override;
  void InfoBarDismissed() override;

  base::string16 GetMessageText() const;
  base::string16 GetButtonLabel() const;
  bool Cancel();

  bool EqualsDelegate(infobars::InfoBarDelegate* delegate) const override;

  base::string16 fullMsg;

  DISALLOW_COPY_AND_ASSIGN(WebrecorderInfoBarDelegate);

};

#endif  // BRAVE_BROWSER_INFOBARS_WEBRECORDER_INFOBAR_DELEGATE_H_
