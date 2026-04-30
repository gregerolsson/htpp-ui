#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(popover_default) {
    HT_USE(popover::root, {}) {
        HT_USE(popover::trigger, {}) {
            HT_USE(button::button, {.variant = button::outline}) {
                os << "Open Popover";
            }
        }
        HT_USE(popover::content, {}) {
            HT_DIV(class_ = "p-4 space-y-4") {
                HT_DIV() {
                    HT_H3(class_ = "text-lg font-semibold") {
                        os << "Dimensions";
                    }
                    HT_P() {
                        os << "Set the dimensions for the layer.";
                    }
                }
                HT_DIV(class_ = "flex flex-col gap-2 max-w-fit") {
                    HT_DIV(class_ = "flex items-center gap-2") {
                        HT_USE(label::label, {.class_ = "w-24", .for_ = "width"}) {
                            os << "Width";
                        }
                        input::input(os, {.id = "width", .class_ = "flex-1", .placeholder = "Width", .value = "100%"});
                    }
                    HT_DIV(class_ = "flex items-center gap-2") {
                        HT_USE(label::label, {.class_ = "w-24", .for_ = "height"}) {
                            os << "Height";
                        }
                        input::input(os, {.id = "height", .class_ = "flex-1", .placeholder = "Height", .value = "100%"});
                    }
                }
            }
        }
    }
}
