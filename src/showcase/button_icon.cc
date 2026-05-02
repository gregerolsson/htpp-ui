#include "htpp.ico.hh"
#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(button_icon) {
    HT_USE(button::button, {.variant = button::secondary, .size = button::icon}) {
        icon::icon(os, {
            .class_ = "size-4",
            .glyph = glyph::chevron_right
        });
    }
}
