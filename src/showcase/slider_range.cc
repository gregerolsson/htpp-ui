#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(slider_range) {
    HT_DIV(class_ = "w-full max-w-sm") {
        HT_DIV(class_ = "flex justify-between mb-1") {
            slider::value(os, {.for_ = "slider-range-min"});
            slider::value(os, {.for_ = "slider-range-max"});
        }
        slider::range(os, {.id = "slider-range", .min_value = 25, .max_value = 75});
    }
}
