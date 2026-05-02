#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace sheet {
    std::string side_classes(side s) {
        std::string base =
            "fixed z-50 flex flex-col bg-background shadow-lg !transition-transform ease-in-out "
            "data-[tui-dialog-open=false]:duration-300 data-[tui-dialog-open=true]:duration-500 ";

        switch (s) {
            case side::right:
                return base +
                    "!top-0 !bottom-0 !right-0 !left-auto "
                    "!h-dvh !max-h-dvh w-3/4 sm:!max-w-sm "
                    "border-l border-t-0 border-r-0 border-b-0 "
                    "!translate-x-0 !translate-y-0 "
                    "data-[tui-dialog-open=false]:!translate-x-full "
                    "data-[tui-dialog-open=true]:!translate-x-0";
            case side::left:
                return base +
                    "!top-0 !bottom-0 !left-0 !right-auto "
                    "!h-dvh !max-h-dvh w-3/4 sm:!max-w-sm "
                    "border-r border-t-0 border-l-0 border-b-0 "
                    "!translate-x-0 !translate-y-0 "
                    "data-[tui-dialog-open=false]:!-translate-x-full "
                    "data-[tui-dialog-open=true]:!translate-x-0";
            case side::top:
                return base +
                    "!inset-x-0 !top-0 !bottom-auto !left-0 !right-0 "
                    "!w-full !max-w-full h-auto "
                    "border-b border-t-0 border-l-0 border-r-0 "
                    "!translate-x-0 !translate-y-0 "
                    "data-[tui-dialog-open=false]:!-translate-y-full "
                    "data-[tui-dialog-open=true]:!translate-y-0";
            case side::bottom:
                return base +
                    "!inset-x-0 !bottom-0 !top-auto !left-0 !right-0 "
                    "!w-full !max-w-full h-auto "
                    "border-t border-b-0 border-l-0 border-r-0 "
                    "!translate-x-0 !translate-y-0 "
                    "data-[tui-dialog-open=false]:!translate-y-full "
                    "data-[tui-dialog-open=true]:!translate-y-0";
            default:
                return base +
                    "!top-0 !bottom-0 !right-0 !left-auto "
                    "!h-dvh !max-h-dvh w-3/4 sm:!max-w-sm "
                    "border-l border-t-0 border-r-0 border-b-0 "
                    "!translate-x-0 !translate-y-0 "
                    "data-[tui-dialog-open=false]:!translate-x-full "
                    "data-[tui-dialog-open=true]:!translate-x-0";
        }
    }

    HT_COMPONENT(script) {
    }

    HT_COMPONENT(sheet, const sheet::props &props) {
        auto s = (props.side == side::right || props.side == side::left ||
                  props.side == side::top   || props.side == side::bottom)
                 ? props.side : side::right;

        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            "data-tui-dialog"_a = "",
            "data-tui-sheet"_a = "true",
            "data-tui-sheet-side"_a = (s == side::top ? "top" :
                                        s == side::bottom ? "bottom" :
                                        s == side::left ? "left" : "right"),
            attr_if(props.disable_click_away, "data-tui-dialog-disable-click-away"_a = "true"),
            attr_if(props.disable_esc, "data-tui-dialog-disable-esc"_a = "true"),
            "data-tui-dialog-open"_a = (props.open ? "true" : "false"),
            class_ = ui::merge("contents", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(trigger, const trigger_props &props) {
        HT_USE(dialog::trigger, {
            .id     = props.id,
            .for_   = props.for_,
            .class_ = props.class_,
        }) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(content, const content_props &props) {
        auto s = (props.side == side::right || props.side == side::left ||
                  props.side == side::top   || props.side == side::bottom)
                 ? props.side : side::right;
        auto content_cls = ui::merge(side_classes(s), "!scale-100 !rounded-none !opacity-100", props.class_);

        HT_TAG("dialog",
            class_ = content_cls,
            "data-tui-dialog-content"_a = "",
            "data-tui-sheet-content"_a = "true",
            "data-tui-sheet-side"_a = (s == side::top ? "top" :
                                        s == side::bottom ? "bottom" :
                                        s == side::left ? "left" : "right"),
            "data-tui-dialog-show-modal"_a = "true"
        ) {
            HT_DIV(class_ = "relative grid gap-4 p-6", "data-tui-dialog-panel"_a = "") {
                HT_SLOT();
                if (!props.hide_close_button) {
                    HT_BUTTON(
                        class_ = "absolute top-4 right-4 rounded-xs opacity-70 transition-opacity hover:opacity-100 "
                                 "focus:outline-none focus:ring-2 focus:ring-ring focus:ring-offset-2 "
                                 "ring-offset-background disabled:pointer-events-none "
                                 "[&_svg]:pointer-events-none [&_svg]:shrink-0",
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

    HT_COMPONENT(header, const header_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("gap-1.5 p-4 text-left flex flex-col gap-2", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(title, const title_props &props) {
        HT_H2(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("text-base leading-normal font-semibold", props.class_)
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

    HT_COMPONENT(footer, const footer_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("mt-auto flex flex-col gap-2 p-4", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(close, const close_props &props) {
        HT_USE(dialog::close, {
            .id     = props.id,
            .for_   = props.for_,
            .class_ = props.class_,
        }) {
            HT_SLOT();
        }
    }
}
