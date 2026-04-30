#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(avatar_fallback) {
    HT_USE(avatar::avatar, {}) {
        avatar::image(os, {.alt = "John Doe avatar", .src = "broken-image.jpg"});
        HT_USE(avatar::fallback, {}) {
            os << "JD";
        }
    }
}
