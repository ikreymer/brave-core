/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_BROWSER_EXTENSIONS_API_BRAVE_WEBRECORDER_API_H_
#define BRAVE_BROWSER_EXTENSIONS_API_BRAVE_WEBRECORDER_API_H_

#include "extensions/browser/extension_function.h"

namespace extensions {
namespace api {

class BraveWebrecorderShowInfoBarFunction : public ExtensionFunction {
 public:
  DECLARE_EXTENSION_FUNCTION("braveWebrecorder.showInfoBar", UNKNOWN)

 protected:
  ~BraveWebrecorderShowInfoBarFunction() override {}

  ResponseAction Run() override;
};

class BraveWebrecorderSetSizeMsgFunction : public ExtensionFunction {
 public:
  DECLARE_EXTENSION_FUNCTION("braveWebrecorder.setSizeMsg", UNKNOWN)

 protected:
  ~BraveWebrecorderSetSizeMsgFunction() override {}

  ResponseAction Run() override;
};

class BraveWebrecorderHideInfoBarFunction : public ExtensionFunction {
 public:
  DECLARE_EXTENSION_FUNCTION("braveWebrecorder.hideInfoBar", UNKNOWN)

 protected:
  ~BraveWebrecorderHideInfoBarFunction() override {}

  ResponseAction Run() override;
};


}  // namespace api
}  // namespace extensions

#endif  // BRAVE_BROWSER_EXTENSIONS_API_BRAVE_WEBRECORDER_API_H_
