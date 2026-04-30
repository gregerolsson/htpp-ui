#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(avatar_sizes) {
    HT_DIV(class_ = "flex flex-wrap items-center gap-4") {
        HT_USE(avatar::avatar, {.class_ = "size-6"}) {
            avatar::image(os, {.alt = "Small avatar", .src = "https://avatars.githubusercontent.com/u/26936893?v=4"});
            HT_USE(avatar::fallback, {}) {
                os << "SM";
            }
        }
        HT_USE(avatar::avatar, {}) {
            avatar::image(os, {.alt = "Default avatar", .src = "https://avatars.githubusercontent.com/u/26936893?v=4"});
            HT_USE(avatar::fallback, {}) {
                os << "MD";
            }
        }
        HT_USE(avatar::avatar, {.class_ = "size-12"}) {
            avatar::image(os, {.alt = "Large avatar", .src = "https://avatars.githubusercontent.com/u/26936893?v=4"});
            HT_USE(avatar::fallback, {}) {
                os << "LG";
            }
        }
        HT_USE(avatar::avatar, {.class_ = "size-16"}) {
            avatar::image(os, {.alt = "Extra large avatar", .src = "https://avatars.githubusercontent.com/u/26936893?v=4"});
            HT_USE(avatar::fallback, {}) {
                os << "XL";
            }
        }
    }
}
