#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(date_picker_formats) {
    HT_DIV(class_ = "w-full max-w-sm flex flex-col gap-4") {
        HT_DIV(class_ = "space-y-2") {
            HT_USE(label::label, {.for_ = "dp-default"}) {
                os << "Default (Medium, en-US)";
            }
            datepicker::datepicker(os, {.id = "dp-default"});
        }
        HT_DIV(class_ = "space-y-2") {
            HT_USE(label::label, {.for_ = "dp-de-short"}) {
                os << "Short Format (German)";
            }
            datepicker::datepicker(os, {.id = "dp-de-short", .format = datepicker::locale_short, .locale = datepicker::german});
        }
        HT_DIV(class_ = "space-y-2") {
            HT_USE(label::label, {.for_ = "dp-es-long"}) {
                os << "Long Format (Spanish)";
            }
            datepicker::datepicker(os, {.id = "dp-es-long", .format = datepicker::locale_long, .locale = datepicker::spanish, .placeholder = "Seleccionar fecha"});
        }
        HT_DIV(class_ = "space-y-2") {
            HT_USE(label::label, {.for_ = "dp-fr-full"}) {
                os << "Full Format (French)";
            }
            datepicker::datepicker(os, {.id = "dp-fr-full", .format = datepicker::locale_full, .locale = datepicker::french});
        }
        HT_DIV(class_ = "space-y-2") {
            HT_USE(label::label, {.for_ = "dp-ja-medium"}) {
                os << "Medium Format (Japanese)";
            }
            datepicker::datepicker(os, {.id = "dp-ja-medium", .format = datepicker::locale_medium, .locale = datepicker::japanese});
        }
        HT_DIV(class_ = "space-y-2") {
            HT_USE(label::label, {.for_ = "dp-ar-short"}) {
                os << "Short Format (Arabic - ar-SA)";
            }
            datepicker::datepicker(os, {.id = "dp-ar-short", .format = datepicker::locale_short, .locale = datepicker::locale_default});
        }
    }
}
