#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(slider_external_value) {
    HT_DIV(class_ = "space-y-6 w-full max-w-sm") {
        slider::slider(os, {.id = "slider-external-value", .value = 50});
        HT_DIV(class_ = "bg-muted p-4 rounded-md") {
            HT_P(class_ = "text-sm text-muted-foreground mb-2") {
                os << "External value (linked to the slider):";
            }
            HT_DIV(class_ = "text-3xl font-bold flex gap-1") {
                slider::value(os, {.class_ = "text-3xl font-bold text-primary", .for_ = "slider-external-value"});
                os << "%";
            }
        }
    }
}
