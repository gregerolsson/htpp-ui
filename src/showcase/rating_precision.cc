#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(rating_precision) {
    HT_USE(rating::rating, {.value = 1.3, .read_only = true, .precision = 0.5}) {
        HT_USE(rating::group, {}) {
            for (int i = 1; i <= 5; i++) {
                rating::item(os, {.value = i, .style = rating::star});
            }
        }
    }
}
