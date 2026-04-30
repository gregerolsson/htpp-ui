#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(time_picker_form) {
    HT_DIV(class_ = "w-full max-w-sm") {
        HT_USE(form::item, {}) {
            HT_USE(form::label, {.for_ = "time-picker-form"}) {
                os << "Select a time";
            }
            timepicker::timepicker(os, {.id = "time-picker-form", .name = "time-picker-form", .has_error = true});
            HT_USE(form::description, {}) {
                os << "Select a time from the dropdown.";
            }
            HT_USE(form::message, {.variant = form::error}) {
                os << "Please select a time";
            }
        }
    }
}
