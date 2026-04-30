#include "htpp.hh"
#include "ui.hh"

using namespace htpp::attr;

namespace accordion {
    inline constexpr std::string_view accordion_base =
        "group border-b last:border-b-0 "
        "[&[open]>summary>svg]:rotate-180";

    inline constexpr std::string_view item_base =
        "group border-b last:border-b-0 "
		"[&[open]>summary>svg]:rotate-180";

    inline constexpr std::string_view trigger_base =
        "flex flex-1 items-start justify-between gap-4 py-4 "
        "text-left text-sm font-medium "
        "transition-all hover:underline cursor-pointer "
        "outline-none focus-visible:ring-[3px] focus-visible:ring-ring/50 focus-visible:border-ring rounded-md "
        "disabled:pointer-events-none disabled:opacity-50 "
        "list-none [&::-webkit-details-marker]:hidden";

    HT_COMPONENT(accordion, const props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(accordion_base, props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(item, const item_props &props) {
        HT_DETAILS(attr_if(!props.id.empty(), id = props.id)) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(trigger, const trigger_props &props) {
        HT_SUMMARY(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(trigger_base, props.class_)
        ) {
            HT_SLOT();
            HT_SPAN() { os << "Icon"; }
        }
    }

    HT_COMPONENT(content, const content_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(trigger_base, props.class_)
        ) {
            HT_SLOT();
        }
    }
}
