#include "htpp.ico.hh"
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
                            icon::icon(os, {.class_ = "size-4 mr-2", .glyph = glyph::users});
                            os << "Invite users";
                        }
                    }
                    HT_USE(dropdown::sub_content, {}) {
                        HT_USE(dropdown::item, {}) {
                            HT_SPAN(class_ = "flex items-center") {
                                icon::icon(os, {.class_ = "size-4 mr-2", .glyph = glyph::mail});
                                os << "Email";
                            }
                        }
                        HT_USE(dropdown::item, {}) {
                            HT_SPAN(class_ = "flex items-center") {
                                icon::icon(os, {.class_ = "size-4 mr-2", .glyph = glyph::message_square});
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
                    icon::icon(os, {.class_ = "size-4 mr-2", .glyph = glyph::git_graph});
                    os << "GitHub";
                }
            }
            HT_USE(dropdown::item, {}) {
                HT_SPAN(class_ = "flex items-center") {
                    icon::icon(os, {.class_ = "size-4 mr-2", .glyph = glyph::life_buoy});
                    os << "Support";
                }
            }
            HT_USE(dropdown::item, {.disabled = true}) {
                HT_SPAN(class_ = "flex items-center") {
                    icon::icon(os, {.class_ = "size-4 mr-2", .glyph = glyph::code});
                    os << "API";
                }
            }
            dropdown::separator(os, {});
            HT_USE(dropdown::item, {}) {
                HT_SPAN(class_ = "flex items-center") {
                    icon::icon(os, {.class_ = "size-4 mr-2", .glyph = glyph::log_out});
                    os << "Log out";
                }
                HT_USE(dropdown::shortcut, {}) {
                    os << "⇧⌘Q";
                }
            }
        }
    }
}
