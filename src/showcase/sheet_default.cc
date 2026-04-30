#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(sheet_default) {
    HT_USE(sheet::sheet, {.side = sheet::right}) {
        HT_USE(sheet::trigger, {}) {
            HT_USE(button::button, {.variant = button::outline}) {
                os << "Open";
            }
        }
        HT_USE(sheet::content, {}) {
            HT_USE(sheet::header, {}) {
                HT_USE(sheet::title, {}) {
                    os << "Edit profile";
                }
                HT_USE(sheet::description, {}) {
                    os << "Make changes to your profile here. Click save when you're done.";
                }
            }
            HT_DIV(class_ = "grid flex-1 auto-rows-min gap-6 px-4") {
                HT_DIV(class_ = "grid gap-3") {
                    HT_USE(label::label, {.for_ = "sheet-demo-name"}) {
                        os << "Name";
                    }
                    input::input(os, {.id = "sheet-demo-name", .type_ = input::text, .value = "Pedro Duarte"});
                }
                HT_DIV(class_ = "grid gap-3") {
                    HT_USE(label::label, {.for_ = "sheet-demo-username"}) {
                        os << "Username";
                    }
                    input::input(os, {.id = "sheet-demo-username", .type_ = input::text, .value = "@peduarte"});
                }
            }
            HT_USE(sheet::footer, {}) {
                HT_USE(button::button, {.type_ = button::submit}) {
                    os << "Save changes";
                }
                HT_USE(sheet::close, {}) {
                    HT_USE(button::button, {.variant = button::outline}) {
                        os << "Close";
                    }
                }
            }
        }
    }
}
