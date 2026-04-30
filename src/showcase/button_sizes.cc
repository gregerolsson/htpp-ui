#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(button_sizes) {
    HT_DIV(class_ = "flex flex-wrap items-center gap-4") {
        HT_USE(button::button, {.variant = button::secondary, .size = button::sm}) {
            os << "Small";
        }
        HT_USE(button::button, {.variant = button::secondary}) {
            os << "Default";
        }
        HT_USE(button::button, {.variant = button::secondary, .size = button::lg}) {
            os << "Large";
        }
        HT_USE(button::button, {.variant = button::secondary, .size = button::icon}) {
            HT_SPAN() { os << "icon::chevron_right"; }
        }
    }
}
