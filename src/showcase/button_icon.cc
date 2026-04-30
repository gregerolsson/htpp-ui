#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(button_icon) {
    HT_USE(button::button, {.variant = button::secondary, .size = button::icon}) {
        HT_SPAN() { os << "icon::chevron_right"; }
    }
}
