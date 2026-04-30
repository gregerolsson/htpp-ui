#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(textarea_auto_resize) {
    HT_DIV(class_ = "w-full max-w-md") {
        textarea::textarea(os, {.placeholder = "Start typing to see the magic...", .auto_resize = true});
    }
}
