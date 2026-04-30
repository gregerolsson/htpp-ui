#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(copybutton_default) {
    HT_DIV(class_ = "flex items-center gap-4") {
        HT_DIV(id = "copy-text-default", class_ = "text-sm text-muted-foreground") {
            os << "Hello, World!";
        }
        copybutton::copybutton(os, {.target_id = "copy-text-default"});
    }
}
