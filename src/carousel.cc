#include "htpp.ui.hh"

#include <string>

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace carousel {
    HT_COMPONENT(script) {
    }

    HT_COMPONENT(carousel, const carousel::props &props) {
        auto autoplay_str = props.autoplay ? "true" : "false";
        auto loop_str     = props.loop ? "true" : "false";
        int  interval     = (props.interval == 0) ? 5000 : props.interval;
        auto interval_str = std::to_string(interval);

        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("relative overflow-hidden w-full", props.class_),
            "data-tui-carousel"_a = "",
            "data-tui-carousel-current"_a = "0",
            "data-tui-carousel-autoplay"_a = autoplay_str,
            "data-tui-carousel-interval"_a = interval_str,
            "data-tui-carousel-loop"_a = loop_str
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(content, const content_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(
                "flex h-full w-full transition-transform duration-500 ease-in-out cursor-grab",
                props.class_
            ),
            "data-tui-carousel-track"_a = ""
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(item, const item_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("flex-shrink-0 w-full h-full relative", props.class_),
            "data-tui-carousel-item"_a = ""
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(previous, const previous_props &props) {
        HT_BUTTON(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(
                "absolute left-2 top-1/2 transform -translate-y-1/2 p-2 rounded-full "
                "bg-black/20 text-white hover:bg-black/40 focus:outline-none",
                props.class_
            ),
            "data-tui-carousel-prev"_a = "",
            aria_label = "Previous slide",
            type = "button"
        ) {
        }
    }

    HT_COMPONENT(next, const next_props &props) {
        HT_BUTTON(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(
                "absolute right-2 top-1/2 transform -translate-y-1/2 p-2 rounded-full "
                "bg-black/20 text-white hover:bg-black/40 focus:outline-none",
                props.class_
            ),
            "data-tui-carousel-next"_a = "",
            aria_label = "Next slide",
            type = "button"
        ) {
        }
    }

    HT_COMPONENT(indicators, const indicators_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(
                "absolute bottom-4 left-1/2 transform -translate-x-1/2 flex gap-2",
                props.class_
            )
        ) {
            for (int i = 0; i < props.count; ++i) {
                auto idx_str    = std::to_string(i);
                auto active_str = (i == 0) ? "true" : "false";
                auto cls = (i == 0)
                    ? "w-3 h-3 rounded-full bg-primary hover:bg-foreground/50 focus:outline-none transition-colors"
                    : "w-3 h-3 rounded-full bg-foreground/30 hover:bg-foreground/50 focus:outline-none transition-colors";
                HT_BUTTON(
                    class_ = cls,
                    "data-tui-carousel-indicator"_a = idx_str,
                    "data-tui-carousel-active"_a = active_str,
                    type = "button"
                ) {
                }
            }
        }
    }
}
