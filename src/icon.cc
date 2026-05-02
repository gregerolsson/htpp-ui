#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace icon {

    auto opening_tag = R"(
        <svg
            width="24"
            height="24"
            viewBox="0 0 24 24"
            fill="none"
            stroke="currentColor"
            stroke-width="1.75"
            stroke-linecap="round"
            stroke-linejoin="round"
    )";

    HT_COMPONENT(icon, const props &props) {
        os  << opening_tag
            << attr_if(!props.class_.empty(), class_ = props.class_) << "\">"
            << props.glyph
            << "</svg>";
    }
}
