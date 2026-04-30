#include "htpp.hh"
#include "htpp.ui.hh"

#include <string>

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace toast {
    constexpr std::string_view variant_str(variant v) {
        switch (v) {
            case variant::success: return "success";
            case variant::error:   return "error";
            case variant::warning: return "warning";
            case variant::info:    return "info";
            case variant::normal:
            default:               return "default";
        }
    }

    constexpr std::string_view position_str(position p) {
        switch (p) {
            case position::top_right:     return "top-right";
            case position::top_left:      return "top-left";
            case position::top_center:    return "top-center";
            case position::bottom_right:  return "bottom-right";
            case position::bottom_left:   return "bottom-left";
            case position::bottom_center: return "bottom-center";
            default:                      return "bottom-right";
        }
    }

    HT_COMPONENT(script) {
    }

    HT_COMPONENT(toast, const toast::props &props) {
        int  actual_duration = (props.duration == 0) ? 3000 : props.duration;
        auto dur_str         = std::to_string(actual_duration);
        auto var_s           = variant_str(props.variant);
        auto pos_s           = position_str(props.position);

        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            "data-tui-toast"_a = "",
            "data-tui-toast-duration"_a = dur_str,
            "data-position"_a = pos_s,
            "data-variant"_a = var_s,
            class_ = ui::merge(
                "z-50 fixed pointer-events-auto p-4 w-full md:max-w-[420px] "
                "animate-in fade-in slide-in-from-bottom-4 duration-300 "
                "data-[position=top-right]:top-0 data-[position=top-right]:right-0 "
                "data-[position=top-left]:top-0 data-[position=top-left]:left-0 "
                "data-[position=top-center]:top-0 data-[position=top-center]:left-1/2 data-[position=top-center]:-translate-x-1/2 "
                "data-[position=bottom-right]:bottom-0 data-[position=bottom-right]:right-0 "
                "data-[position=bottom-left]:bottom-0 data-[position=bottom-left]:left-0 "
                "data-[position=bottom-center]:bottom-0 data-[position=bottom-center]:left-1/2 data-[position=bottom-center]:-translate-x-1/2 "
                "data-[position*=top]:slide-in-from-top-4 "
                "data-[position*=bottom]:slide-in-from-bottom-4",
                props.class_
            )
        ) {
            HT_DIV(class_ = "w-full bg-popover text-popover-foreground rounded-lg shadow-xs border pt-5 pb-4 px-4 flex items-center justify-center relative overflow-hidden group") {
                if (props.show_indicator && actual_duration > 0) {
                    HT_DIV(class_ = "absolute top-0 left-0 right-0 h-1 overflow-hidden") {
                        HT_DIV(
                            class_ = "toast-progress h-full origin-left transition-transform ease-linear "
                                     "data-[variant=default]:bg-gray-500 "
                                     "data-[variant=success]:bg-green-500 "
                                     "data-[variant=error]:bg-red-500 "
                                     "data-[variant=warning]:bg-yellow-500 "
                                     "data-[variant=info]:bg-blue-500",
                            "data-variant"_a = var_s,
                            "data-duration"_a = dur_str
                        ) {
                        }
                    }
                }
                HT_TAG("span", class_ = "flex-1 min-w-0") {
                    if (!props.title.empty()) {
                        HT_P(class_ = "text-sm font-semibold truncate") { HT_TEXT(props.title); }
                    }
                    if (!props.description.empty()) {
                        HT_P(class_ = "text-sm opacity-90 mt-1") { HT_TEXT(props.description); }
                    }
                }
                if (props.dismissible) {
                    HT_BUTTON(
                        class_ = "size-9 inline-flex items-center justify-center gap-2 whitespace-nowrap rounded-md text-sm "
                                 "hover:bg-accent hover:text-accent-foreground",
                        aria_label = "Close",
                        "data-tui-toast-dismiss"_a = "",
                        type = "button"
                    ) {
                    }
                }
            }
        }
    }
}
