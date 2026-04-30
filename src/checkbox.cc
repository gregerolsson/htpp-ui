#include "htpp.hh"
#include "ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace checkbox {
    HT_COMPONENT(script) {
    }

    HT_COMPONENT(checkbox, const checkbox::props &props) {
        HT_DIV(class_ = "relative inline-flex items-center") {
            HT_INPUT(
                attr_if(props.checked, checked),
                attr_if(props.disabled, disabled),
                attr_if(!props.id.empty(), id = props.id),
                attr_if(!props.name.empty(), name = props.name),
                value = (props.value.empty() ? "on" : props.value),
                attr_if(!props.form.empty(), "form"_a = props.form),
                attr_if(!props.group.empty(), "data-tui-checkbox-group"_a = props.group),
                attr_if(props.group_parent, "data-tui-checkbox-parent"_a = "true"),
                type = "checkbox",
                class_ = ui::merge(
                    "peer size-4 shrink-0 rounded-[4px] border border-input shadow-xs "
                    "focus-visible:outline-none focus-visible:ring-[3px] focus-visible:ring-ring/50 focus-visible:border-ring "
                    "disabled:cursor-not-allowed disabled:opacity-50 "
                    "checked:bg-primary checked:text-primary-foreground checked:border-primary "
                    "indeterminate:bg-primary indeterminate:text-primary-foreground indeterminate:border-primary "
                    "appearance-none cursor-pointer transition-shadow "
                    "relative",
                    props.class_
                )
            );
            HT_DIV(class_ = "absolute inset-0 pointer-events-none flex items-center justify-center text-primary-foreground opacity-0 peer-checked:opacity-100") {
            }
            HT_DIV(class_ = "absolute inset-0 pointer-events-none flex items-center justify-center text-primary-foreground opacity-0 peer-indeterminate:opacity-100") {
            }
        }
    }
}
