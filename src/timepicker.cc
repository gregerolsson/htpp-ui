#include "htpp.hh"
#include "htpp.ui.hh"

#include <string>

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace timepicker {
    HT_COMPONENT(script) {
    }

    HT_COMPONENT(timepicker, const timepicker::props &props) {
        auto placeholder = props.placeholder.empty() ? "Select time" : props.placeholder;
        auto am_label    = props.am_label.empty()    ? "AM"           : props.am_label;
        auto pm_label    = props.pm_label.empty()    ? "PM"           : props.pm_label;
        int  actual_step = (props.step <= 0) ? 1 : props.step;
        auto use12_str   = props.use_12_hours ? "true" : "false";
        auto step_str    = std::to_string(actual_step);

        HT_DIV(
            class_ = "relative inline-block w-full",
            "data-tui-timepicker-root"_a = ""
        ) {
            HT_USE(popover::root, {}) {
                HT_INPUT(
                    type = "hidden",
                    attr_if(!props.name.empty(), name = props.name),
                    attr_if(!props.value.empty(), value = props.value),
                    attr_if(!props.form.empty(), "form"_a = props.form),
                    "data-tui-timepicker-hidden-input"_a = "true"
                );
                HT_USE(popover::trigger, {.trigger_type = popover::trigger_type::click}) {
                    HT_BUTTON(
                        attr_if(!props.id.empty(), id = props.id),
                        class_ = ui::merge(
                            "w-full h-9 px-3 py-1 text-base md:text-sm "
                            "flex items-center justify-between "
                            "rounded-md border border-input bg-transparent shadow-xs transition-[color,box-shadow] outline-none "
                            "dark:bg-input/30 "
                            "selection:bg-primary selection:text-primary-foreground "
                            "focus-visible:border-ring focus-visible:ring-ring/50 focus-visible:ring-[3px] "
                            "aria-invalid:ring-destructive/20 aria-invalid:border-destructive dark:aria-invalid:ring-destructive/40",
                            props.has_error ? "border-destructive ring-destructive/20 dark:ring-destructive/40" : "",
                            props.class_
                        ),
                        attr_if(props.disabled, disabled),
                        "data-tui-timepicker"_a = "true",
                        "data-tui-timepicker-use12hours"_a = use12_str,
                        "data-tui-timepicker-am-label"_a = am_label,
                        "data-tui-timepicker-pm-label"_a = pm_label,
                        "data-tui-timepicker-placeholder"_a = placeholder,
                        "data-tui-timepicker-step"_a = step_str,
                        attr_if(!props.min_time.empty(), "data-tui-timepicker-min-time"_a = props.min_time),
                        attr_if(!props.max_time.empty(), "data-tui-timepicker-max-time"_a = props.max_time),
                        attr_if(props.has_error, "aria-invalid"_a = "true"),
                        type = "button"
                    ) {
                        HT_TAG("span",
                            "data-tui-timepicker-display"_a = "",
                            class_ = "text-left grow text-muted-foreground"
                        ) {
                            HT_TEXT(placeholder);
                        }
                    }
                }
                HT_USE(popover::content, {
                    .class_    = "p-0 w-80",
                    .placement = popover::placement::bottom_start,
                    .offset    = 4,
                }) {
                    HT_DIV(class_ = "w-full rounded-lg border bg-card text-card-foreground shadow-xs border-0 shadow-none") {
                        HT_DIV(class_ = "p-4 p-6") {
                            HT_DIV(
                                "data-tui-timepicker-popup"_a = "true",
                                "data-tui-timepicker-input-name"_a = props.name,
                                attr_if(!props.value.empty(), "data-tui-timepicker-value"_a = props.value)
                            ) {
                                HT_DIV(class_ = "grid grid-cols-2 gap-3 mb-4") {
                                    HT_DIV(class_ = "space-y-2") {
                                        HT_LABEL(class_ = "text-sm font-medium") { HT_TEXT("Hour"); }
                                        HT_DIV(class_ = "max-h-32 overflow-y-auto border rounded-md bg-background") {
                                            HT_DIV("data-tui-timepicker-hour-list"_a = "true", class_ = "p-1 space-y-0.5") {
                                            }
                                        }
                                    }
                                    HT_DIV(class_ = "space-y-2") {
                                        HT_LABEL(class_ = "text-sm font-medium") { HT_TEXT("Minute"); }
                                        HT_DIV(class_ = "max-h-32 overflow-y-auto border rounded-md bg-background") {
                                            HT_DIV("data-tui-timepicker-minute-list"_a = "true", class_ = "p-1 space-y-0.5") {
                                            }
                                        }
                                    }
                                }
                                HT_DIV(class_ = "flex justify-between items-center") {
                                    if (props.use_12_hours) {
                                        HT_DIV(class_ = "flex gap-1") {
                                            HT_BUTTON(
                                                type = "button",
                                                "data-tui-timepicker-period"_a = "AM",
                                                "data-tui-timepicker-active"_a = "false",
                                                class_ = "px-3 py-1 text-sm rounded-md border transition-colors hover:bg-accent hover:text-accent-foreground "
                                                         "data-[tui-timepicker-active=true]:bg-primary data-[tui-timepicker-active=true]:text-primary-foreground "
                                                         "data-[tui-timepicker-active=true]:hover:bg-primary/90"
                                            ) {
                                                HT_TEXT(am_label);
                                            }
                                            HT_BUTTON(
                                                type = "button",
                                                "data-tui-timepicker-period"_a = "PM",
                                                "data-tui-timepicker-active"_a = "false",
                                                class_ = "px-3 py-1 text-sm rounded-md border transition-colors hover:bg-accent hover:text-accent-foreground "
                                                         "data-[tui-timepicker-active=true]:bg-primary data-[tui-timepicker-active=true]:text-primary-foreground "
                                                         "data-[tui-timepicker-active=true]:hover:bg-primary/90"
                                            ) {
                                                HT_TEXT(pm_label);
                                            }
                                        }
                                    } else {
                                        HT_DIV() {}
                                    }
                                    HT_BUTTON(
                                        type = "button",
                                        class_ = "bg-secondary text-secondary-foreground shadow-xs hover:bg-secondary/80 "
                                                 "h-8 rounded-md gap-1.5 px-3 has-[>svg]:px-2.5 "
                                                 "inline-flex items-center justify-center",
                                        "data-tui-timepicker-done"_a = "true"
                                    ) {
                                        HT_TEXT("Done");
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
