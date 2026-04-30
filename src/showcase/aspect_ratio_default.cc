#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(aspect_ratio_default) {
    HT_USE(aspectratio::aspectratio, {.class_ = "rounded-md overflow-hidden", .ratio = aspectratio::video}) {
        HT_IMG(src = "/assets/img/aspect_ratio_placeholder.jpeg", alt = "Example image", class_ = "h-full w-full object-cover");
    }
}
