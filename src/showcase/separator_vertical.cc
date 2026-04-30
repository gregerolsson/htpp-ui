#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(separator_vertical) {
    HT_DIV(class_ = "w-full max-w-md") {
        HT_DIV(class_ = "flex h-24 items-center") {
            HT_DIV(class_ = "w-1/2 text-center") {
                os << "Left";
            }
            separator::separator(os, {.class_ = "mx-4", .orientation = separator::vertical});
            HT_DIV(class_ = "w-1/2 text-center") {
                os << "Right";
            }
        }
    }
}
