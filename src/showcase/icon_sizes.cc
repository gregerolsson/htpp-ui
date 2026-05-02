#include "htpp.ico.hh"
#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(icon_sizes) {
    HT_DIV(class_ = "flex flex-wrap gap-2") {
        icon::icon(os, {.class_ = "size-3.5", .glyph = glyph::house});
        icon::icon(os, {.class_ = "size-4", .glyph = glyph::house});
        icon::icon(os, {.class_ = "size-6", .glyph = glyph::house});
    }
}
