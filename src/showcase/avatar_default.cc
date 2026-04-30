#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(avatar_default) {
    HT_USE(avatar::avatar, {}) {
        avatar::image(os, {.alt = "User avatar", .src = "https://avatars.githubusercontent.com/u/26936893?v=4"});
    }
}
