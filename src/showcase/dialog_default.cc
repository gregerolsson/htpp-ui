#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(dialog_default) {
    HT_USE(dialog::dialog, {}) {
        HT_USE(dialog::trigger, {}) {
            HT_USE(button::button, {.variant = button::outline}) {
                os << "Open Dialog";
            }
        }
        HT_USE(dialog::content, {.class_ = "max-w-md"}) {
            HT_USE(dialog::header, {}) {
                HT_USE(dialog::title, {}) {
                    os << "Edit Profile";
                }
                HT_USE(dialog::description, {}) {
                    os << "Make changes to your profile here. Click save when you're done.";
                }
            }
            HT_DIV(class_ = "space-y-4") {
                HT_DIV(class_ = "space-y-2") {
                    HT_USE(form::label, {.for_ = "name"}) {
                        os << "Name";
                    }
                    input::input(os, {.id = "name", .placeholder = "Enter your name", .value = "John Doe"});
                }
                HT_DIV(class_ = "space-y-2") {
                    HT_USE(form::label, {.for_ = "username"}) {
                        os << "Username";
                    }
                    input::input(os, {.id = "username", .placeholder = "Enter your username", .value = "@johndoe"});
                }
            }
            HT_USE(dialog::footer, {}) {
                HT_USE(dialog::close, {}) {
                    HT_USE(button::button, {.variant = button::outline}) {
                        os << "Cancel";
                    }
                }
                HT_USE(button::button, {}) {
                    os << "Save changes";
                }
            }
        }
    }
}
