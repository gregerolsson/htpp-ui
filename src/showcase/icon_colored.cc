#include "htpp.ico.hh"
#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(icon_colored) {
    icon::icon(os, {.class_ = "stroke-red-500", .glyph = glyph::heart});
}
