#include "htpp.hh"
#include "htpp.ui.hh"

#include <string>

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace rating {
    constexpr std::string_view color_class(style s) {
        switch (s) {
            case style::heart: return "text-destructive";
            case style::emoji: return "text-yellow-500";
            case style::star:
            default:           return "text-yellow-400";
        }
    }

    HT_COMPONENT(script) {
    }

    HT_COMPONENT(rating, const rating::props &props) {
        auto val_str       = std::to_string(props.value);
        auto precision_str = std::to_string(props.precision);
        auto readonly_str  = props.read_only ? "true" : "false";
        auto integer_str   = props.only_integer ? "true" : "false";

        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            "data-tui-rating-component"_a = "",
            "data-tui-rating-initial-value"_a = val_str,
            "data-tui-rating-precision"_a = precision_str,
            "data-tui-rating-readonly"_a = readonly_str,
            attr_if(!props.name.empty(), "data-tui-rating-name"_a = props.name),
            "data-tui-rating-onlyinteger"_a = integer_str,
            class_ = ui::merge("flex flex-col items-start gap-1", props.class_)
        ) {
            HT_SLOT();
            if (!props.name.empty()) {
                HT_INPUT(
                    type = "hidden",
                    name = props.name,
                    value = val_str,
                    attr_if(!props.form.empty(), "form"_a = props.form),
                    "data-tui-rating-hidden-input"_a = ""
                );
            }
        }
    }

    HT_COMPONENT(group, const group_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("flex flex-row items-center gap-1", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(item, const item_props &props) {
        auto val_str = std::to_string(props.value);
        auto s       = (props.style == style::star) ? style::star : props.style;

        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            "data-tui-rating-item"_a = "",
            "data-tui-rating-value"_a = val_str,
            class_ = ui::merge(
                "relative",
                color_class(s),
                "transition-opacity",
                "cursor-pointer",
                props.class_
            )
        ) {
            HT_DIV(class_ = "opacity-30") {
            }
            HT_DIV(
                class_ = "absolute inset-0 overflow-hidden w-0",
                "data-tui-rating-item-foreground"_a = ""
            ) {
            }
        }
    }
}
