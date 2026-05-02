#include "htpp.ico.hh"
#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(avatar_with_icon) {
    HT_USE(avatar::avatar, {}) {
        HT_USE(avatar::fallback, {}) {
            icon::icon(os, {.glyph = glyph::camera});
        }
    }
}
