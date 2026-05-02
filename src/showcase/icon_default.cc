#include "htpp.ico.hh"
#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(icon_default) {
    icon::icon(os, {.glyph = glyph::user});
}
