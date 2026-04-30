#include "htpp.hh"
#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace separator {
    constexpr std::string_view decoration_classes(decoration d) {
        switch (d) {
            case decoration::dashed: return "border-dashed";
            case decoration::dotted: return "border-dotted";
            default:                 return "";
        }
    }

    HT_COMPONENT(separator, const separator::props &props) {
        if (props.orientation == orientation::horizontal) {
            HT_DIV(
                attr_if(!props.id.empty(), id = props.id),
                role = "separator",
                "aria-orientation"_a = "horizontal",
                class_ = ui::merge("shrink-0 w-full", props.class_)
            ) {
                HT_DIV(class_ = "relative flex items-center w-full") {
                    HT_TAG("span",
                        class_ = ui::merge(
                            "absolute w-full border-t h-[1px]",
                            decoration_classes(props.decoration)
                        ),
                        aria_hidden = "true"
                    ) {
                    }
                    HT_TAG("span", class_ = "relative mx-auto bg-background px-2 text-xs text-muted-foreground") {
                        HT_SLOT();
                    }
                }
            }
        } else {
            HT_DIV(
                attr_if(!props.id.empty(), id = props.id),
                role = "separator",
                "aria-orientation"_a = "vertical",
                class_ = ui::merge("shrink-0 h-full", props.class_)
            ) {
                HT_DIV(class_ = "relative flex flex-col items-center h-full") {
                    HT_TAG("span",
                        class_ = ui::merge(
                            "absolute h-full border-l w-[1px]",
                            decoration_classes(props.decoration)
                        ),
                        aria_hidden = "true"
                    ) {
                    }
                    HT_TAG("span", class_ = "relative my-auto bg-background py-2 text-xs text-muted-foreground") {
                        HT_SLOT();
                    }
                }
            }
        }
    }
}
