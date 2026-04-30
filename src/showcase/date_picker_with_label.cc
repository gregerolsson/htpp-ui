#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(date_picker_with_label) {
    HT_DIV(class_ = "w-full max-w-sm space-y-2") {
        datepicker::datepicker(os, {.id = "xxxx"});
    }
}
