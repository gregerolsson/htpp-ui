#include "htpp.hh"
#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace switch_ {
    HT_COMPONENT(switch_, const switch_::props &props) {
        HT_LABEL(
            for_ = props.id,
            class_ = ui::merge(
                "inline-flex cursor-pointer items-center gap-2",
                props.disabled ? "cursor-not-allowed" : ""
            )
        ) {
            HT_INPUT(
                id = props.id,
                attr_if(!props.name.empty(), name = props.name),
                type = "checkbox",
                value = (props.value.empty() ? "on" : props.value),
                attr_if(!props.form.empty(), "form"_a = props.form),
                attr_if(props.checked, checked),
                attr_if(props.disabled, disabled),
                class_ = "peer hidden",
                role = "switch"
            );
            HT_DIV(
                class_ = ui::merge(
                    "relative inline-flex h-5 w-9 shrink-0 cursor-pointer items-center "
                    "rounded-full border-2 border-transparent "
                    "transition-colors "
                    "bg-input "
                    "peer-checked:bg-primary "
                    "peer-focus-visible:outline-none peer-focus-visible:ring-2 "
                    "peer-focus-visible:ring-ring peer-focus-visible:ring-offset-2 "
                    "peer-focus-visible:ring-offset-background "
                    "peer-disabled:cursor-not-allowed peer-disabled:opacity-50 "
                    "after:pointer-events-none after:block "
                    "after:h-4 after:w-4 "
                    "after:rounded-full after:bg-background "
                    "after:shadow-lg after:ring-0 "
                    "after:transition-transform "
                    "after:content-[''] "
                    "peer-checked:after:translate-x-4",
                    props.class_
                ),
                aria_hidden = "true"
            ) {
            }
        }
    }
}
