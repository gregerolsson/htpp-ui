#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(dropdown_default) {
    HT_USE(dropdown::dropdown, {}) {
        HT_USE(dropdown::trigger, {}) {
            HT_USE(button::button, {.variant = button::outline}) {
                os << "Open";
            }
        }
        HT_USE(dropdown::content, {.class_ = "w-56"}) {
            HT_USE(dropdown::label, {}) {
                os << "My Account";
            }
            dropdown::separator(os, {});
            HT_USE(dropdown::group, {}) {
                HT_USE(dropdown::item, {}) {
                    os << "Team";
                }
                HT_USE(dropdown::sub, {}) {
                    HT_USE(dropdown::sub_trigger, {}) {
                        HT_SPAN(class_ = "flex items-center") {
                            HT_SPAN() { os << "icon::users"; }
                            os << "Invite users";
                        }
                    }
                    HT_USE(dropdown::sub_content, {}) {
                        HT_USE(dropdown::item, {}) {
                            HT_SPAN(class_ = "flex items-center") {
                                HT_SPAN() { os << "icon::mail"; }
                                os << "Email";
                            }
                        }
                        HT_USE(dropdown::item, {}) {
                            HT_SPAN(class_ = "flex items-center") {
                                HT_SPAN() { os << "icon::message_square"; }
                                os << "Message";
                            }
                        }
                        dropdown::separator(os, {});
                        HT_USE(dropdown::item, {}) {
                            os << "More...";
                        }
                    }
                }
                HT_USE(dropdown::item, {}) {
                    os << "New Team";
                    HT_USE(dropdown::shortcut, {}) {
                        os << "⌘+T";
                    }
                }
            }
            dropdown::separator(os, {});
            HT_USE(dropdown::item, {.href = "https://github.com", .target = "_blank"}) {
                HT_SPAN(class_ = "flex items-center") {
                    HT_SPAN() { os << "icon::github"; }
                    os << "GitHub";
                }
            }
            HT_USE(dropdown::item, {}) {
                HT_SPAN(class_ = "flex items-center") {
                    HT_SPAN() { os << "icon::life_buoy"; }
                    os << "Support";
                }
            }
            HT_USE(dropdown::item, {.disabled = true}) {
                HT_SPAN(class_ = "flex items-center") {
                    HT_SPAN() { os << "icon::code"; }
                    os << "API";
                }
            }
            dropdown::separator(os, {});
            HT_USE(dropdown::item, {}) {
                HT_SPAN(class_ = "flex items-center") {
                    HT_SPAN() { os << "icon::log_out"; }
                    os << "Log out";
                }
                HT_USE(dropdown::shortcut, {}) {
                    os << "⇧⌘Q";
                }
            }
        }
    }
}
