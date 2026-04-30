#include "htpp.hh"
#include "htpp.ui.hh"

using namespace htpp::attr;

namespace aspectratio {
    constexpr std::string_view ratio_class(ratio r) {
        switch (r) {
            case ratio::square:   return "aspect-square";
            case ratio::video:    return "aspect-video";
            case ratio::portrait: return "aspect-[3/4]";
            case ratio::wide:     return "aspect-[2/1]";
            case ratio::automatic:
            default:              return "aspect-auto";
        }
    }

    HT_COMPONENT(aspectratio, const aspectratio::props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("relative w-full", ratio_class(props.ratio), props.class_)
        ) {
            HT_DIV(class_ = "absolute inset-0") {
                HT_SLOT();
            }
        }
    }
}
