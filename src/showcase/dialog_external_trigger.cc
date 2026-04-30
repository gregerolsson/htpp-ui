#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(dialog_external_trigger) {
    HT_DIV(class_ = "space-y-4") {
        HT_USE(dialog::trigger, {.for_ = "external-dialog"}) {
            HT_USE(button::button, {.variant = button::outline}) {
                os << "Open External Dialog";
            }
        }
        HT_USE(dialog::dialog, {.id = "external-dialog"}) {
            HT_USE(dialog::content, {.class_ = "max-w-md"}) {
                HT_USE(dialog::header, {}) {
                    HT_USE(dialog::title, {}) {
                        os << "External Dialog";
                    }
                    HT_USE(dialog::description, {}) {
                        os << "This dialog can be triggered from anywhere on the page.";
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
