#include "htpp.ui.hh"

#include <string>
#include <sstream>
#include <iomanip>

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace slider {
    static std::string pct_str(int value, int min, int max) {
        if (max == min) { return "0.00"; }
        double pct = static_cast<double>(value - min) / static_cast<double>(max - min) * 100.0;
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << pct;
        return oss.str();
    }

    static std::string right_pct_str(int value, int min, int max) {
        if (max == min) { return "100.00"; }
        double pct = 100.0 - static_cast<double>(value - min) / static_cast<double>(max - min) * 100.0;
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << pct;
        return oss.str();
    }

    HT_COMPONENT(script) {
    }

    HT_COMPONENT(slider, const slider::props &props) {
        int actual_max  = (props.max == 0) ? 100 : props.max;
        int actual_step = (props.step == 0) ? 1   : props.step;
        auto min_str   = std::to_string(props.min);
        auto max_str   = std::to_string(actual_max);
        auto step_str  = std::to_string(actual_step);
        auto val_str   = std::to_string(props.value);
        auto left_s    = pct_str(props.value, props.min, actual_max) + "%";
        auto right_s   = right_pct_str(props.value, props.min, actual_max) + "%";
        auto fill_style = "left:0%;right:" + right_s;
        auto thumb_style = "left:" + left_s;
        auto tabidx    = props.disabled ? "-1" : "0";
        auto thumb_cls = ui::merge(
            "absolute top-1/2 size-4 -translate-x-1/2 -translate-y-1/2 rounded-full bg-primary touch-none "
            "ring-offset-background focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring focus-visible:ring-offset-2 "
            "hover:bg-primary/90",
            props.disabled ? "opacity-50 cursor-not-allowed" : "cursor-grab active:cursor-grabbing"
        );

        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            "data-tui-slider"_a = "",
            "data-min"_a = min_str,
            "data-max"_a = max_str,
            "data-step"_a = step_str,
            class_ = ui::merge("relative flex items-center w-full select-none", props.class_)
        ) {
            HT_DIV("data-track"_a = "", class_ = "relative w-full h-2 rounded-full bg-secondary") {
                HT_DIV(
                    "data-fill"_a = "",
                    class_ = "absolute inset-y-0 rounded-full bg-primary pointer-events-none",
                    style = fill_style
                ) {
                }
                HT_DIV(
                    "data-thumb"_a = "",
                    role = "slider",
                    tabindex = tabidx,
                    "aria-valuemin"_a = min_str,
                    "aria-valuemax"_a = max_str,
                    "aria-valuenow"_a = val_str,
                    attr_if(props.disabled, "aria-disabled"_a = "true"),
                    style = thumb_style,
                    class_ = thumb_cls
                ) {
                }
            }
            HT_INPUT(
                "data-input"_a = "",
                type = "hidden",
                attr_if(!props.name.empty(), name = props.name),
                htpp::attr::value = val_str
            );
        }
    }

    HT_COMPONENT(range, const range_props &props) {
        int actual_max      = (props.max == 0) ? 100 : props.max;
        int actual_step     = (props.step == 0) ? 1   : props.step;
        int actual_max_val  = (props.max_value == 0) ? actual_max : props.max_value;
        auto min_str        = std::to_string(props.min);
        auto max_str        = std::to_string(actual_max);
        auto step_str       = std::to_string(actual_step);
        auto min_val_str    = std::to_string(props.min_value);
        auto max_val_str    = std::to_string(actual_max_val);
        auto fill_left_s    = pct_str(props.min_value, props.min, actual_max) + "%";
        auto fill_right_s   = right_pct_str(actual_max_val, props.min, actual_max) + "%";
        auto fill_style     = "left:" + fill_left_s + ";right:" + fill_right_s;
        auto min_thumb_style = "left:" + pct_str(props.min_value, props.min, actual_max) + "%";
        auto max_thumb_style = "left:" + pct_str(actual_max_val, props.min, actual_max) + "%";
        auto tabidx         = props.disabled ? "-1" : "0";
        auto thumb_cls      = ui::merge(
            "absolute top-1/2 size-4 -translate-x-1/2 -translate-y-1/2 rounded-full bg-primary touch-none "
            "ring-offset-background focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring focus-visible:ring-offset-2 "
            "hover:bg-primary/90",
            props.disabled ? "opacity-50 cursor-not-allowed" : "cursor-grab active:cursor-grabbing"
        );

        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            "data-tui-slider"_a = "",
            "data-min"_a = min_str,
            "data-max"_a = max_str,
            "data-step"_a = step_str,
            class_ = ui::merge("relative flex items-center w-full select-none", props.class_)
        ) {
            HT_DIV("data-track"_a = "", class_ = "relative w-full h-2 rounded-full bg-secondary") {
                HT_DIV(
                    "data-fill"_a = "",
                    class_ = "absolute inset-y-0 rounded-full bg-primary pointer-events-none",
                    style = fill_style
                ) {
                }
                HT_DIV(
                    "data-thumb"_a = "",
                    role = "slider",
                    tabindex = tabidx,
                    aria_label = "Minimum",
                    "aria-valuemin"_a = min_str,
                    "aria-valuemax"_a = max_str,
                    "aria-valuenow"_a = min_val_str,
                    attr_if(props.disabled, "aria-disabled"_a = "true"),
                    style = min_thumb_style,
                    class_ = thumb_cls
                ) {
                }
                HT_DIV(
                    "data-thumb"_a = "",
                    role = "slider",
                    tabindex = tabidx,
                    aria_label = "Maximum",
                    "aria-valuemin"_a = min_str,
                    "aria-valuemax"_a = max_str,
                    "aria-valuenow"_a = max_val_str,
                    attr_if(props.disabled, "aria-disabled"_a = "true"),
                    style = max_thumb_style,
                    class_ = thumb_cls
                ) {
                }
            }
            HT_INPUT(
                "data-input"_a = "",
                type = "hidden",
                attr_if(!props.name_min.empty(), name = props.name_min),
                htpp::attr::value = min_val_str
            );
            HT_INPUT(
                "data-input"_a = "",
                type = "hidden",
                attr_if(!props.name_max.empty(), name = props.name_max),
                htpp::attr::value = max_val_str
            );
        }
    }

    HT_COMPONENT(value, const value_props &props) {
        HT_TAG("span",
            attr_if(!props.id.empty(), id = props.id),
            "data-tui-slider-value"_a = "",
            "data-tui-slider-value-for"_a = props.for_,
            class_ = ui::merge("text-sm text-muted-foreground", props.class_)
        ) {
        }
    }
}
