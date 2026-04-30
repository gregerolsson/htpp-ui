#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(dialog_no_modal) {
    HT_DIV(class_ = "space-y-4") {
        HT_USE(dialog::trigger, {.for_ = "non-modal-dialog"}) {
            HT_USE(button::button, {.variant = button::outline}) {
                os << "Open Non-modal Dialog";
            }
        }
        HT_USE(dialog::dialog, {.id = "non-modal-dialog"}) {
            HT_USE(dialog::content, {.class_ = "max-w-md", .disable_modal = true}) {
                HT_USE(dialog::header, {}) {
                    HT_USE(dialog::title, {}) {
                        os << "Non-Modal Mode";
                    }
                    HT_USE(dialog::description, {}) {
                        os << "This dialog does not use a backdrop.";
                    }
                }
                HT_USE(dialog::footer, {}) {
                    HT_USE(dialog::close, {}) {
                        HT_USE(button::button, {}) {
                            os << "Close";
                        }
                    }
                }
            }
        }
    }
}
