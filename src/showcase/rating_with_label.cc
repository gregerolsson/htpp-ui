#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(rating_with_label) {
    HT_DIV(class_ = "items-center") {
        HT_DIV(class_ = "flex flex-col gap-2") {
            HT_USE(label::label, {.for_ = "rating-with-label"}) {
                os << "Fruit";
            }
            HT_USE(rating::rating, {.value = 2}) {
                HT_USE(rating::group, {}) {
                    for (int i = 1; i <= 5; i++) {
                        rating::item(os, {.value = i, .style = rating::star});
                    }
                }
            }
        }
    }
}
