#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(slider_steps) {
    HT_DIV(class_ = "w-full max-w-sm") {
        HT_DIV(class_ = "flex justify-between items-center mb-1") {
            HT_USE(label::label, {}) {
                os << "Zoom Level";
            }
            slider::value(os, {.for_ = "slider-steps"});
        }
        slider::slider(os, {.id = "slider-steps", .name = "slider-steps", .min = 0, .max = 200, .step = 25, .value = 100});
    }
}
