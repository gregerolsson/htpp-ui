#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(separator_label) {
    HT_DIV(class_ = "flex flex-col gap-16 w-full max-w-md items-center") {
        HT_USE(separator::separator, {.class_ = "w-full"}) {
            os << "OR";
        }
        HT_USE(separator::separator, {.class_ = "h-24", .orientation = separator::vertical}) {
            os << "OR";
        }
    }
}
