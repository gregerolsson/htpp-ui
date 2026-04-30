#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(rating_max_values) {
    HT_USE(rating::rating, {.value = 7}) {
        HT_USE(rating::group, {}) {
            for (int i = 1; i <= 10; i++) {
                rating::item(os, {.class_ = "scale-75", .value = i, .style = rating::star});
            }
        }
    }
}
