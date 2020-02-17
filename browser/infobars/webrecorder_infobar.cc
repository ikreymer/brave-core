#include "brave/browser/infobars/webrecorder_infobar.h"
#include "brave/browser/infobars/webrecorder_infobar_delegate.h"

#include <memory>
#include <utility>

#include "base/bind.h"
#include "base/logging.h"
#include "brave/common/extensions/extension_constants.h"
#include "chrome/browser/infobars/infobar_service.h"
#include "chrome/browser/ui/views/chrome_layout_provider.h"
#include "components/infobars/core/infobar_delegate.h"
#include "components/infobars/core/infobar.h"
#include "components/prefs/pref_service.h"
#include "components/strings/grit/components_strings.h"
#include "components/user_prefs/user_prefs.h"
#include "content/public/browser/browser_context.h"

#include "ui/views/controls/button/label_button.h"
#include "ui/views/controls/button/md_text_button.h"
#include "ui/views/controls/label.h"
#include "ui/views/view_class_properties.h"


WebrecorderInfoBar::WebrecorderInfoBar(std::unique_ptr<WebrecorderInfoBarDelegate> delegate)
    : InfoBarView(std::move(delegate)) {
  auto* delegate_ptr = GetDelegate();
  label_ = CreateLabel(delegate_ptr->GetMessageText());
  AddChildView(label_);

  //const auto buttons = delegate_ptr->GetButtons();
  cancel_button_ = CreateButton();
  cancel_button_->SetProminent(true);
}

WebrecorderInfoBar::~WebrecorderInfoBar() {
}

void WebrecorderInfoBar::Layout() {
  InfoBarView::Layout();

  int x = StartX();
  Views views;
  views.push_back(label_);
  AssignWidths(&views, std::max(0, EndX() - x - NonLabelWidth()));

  ChromeLayoutProvider* layout_provider = ChromeLayoutProvider::Get();

  label_->SetPosition(gfx::Point(x, OffsetY(label_)));
  if (!label_->GetText().empty())
    x = label_->bounds().right() +
        layout_provider->GetDistanceMetric(
            views::DISTANCE_RELATED_LABEL_HORIZONTAL);

  if (cancel_button_)
    cancel_button_->SetPosition(gfx::Point(x, OffsetY(cancel_button_)));
}

void WebrecorderInfoBar::SetLabelText(const base::string16& new_text) {
  label_->SetText(new_text);
}

void WebrecorderInfoBar::ButtonPressed(views::Button* sender,
                                   const ui::Event& event) {
  if (!owner())
    return;  // We're closing; don't call anything, it might access the owner.
  WebrecorderInfoBarDelegate* delegate = GetDelegate();

  if (sender == cancel_button_) {
    if (delegate->Cancel())
      RemoveSelf();
  } else {
    InfoBarView::ButtonPressed(sender, event);
  }
}

int WebrecorderInfoBar::ContentMinimumWidth() const {
  return NonLabelWidth();
}

WebrecorderInfoBarDelegate* WebrecorderInfoBar::GetDelegate() {
  infobars::InfoBarDelegate* theDelegate = delegate();
  return (theDelegate && theDelegate->GetIdentifier() == infobars::InfoBarDelegate::WEBRECORDER_INFOBAR_DELEGATE) ?
    static_cast<WebrecorderInfoBarDelegate*>(theDelegate) : nullptr;
}

views::MdTextButton* WebrecorderInfoBar::CreateButton() {
  auto button =
      views::MdTextButton::Create(this, GetDelegate()->GetButtonLabel());
  button->SetProperty(
      views::kMarginsKey,
      gfx::Insets(ChromeLayoutProvider::Get()->GetDistanceMetric(
                      DISTANCE_TOAST_CONTROL_VERTICAL),
                  0));
  auto* button_ptr = AddChildView(std::move(button));
  button_ptr->SizeToPreferredSize();
  return button_ptr;
}

int WebrecorderInfoBar::NonLabelWidth() const {
  ChromeLayoutProvider* layout_provider = ChromeLayoutProvider::Get();

  const int label_spacing = layout_provider->GetDistanceMetric(
      views::DISTANCE_RELATED_LABEL_HORIZONTAL);
  //const int button_spacing = layout_provider->GetDistanceMetric(
  //    views::DISTANCE_RELATED_BUTTON_HORIZONTAL);

  return 2*label_spacing + cancel_button_->width();
}

