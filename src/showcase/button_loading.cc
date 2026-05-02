#include "htpp.ico.hh"
#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(button_loading) {
    HT_USE(button::button, {.class_ = "flex items-center gap-2", .disabled = true}) {
        icon::icon(os, {
            .class_ = "animate-spin",
            .glyph = glyph::loader_circle
        });
        os << "Please wait";
    }
}
