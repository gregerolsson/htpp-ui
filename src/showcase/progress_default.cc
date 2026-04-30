#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(progress_default) {
    HT_DIV(class_ = "w-full max-w-sm") {
        progress::progress(os, {.value = 25});
    }
}
