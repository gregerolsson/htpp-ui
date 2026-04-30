#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(progress_sizes) {
    HT_DIV(class_ = "space-y-6 w-full max-w-sm") {
        progress::progress(os, {.value = 50, .size = progress::sm});
        progress::progress(os, {.value = 65, .size = progress::lg});
        progress::progress(os, {.value = 80, .size = progress::lg});
    }
}
