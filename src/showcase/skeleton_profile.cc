#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(skeleton_profile) {
    HT_DIV(class_ = "flex items-center gap-4 w-full max-w-sm") {
        skeleton::skeleton(os, {.class_ = "h-12 w-12 rounded-full"});
        HT_DIV(class_ = "space-y-2 w-full") {
            skeleton::skeleton(os, {.class_ = "h-4 w-full"});
            skeleton::skeleton(os, {.class_ = "h-4 w-3/4"});
        }
    }
}
