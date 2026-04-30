#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(date_picker_form) {
    HT_DIV(class_ = "w-full max-w-sm") {
        HT_USE(form::item, {}) {
            HT_USE(form::label, {.for_ = "date-picker-form"}) {
                os << "Select a date";
            }
            datepicker::datepicker(os, {.id = "date-picker-form", .has_error = true});
            HT_USE(form::description, {}) {
                os << "Select a date from the calendar.";
            }
            HT_USE(form::message, {.variant = form::error}) {
                os << "Select a valid date";
            }
        }
    }
}
