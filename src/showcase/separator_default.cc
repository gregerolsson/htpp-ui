#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(separator_default) {
    HT_DIV(class_ = "flex flex-col gap-4 items-center w-full max-w-md") {
        HT_P() {
            os << "Top";
        }
        separator::separator(os, {});
        HT_P() {
            os << "Bottom";
        }
    }
}
