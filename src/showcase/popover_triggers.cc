#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(popover_triggers) {
    auto popover_content = [&]() {
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
    };

    HT_DIV(class_ = "flex gap-2 flex-wrap") {
        HT_USE(popover::root, {}) {
            HT_USE(popover::trigger, {.trigger_type = popover::hover}) {
                HT_USE(button::button, {.variant = button::outline}) {
                    os << "Hover";
                }
            }
            HT_USE(popover::content, {.hover_delay = 300, .hover_out_delay = 500}) {
                popover_content();
            }
        }
        HT_USE(popover::root, {}) {
            HT_USE(popover::trigger, {}) {
                HT_USE(button::button, {.variant = button::outline}) {
                    os << "Click";
                }
            }
            HT_USE(popover::content, {}) {
                popover_content();
            }
        }
        HT_USE(popover::root, {}) {
            HT_USE(popover::trigger, {}) {
                HT_USE(button::button, {.variant = button::outline}) {
                    os << "No ClickAway";
                }
            }
            HT_USE(popover::content, {.disable_click_away = true}) {
                popover_content();
            }
        }
        HT_USE(popover::root, {}) {
            HT_USE(popover::trigger, {}) {
                HT_USE(button::button, {.variant = button::outline}) {
                    os << "No ClickAway-ESC";
                }
            }
            HT_USE(popover::content, {.disable_click_away = true, .disable_esc = true}) {
                popover_content();
            }
        }
    }
}
