#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(button_with_icon) {
    HT_USE(button::button, {.class_ = "flex gap-2 items-center", .variant = button::secondary}) {
        HT_SPAN() { os << "icon::mail"; }
        os << "Login with Email";
    }
}
