#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(separator_decorated) {
    HT_DIV(class_ = "flex flex-col gap-16 w-full max-w-md") {
        HT_USE(separator::separator, {.decoration = separator::dashed}) {
            os << "DASHED";
        }
        HT_USE(separator::separator, {.decoration = separator::dotted}) {
            os << "DOTTED";
        }
    }
}
