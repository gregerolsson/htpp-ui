#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace tabs {
    HT_COMPONENT(script) {
    }

    HT_COMPONENT(tabs, const tabs::props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("flex flex-col gap-2", props.class_),
            "data-tui-tabs"_a = "",
            "data-tui-tabs-id"_a = props.id
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(list, const list_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(
                "bg-muted text-muted-foreground inline-flex h-9 w-fit items-center justify-center rounded-lg p-[3px]",
                props.class_
            ),
            "data-tui-tabs-list"_a = ""
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(trigger, const trigger_props &props) {
        HT_BUTTON(
            attr_if(!props.id.empty(), id = props.id),
            type = "button",
            class_ = ui::merge(
                "data-[tui-tabs-state=active]:bg-background dark:data-[tui-tabs-state=active]:text-foreground "
                "focus-visible:border-ring focus-visible:ring-ring/50 focus-visible:outline-ring "
                "dark:data-[tui-tabs-state=active]:border-input dark:data-[tui-tabs-state=active]:bg-input/30 "
                "text-foreground dark:text-muted-foreground "
                "inline-flex h-[calc(100%-1px)] flex-1 items-center justify-center gap-1.5 rounded-md border border-transparent "
                "px-2 py-1 text-sm font-medium whitespace-nowrap transition-[color,box-shadow] "
                "focus-visible:ring-[3px] focus-visible:outline-1 "
                "disabled:pointer-events-none disabled:opacity-50 "
                "data-[tui-tabs-state=active]:shadow-sm "
                "[&_svg]:pointer-events-none [&_svg]:shrink-0 [&_svg:not([class*='size-'])]:size-4",
                props.class_
            ),
            "data-tui-tabs-trigger"_a = "",
            "data-tui-tabs-id"_a = props.tabs_id,
            "data-tui-tabs-value"_a = props.value,
            "data-tui-tabs-state"_a = (props.is_active ? "active" : "inactive")
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(content, const content_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(
                "flex-1 outline-none",
                props.is_active ? "" : "hidden",
                props.class_
            ),
            "data-tui-tabs-content"_a = "",
            "data-tui-tabs-id"_a = props.tabs_id,
            "data-tui-tabs-value"_a = props.value,
            "data-tui-tabs-state"_a = (props.is_active ? "active" : "inactive")
        ) {
            HT_SLOT();
        }
    }
}
