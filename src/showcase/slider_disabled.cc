#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(slider_disabled) {
    HT_DIV(class_ = "w-full max-w-sm") {
        HT_DIV(class_ = "flex justify-between items-center mb-1") {
            HT_USE(label::label, {}) {
                os << "Volume";
            }
            slider::value(os, {.for_ = "slider-disabled"});
        }
        slider::slider(os, {.id = "slider-disabled", .min = -20, .max = 200, .step = 20, .value = 20, .disabled = true});
    }
}
