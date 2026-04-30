#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(copybutton_with_input) {
    HT_DIV(class_ = "flex items-center gap-2") {
        input::input(os, {.id = "api-key-input", .class_ = "max-w-xs", .value = "abc123_example_key_xyz789", .readonly = true});
        copybutton::copybutton(os, {.target_id = "api-key-input"});
    }
}
