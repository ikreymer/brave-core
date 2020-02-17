#ifndef BRAVE_BROWSER_INFOBARS_WEBRECORDER_INFOBAR_H_
#define BRAVE_BROWSER_INFOBARS_WEBRECORDER_INFOBAR_H_

#include "base/compiler_specific.h"
#include "base/macros.h"
#include "chrome/browser/ui/views/infobars/infobar_view.h"
#include "components/infobars/core/confirm_infobar_delegate.h"

namespace views {
class Button;
class Label;
class MdTextButton;
}

class WebrecorderInfoBarDelegate;

class WebrecorderInfoBar : public InfoBarView {
 public:
  explicit WebrecorderInfoBar(std::unique_ptr<WebrecorderInfoBarDelegate> delegate);
  ~WebrecorderInfoBar() override;

  // InfoBarView:
  void Layout() override;
  void ButtonPressed(views::Button* sender, const ui::Event& event) override;

  void SetLabelText(const base::string16& new_text);

 protected:
  // InfoBarView:
  int ContentMinimumWidth() const override;

 private:

  WebrecorderInfoBarDelegate* GetDelegate();

  // Creates a button suitable for use as either OK or Cancel.
  views::MdTextButton* CreateButton();

  // Returns the width of all content other than the label and link.  Layout()
  // uses this to determine how much space the label and link can take.
  int NonLabelWidth() const;

  views::Label* label_ = nullptr;
  views::MdTextButton* cancel_button_ = nullptr;

  DISALLOW_COPY_AND_ASSIGN(WebrecorderInfoBar);
};

#endif  //BRAVE_BROWSER_INFOBARS_WEBRECORDER_INFOBAR_H_


