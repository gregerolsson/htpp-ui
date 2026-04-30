#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(switch_form) {
    HT_DIV(class_ = "w-full max-w-sm") {
        HT_USE(form::item, {}) {
            HT_USE(form::item_flex, {}) {
                switch_::switch_(os, {.id = "airplane-mode", .name = "airplane"});
                HT_USE(form::label, {.for_ = "airplane-mode"}) {
                    os << "Airplane Mode";
                }
            }
            HT_USE(form::item_flex, {}) {
                switch_::switch_(os, {.id = "wifi-mode", .name = "wifi", .disabled = true});
                HT_USE(form::label, {.for_ = "wifi-mode"}) {
                    os << "Wi-Fi";
                }
            }
            HT_USE(form::item_flex, {}) {
                switch_::switch_(os, {.id = "bluetooth-mode", .name = "bluetooth", .checked = true});
                HT_USE(form::label, {.for_ = "bluetooth-mode"}) {
                    os << "Bluetooth";
                }
            }
            HT_USE(form::description, {}) {
                os << "Manage your devices connectivity options.";
            }
            HT_USE(form::message, {.variant = form::error}) {
                os << "Please configure your connectivity settings.";
            }
        }
    }
}
