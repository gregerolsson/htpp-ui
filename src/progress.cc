#include "htpp.hh"
#include "htpp.ui.hh"

#include <string>

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace progress {
    constexpr std::string_view size_classes(size s) {
        switch (s) {
            case size::sm: return "h-1";
            case size::lg: return "h-4";
            default:       return "h-2.5";
        }
    }

    constexpr std::string_view variant_classes(variant v) {
        switch (v) {
            case variant::success: return "bg-green-500";
            case variant::danger:  return "bg-destructive";
            case variant::warning: return "bg-yellow-500";
            case variant::normal:
            default:               return "bg-primary";
        }
    }

    HT_COMPONENT(script) {
    }

    HT_COMPONENT(progress, const progress::props &props) {
        int max_val = (props.max <= 0) ? 100 : props.max;
        auto max_str = std::to_string(max_val);
        auto val_str = std::to_string(props.value);

        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("w-full", props.class_),
            "aria-valuemin"_a = "0",
            "aria-valuemax"_a = max_str,
            "aria-valuenow"_a = val_str,
            role = "progressbar"
        ) {
            if (!props.label.empty() || props.show_value) {
                HT_DIV(class_ = "flex justify-between items-center mb-1") {
                    if (!props.label.empty()) {
                        HT_TAG("span", class_ = "text-sm font-medium") { HT_TEXT(props.label); }
                    }
                    if (props.show_value) {
                        int pct = max_val > 0 ? (props.value * 100) / max_val : 0;
                        auto pct_str = std::to_string(pct) + "%";
                        HT_TAG("span", class_ = "text-sm font-medium") { HT_TEXT(pct_str); }
                    }
                }
            }
            HT_DIV(class_ = "w-full overflow-hidden rounded-full bg-secondary") {
                HT_DIV(
                    "data-tui-progress-indicator"_a = "",
                    class_ = ui::merge(
                        "h-full rounded-full transition-all",
                        size_classes(props.size),
                        variant_classes(props.variant),
                        props.bar_class
                    )
                ) {
                }
            }
        }
    }
}
