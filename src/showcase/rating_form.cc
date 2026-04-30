#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(rating_form) {
    HT_FORM(class_ = "max-w-sm mx-auto") {
        HT_USE(form::item, {}) {
            HT_USE(form::label, {.for_ = "product_quality"}) {
                os << "Product Quality";
            }
            HT_USE(rating::rating, {.value = 3, .read_only = false, .precision = 1.0, .name = "product_quality"}) {
                HT_USE(rating::group, {}) {
                    for (int i = 1; i <= 5; i++) {
                        rating::item(os, {.value = i, .style = rating::star});
                    }
                }
            }
            HT_USE(form::description, {}) {
                os << "Rate the quality of the product you received.";
            }
            HT_USE(form::message, {.variant = form::error}) {
                os << "Please rate the product quality.";
            }
        }
    }
}
