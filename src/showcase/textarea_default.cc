#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(textarea_default) {
    HT_DIV(class_ = "w-full max-w-md") {
        textarea::textarea(os, {.placeholder = "Type your message here..."});
    }
}
