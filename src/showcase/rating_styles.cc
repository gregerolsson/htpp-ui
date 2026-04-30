#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(rating_styles) {
    HT_DIV(class_ = "flex flex-col gap-4") {
        HT_USE(rating::rating, {.value = 2}) {
            HT_USE(rating::group, {}) {
                for (int i = 1; i <= 5; i++) {
                    rating::item(os, {.value = i, .style = rating::star});
                }
            }
        }
        HT_USE(rating::rating, {.value = 3}) {
            HT_USE(rating::group, {}) {
                for (int i = 1; i <= 5; i++) {
                    rating::item(os, {.value = i, .style = rating::heart});
                }
            }
        }
        HT_USE(rating::rating, {.value = 4}) {
            HT_USE(rating::group, {}) {
                for (int i = 1; i <= 5; i++) {
                    rating::item(os, {.value = i, .style = rating::emoji});
                }
            }
        }
    }
}
