#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(slider_value) {
    HT_DIV(class_ = "w-full max-w-sm") {
        HT_DIV(class_ = "flex justify-end mb-1") {
            slider::value(os, {.for_ = "slider-value"});
        }
        slider::slider(os, {.id = "slider-value", .value = 75});
    }
}
