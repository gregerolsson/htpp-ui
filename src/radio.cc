#include "htpp.hh"
#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace radio {
    HT_COMPONENT(radio, const radio::props &props) {
        HT_INPUT(
            type = "radio",
            attr_if(!props.id.empty(), id = props.id),
            attr_if(!props.name.empty(), name = props.name),
            attr_if(!props.value.empty(), value = props.value),
            attr_if(!props.form.empty(), "form"_a = props.form),
            attr_if(props.checked, checked),
            attr_if(props.disabled, disabled),
            class_ = ui::merge(
                "relative h-4 w-4 "
                "before:absolute before:left-1/2 before:top-1/2 "
                "before:h-1.5 before:w-1.5 before:-translate-x-1/2 before:-translate-y-1/2 "
                "appearance-none rounded-full "
                "border-2 border-primary "
                "before:content[''] before:rounded-full before:bg-background "
                "checked:border-primary checked:bg-primary "
                "checked:before:visible "
                "focus-visible:outline-hidden focus-visible:ring-2 focus-visible:ring-ring "
                "focus-visible:ring-offset-2 focus-visible:ring-offset-background "
                "disabled:cursor-not-allowed",
                props.class_
            )
        );
    }
}
