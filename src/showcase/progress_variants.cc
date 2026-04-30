#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(progress_variants) {
    HT_DIV(class_ = "space-y-6 w-full max-w-xs") {
        progress::progress(os, {.value = 50, .variant = progress::success});
        progress::progress(os, {.value = 75, .variant = progress::danger});
        progress::progress(os, {.value = 90, .variant = progress::warning});
    }
}
