#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(radio_form) {
    HT_DIV(class_ = "w-full max-w-sm") {
        HT_USE(form::item, {}) {
            HT_USE(form::item_flex, {}) {
                radio::radio(os, {.id = "r1", .name = "radio-form", .checked = true});
                HT_USE(form::label, {.for_ = "r1"}) {
                    os << "All new products";
                }
            }
            HT_USE(form::item_flex, {}) {
                radio::radio(os, {.id = "r2", .name = "radio-form", .disabled = true});
                HT_USE(form::label, {.for_ = "r2"}) {
                    os << "Create a wishlist (Coming Soon)";
                }
            }
            HT_USE(form::item_flex, {}) {
                radio::radio(os, {.id = "r3", .name = "radio-form"});
                HT_USE(form::label, {.for_ = "r3"}) {
                    os << "No notifications";
                }
            }
            HT_USE(form::description, {}) {
                os << "You can change your preferences at any time.";
            }
            HT_USE(form::message, {.variant = form::error}) {
                os << "We will send you an email when new products are available.";
            }
        }
    }
}
