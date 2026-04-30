#include "htpp.hh"
#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace dialog {
    HT_COMPONENT(script) {
    }

    HT_COMPONENT(dialog, const dialog::props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            "data-tui-dialog"_a = "",
            attr_if(props.disable_click_away, "data-tui-dialog-disable-click-away"_a = "true"),
            attr_if(props.disable_esc, "data-tui-dialog-disable-esc"_a = "true"),
            "data-tui-dialog-open"_a = (props.open ? "true" : "false"),
            class_ = ui::merge("contents", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(trigger, const trigger_props &props) {
        HT_TAG("span",
            attr_if(!props.id.empty(), id = props.id),
            "data-tui-dialog-trigger"_a = "",
            attr_if(!props.for_.empty(), "data-tui-dialog-target"_a = props.for_),
            "data-tui-dialog-trigger-open"_a = "false",
            class_ = ui::merge("contents", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(content, const content_props &props) {
        HT_TAG("dialog",
            class_ = ui::merge(
                "fixed left-[50%] top-[50%] z-50 m-0 w-full max-w-[calc(100%-2rem)] "
                "-translate-x-1/2 -translate-y-1/2 overflow-hidden border bg-background text-foreground p-0 shadow-lg outline-none sm:max-w-lg "
                "[&:not([open]):not([data-tui-dialog-closing=true])]:hidden "
                "rounded-lg "
                "[&::backdrop]:transition-all [&::backdrop]:duration-200 "
                "data-[tui-dialog-open=false]:[&::backdrop]:bg-black/0 "
                "data-[tui-dialog-open=true]:[&::backdrop]:bg-black/50 "
                "transition-all duration-200 "
                "data-[tui-dialog-open=false]:scale-95 "
                "data-[tui-dialog-open=true]:scale-100 "
                "data-[tui-dialog-open=false]:opacity-0 "
                "data-[tui-dialog-open=true]:opacity-100",
                props.class_
            ),
            "data-tui-dialog-content"_a = "",
            "data-tui-dialog-show-modal"_a = (props.disable_modal ? "false" : "true")
        ) {
            HT_DIV(class_ = "relative grid gap-4 p-6", "data-tui-dialog-panel"_a = "") {
                HT_SLOT();
                if (!props.hide_close_button) {
                    HT_BUTTON(
                        class_ = "absolute top-4 right-4 rounded-xs opacity-70 transition-opacity hover:opacity-100 "
                                 "focus:outline-none focus:ring-2 focus:ring-ring focus:ring-offset-2 "
                                 "ring-offset-background disabled:pointer-events-none "
                                 "[&_svg]:pointer-events-none [&_svg]:shrink-0 [&_svg:not([class*='size-'])]:size-4",
                        "data-tui-dialog-close"_a = "",
                        aria_label = "Close",
                        type = "button"
                    ) {
                        HT_TAG("span", class_ = "sr-only") { HT_TEXT("Close"); }
                    }
                }
            }
        }
    }

    HT_COMPONENT(close, const close_props &props) {
        HT_TAG("span",
            attr_if(!props.id.empty(), id = props.id),
            "data-tui-dialog-close"_a = "",
            attr_if(!props.for_.empty(), "data-tui-dialog-target"_a = props.for_),
            class_ = ui::merge("contents cursor-pointer", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(header, const header_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("flex flex-col gap-2 text-center sm:text-left", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(footer, const footer_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("flex flex-col-reverse gap-2 sm:flex-row sm:justify-end", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(title, const title_props &props) {
        HT_H2(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("text-lg leading-none font-semibold", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(description, const description_props &props) {
        HT_P(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("text-muted-foreground text-sm", props.class_)
        ) {
            HT_SLOT();
        }
    }
}
