#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(popover_positions) {
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

    HT_DIV(class_ = "flex flex-col w-full max-w-md") {
        HT_DIV(class_ = "grid grid-cols-3 gap-2") {
            HT_USE(popover::root, {}) {
                HT_USE(popover::trigger, {.trigger_type = popover::hover}) {
                    HT_USE(button::button, {.class_ = "w-full", .variant = button::outline}) {
                        os << "Top Start";
                    }
                }
                HT_USE(popover::content, {.placement = popover::top_start, .show_arrow = true}) {
                    popover_content();
                }
            }
            HT_USE(popover::root, {}) {
                HT_USE(popover::trigger, {.trigger_type = popover::hover}) {
                    HT_USE(button::button, {.class_ = "w-full", .variant = button::outline}) {
                        os << "Top";
                    }
                }
                HT_USE(popover::content, {.placement = popover::top, .show_arrow = true}) {
                    popover_content();
                }
            }
            HT_USE(popover::root, {}) {
                HT_USE(popover::trigger, {.trigger_type = popover::hover}) {
                    HT_USE(button::button, {.class_ = "w-full", .variant = button::outline}) {
                        os << "Top End";
                    }
                }
                HT_USE(popover::content, {.placement = popover::top_end, .show_arrow = true}) {
                    popover_content();
                }
            }
            HT_USE(popover::root, {}) {
                HT_USE(popover::trigger, {.trigger_type = popover::hover}) {
                    HT_USE(button::button, {.class_ = "w-full", .variant = button::outline}) {
                        os << "Right Start";
                    }
                }
                HT_USE(popover::content, {.placement = popover::right_start, .show_arrow = true}) {
                    popover_content();
                }
            }
            HT_USE(popover::root, {}) {
                HT_USE(popover::trigger, {.trigger_type = popover::hover}) {
                    HT_USE(button::button, {.class_ = "w-full", .variant = button::outline}) {
                        os << "Right";
                    }
                }
                HT_USE(popover::content, {.placement = popover::right, .show_arrow = true}) {
                    popover_content();
                }
            }
            HT_USE(popover::root, {}) {
                HT_USE(popover::trigger, {.trigger_type = popover::hover}) {
                    HT_USE(button::button, {.class_ = "w-full", .variant = button::outline}) {
                        os << "Right End";
                    }
                }
                HT_USE(popover::content, {.placement = popover::right_end, .show_arrow = true}) {
                    popover_content();
                }
            }
            HT_USE(popover::root, {}) {
                HT_USE(popover::trigger, {.trigger_type = popover::hover}) {
                    HT_USE(button::button, {.class_ = "w-full", .variant = button::outline}) {
                        os << "Bottom Start";
                    }
                }
                HT_USE(popover::content, {.placement = popover::bottom_start, .show_arrow = true}) {
                    popover_content();
                }
            }
            HT_USE(popover::root, {}) {
                HT_USE(popover::trigger, {.trigger_type = popover::hover}) {
                    HT_USE(button::button, {.class_ = "w-full", .variant = button::outline}) {
                        os << "Bottom";
                    }
                }
                HT_USE(popover::content, {.placement = popover::bottom, .show_arrow = true}) {
                    popover_content();
                }
            }
            HT_USE(popover::root, {}) {
                HT_USE(popover::trigger, {.trigger_type = popover::hover}) {
                    HT_USE(button::button, {.class_ = "w-full", .variant = button::outline}) {
                        os << "Bottom End";
                    }
                }
                HT_USE(popover::content, {.placement = popover::bottom_end, .show_arrow = true}) {
                    popover_content();
                }
            }
            HT_USE(popover::root, {}) {
                HT_USE(popover::trigger, {.trigger_type = popover::hover}) {
                    HT_USE(button::button, {.class_ = "w-full", .variant = button::outline}) {
                        os << "Left Start";
                    }
                }
                HT_USE(popover::content, {.placement = popover::left_start, .show_arrow = true}) {
                    popover_content();
                }
            }
            HT_USE(popover::root, {}) {
                HT_USE(popover::trigger, {.trigger_type = popover::hover}) {
                    HT_USE(button::button, {.class_ = "w-full", .variant = button::outline}) {
                        os << "Left";
                    }
                }
                HT_USE(popover::content, {.placement = popover::left, .show_arrow = true}) {
                    popover_content();
                }
            }
            HT_USE(popover::root, {}) {
                HT_USE(popover::trigger, {.trigger_type = popover::hover}) {
                    HT_USE(button::button, {.class_ = "w-full", .variant = button::outline}) {
                        os << "Left End";
                    }
                }
                HT_USE(popover::content, {.placement = popover::left_end, .show_arrow = true}) {
                    popover_content();
                }
            }
        }
    }
}
