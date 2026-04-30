#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(tagsinput_with_label) {
    HT_DIV(class_ = "w-full max-w-sm grid gap-2") {
        HT_USE(label::label, {.for_ = "nets"}) {
            os << "Nets";
        }
        tagsinput::tagsinput(os, {.id = "nets", .value = {"127.0.0.1/32"}, .placeholder = "Enter a network"});
    }
}
