#include "htpp.ico.hh"
#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(icon_filled) {
    icon::icon(os, {.glyph = glyph::triangle});
}
