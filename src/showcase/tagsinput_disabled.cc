#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(tagsinput_disabled) {
    HT_DIV(class_ = "w-full max-w-sm") {
        tagsinput::tagsinput(os, {.value = {"127.0.0.1/32"}, .placeholder = "Enter a network", .disabled = true});
    }
}
