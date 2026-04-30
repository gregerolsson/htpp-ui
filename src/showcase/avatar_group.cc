#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(avatar_group) {
    HT_DIV(class_ = "flex -space-x-3 *:ring-2 *:ring-background") {
        HT_USE(avatar::avatar, {}) {
            avatar::image(os, {.alt = "User avatar", .src = "https://avatars.githubusercontent.com/u/26936893?v=4"});
            HT_USE(avatar::fallback, {}) {
                os << "AA";
            }
        }
        HT_USE(avatar::avatar, {}) {
            avatar::image(os, {.alt = "User avatar", .src = "https://avatars.githubusercontent.com/u/26936893?v=4"});
            HT_USE(avatar::fallback, {}) {
                os << "BB";
            }
        }
        HT_USE(avatar::avatar, {}) {
            avatar::image(os, {.alt = "User avatar", .src = "https://avatars.githubusercontent.com/u/26936893?v=4"});
            HT_USE(avatar::fallback, {}) {
                os << "CC";
            }
        }
        HT_USE(avatar::avatar, {.class_ = "text-muted-foreground"}) {
            HT_USE(avatar::fallback, {}) {
                os << "+2";
            }
        }
    }
}
