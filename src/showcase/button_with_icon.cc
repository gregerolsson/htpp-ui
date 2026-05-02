#include "htpp.ico.hh"
#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(button_with_icon) {
    HT_USE(button::button, {.class_ = "flex gap-2 items-center", .variant = button::secondary}) {
        icon::icon(os, {.glyph = glyph::mail});
        os << "Login with Email";
    }
}
