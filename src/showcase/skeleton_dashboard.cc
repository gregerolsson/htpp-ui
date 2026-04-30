#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(skeleton_dashboard) {
    HT_DIV() {
        HT_DIV(class_ = "grid gap-6 md:grid-cols-3") {
            HT_DIV(class_ = "p-4") {
                skeleton::skeleton(os, {.class_ = "h-4 w-20 mb-2"});
                skeleton::skeleton(os, {.class_ = "h-8 w-24 mb-4"});
                HT_DIV(class_ = "flex items-center gap-2") {
                    skeleton::skeleton(os, {.class_ = "h-4 w-12"});
                    skeleton::skeleton(os, {.class_ = "h-4 w-4"});
                }
            }
            HT_DIV(class_ = "p-4") {
                skeleton::skeleton(os, {.class_ = "h-4 w-20 mb-2"});
                skeleton::skeleton(os, {.class_ = "h-8 w-24 mb-4"});
                HT_DIV(class_ = "flex items-center gap-2") {
                    skeleton::skeleton(os, {.class_ = "h-4 w-12"});
                    skeleton::skeleton(os, {.class_ = "h-4 w-4"});
                }
            }
            HT_DIV(class_ = "p-4") {
                skeleton::skeleton(os, {.class_ = "h-4 w-20 mb-2"});
                skeleton::skeleton(os, {.class_ = "h-8 w-24 mb-4"});
                HT_DIV(class_ = "flex items-center gap-2") {
                    skeleton::skeleton(os, {.class_ = "h-4 w-12"});
                    skeleton::skeleton(os, {.class_ = "h-4 w-4"});
                }
            }
        }
        HT_DIV(class_ = "mt-4 p-4") {
            skeleton::skeleton(os, {.class_ = "h-5 w-1/3 mb-6"});
            skeleton::skeleton(os, {.class_ = "h-[240px] w-full rounded-md"});
        }
    }
}
