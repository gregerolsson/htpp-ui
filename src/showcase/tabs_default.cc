#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(account_tab) {
    HT_USE(card::card, {}) {
        HT_USE(card::header, {}) {
            HT_USE(card::title, {}) {
                os << "Account";
            }
            HT_USE(card::description, {}) {
                os << "Make changes to your account here. Click save when you are done.";
            }
        }
        HT_USE(card::content, {}) {
            HT_DIV(class_ = "flex flex-col gap-4") {
                input::input(os, {.id = "name", .type_ = input::text, .placeholder = "Name", .value = "John Doe"});
                input::input(os, {.id = "email", .type_ = input::email, .placeholder = "Email", .value = "john.doe@example.com"});
            }
        }
        HT_USE(card::footer, {}) {
            HT_USE(button::button, {}) {
                os << "Save changes";
            }
        }
    }
}

HT_COMPONENT(password_tab) {
    HT_USE(card::card, {}) {
        HT_USE(card::header, {}) {
            HT_USE(card::title, {}) {
                os << "Password";
            }
            HT_USE(card::description, {}) {
                os << "Change your password here. After saving, you will be logged out.";
            }
        }
        HT_USE(card::content, {}) {
            HT_DIV(class_ = "flex flex-col gap-4") {
                input::input(os, {.id = "current_password", .type_ = input::password, .placeholder = "Current Password"});
                input::input(os, {.id = "new_password", .type_ = input::password, .placeholder = "New Password"});
            }
        }
        HT_USE(card::footer, {}) {
            HT_USE(button::button, {}) {
                os << "Save password";
            }
        }
    }
}

HT_COMPONENT(tabs_default) {
    HT_USE(tabs::tabs, {.id = "account-tabs"}) {
        HT_USE(tabs::list, {.class_ = "w-full max-w-xs"}) {
            HT_USE(tabs::trigger, {.value = "account", .is_active = true, .tabs_id = "account-tabs"}) {
                os << "Account";
            }
            HT_USE(tabs::trigger, {.value = "password", .tabs_id = "account-tabs"}) {
                os << "Password";
            }
        }
        HT_DIV(class_ = "w-full max-w-xs mt-2") {
            HT_USE(tabs::content, {.value = "account", .is_active = true, .tabs_id = "account-tabs"}) {
                account_tab(os, {});
            }
            HT_USE(tabs::content, {.value = "password", .tabs_id = "account-tabs"}) {
                password_tab(os, {});
            }
        }
    }
}
