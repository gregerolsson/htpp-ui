#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(skeleton_default) {
    HT_DIV(class_ = "space-y-2 w-full max-w-sm") {
        skeleton::skeleton(os, {.class_ = "h-4 w-full"});
        skeleton::skeleton(os, {.class_ = "h-4 w-2/3"});
        skeleton::skeleton(os, {.class_ = "h-4 w-1/3"});
    }
}
