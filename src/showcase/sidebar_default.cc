#include "htpp.ico.hh"
#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(sidebar_default) {
    HT_USE(sidebar::layout, {}) {
        HT_USE(sidebar::sidebar, {.variant = sidebar::floating, .collapsible = sidebar::icon}) {
            HT_USE(sidebar::header, {}) {
                HT_USE(sidebar::menu, {}) {
                    HT_USE(sidebar::menu_item, {}) {
                        HT_USE(sidebar::menu_button, {.href = "#"}) {
                            icon::icon(os, {.glyph = glyph::layout_panel_left});
                            HT_SPAN(class_ = "font-semibold") {
                                os << "Acme Inc";
                            }
                        }
                    }
                }
            }
            HT_USE(sidebar::content, {}) {
                HT_USE(sidebar::group, {}) {
                    HT_USE(sidebar::group_label, {}) {
                        os << "Platform";
                    }
                    HT_USE(sidebar::menu, {}) {
                        HT_USE(sidebar::menu_item, {}) {
                            HT_USE(sidebar::menu_button, {.href = "#", .tooltip = "Home"}) {
                                icon::icon(os, {.glyph = glyph::house});
                                HT_SPAN() { os << "Home"; }
                            }
                        }
                        HT_USE(sidebar::menu_item, {}) {
                            HT_USE(sidebar::menu_button, {.href = "#", .tooltip = "Inbox"}) {
                                icon::icon(os, {.glyph = glyph::inbox});
                                HT_SPAN() { os << "Inbox"; }
                                HT_USE(sidebar::menu_badge, {}) {
                                    os << "3";
                                }
                            }
                        }
                        HT_USE(sidebar::menu_item, {}) {
                            HT_USE(collapsible::collapsible, {.class_ = "group/collapsible w-full", .open = true}) {
                                HT_USE(collapsible::trigger, {}) {
                                    HT_USE(sidebar::menu_button, {.tooltip = "Documents"}) {
                                        icon::icon(os, {.glyph = glyph::file_text});
                                        HT_SPAN() { os << "Documents"; }
                                        HT_SPAN(class_ = "ml-auto size-4 transition-transform group-data-[tui-collapsible-state=open]/collapsible:rotate-90") {
                                            os << "icon::chevron_right";
                                        }
                                    }
                                }
                                HT_USE(collapsible::content, {}) {
                                    HT_USE(sidebar::menu_sub, {}) {
                                        HT_USE(sidebar::menu_sub_item, {}) {
                                            HT_USE(sidebar::menu_sub_button, {.href = "#"}) {
                                                HT_SPAN() { os << "Reports"; }
                                            }
                                        }
                                        HT_USE(sidebar::menu_sub_item, {}) {
                                            HT_USE(sidebar::menu_sub_button, {.href = "#"}) {
                                                HT_SPAN() { os << "Invoices"; }
                                            }
                                        }
                                        HT_USE(sidebar::menu_sub_item, {}) {
                                            HT_USE(sidebar::menu_sub_button, {.href = "#", .is_active = true}) {
                                                HT_SPAN() { os << "Receipts"; }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                sidebar::separator(os, {});
                HT_USE(sidebar::group, {}) {
                    HT_USE(sidebar::group_label, {}) {
                        os << "Projects";
                    }
                    HT_USE(sidebar::menu, {}) {
                        HT_USE(sidebar::menu_item, {}) {
                            HT_USE(sidebar::menu_button, {.href = "#", .tooltip = "Project Alpha"}) {
                                icon::icon(os, {.glyph = glyph::folder});
                                HT_SPAN() { os << "Project Alpha"; }
                                HT_USE(sidebar::menu_badge, {}) {
                                    os << "12";
                                }
                            }
                        }
                        HT_USE(sidebar::menu_item, {}) {
                            HT_DIV(class_ = "w-full") {
                                HT_USE(sidebar::menu_button, {.tooltip = "Project Beta"}) {
                                    HT_SPAN() { os << "icon::folder"; }
                                    HT_SPAN() { os << "Project Beta"; }
                                }
                                HT_USE(sidebar::menu_sub, {}) {
                                    HT_USE(sidebar::menu_sub_item, {}) {
                                        HT_USE(sidebar::menu_sub_button, {.href = "#"}) {
                                            HT_SPAN() { os << "Overview"; }
                                        }
                                    }
                                    HT_USE(sidebar::menu_sub_item, {}) {
                                        HT_USE(sidebar::menu_sub_button, {.href = "#"}) {
                                            HT_SPAN() { os << "Analytics"; }
                                        }
                                    }
                                    HT_USE(sidebar::menu_sub_item, {}) {
                                        HT_USE(sidebar::menu_sub_button, {.href = "#"}) {
                                            HT_SPAN() { os << "Reports"; }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                sidebar::separator(os, {});
                HT_USE(sidebar::group, {}) {
                    HT_USE(sidebar::menu, {}) {
                        HT_USE(sidebar::menu_item, {}) {
                            HT_USE(sidebar::menu_button, {.href = "#", .tooltip = "Team"}) {
                                icon::icon(os, {.glyph = glyph::users});
                                HT_SPAN() { os << "Team"; }
                            }
                        }
                        HT_USE(sidebar::menu_item, {}) {
                            HT_USE(collapsible::collapsible, {.class_ = "group/collapsible w-full", .open = false}) {
                                HT_USE(collapsible::trigger, {}) {
                                    HT_USE(sidebar::menu_button, {.tooltip = "Settings"}) {
                                        icon::icon(os, {.glyph = glyph::settings});
                                        HT_SPAN() { os << "Settings"; }
                                        HT_SPAN(class_ = "ml-auto size-4 transition-transform group-data-[tui-collapsible-state=open]/collapsible:rotate-90") {
                                            icon::icon(os, {.glyph = glyph::chevron_right});
                                        }
                                    }
                                }
                                HT_USE(collapsible::content, {}) {
                                    HT_USE(sidebar::menu_sub, {}) {
                                        HT_USE(sidebar::menu_sub_item, {}) {
                                            HT_USE(sidebar::menu_sub_button, {.href = "#"}) {
                                                HT_SPAN() { os << "General"; }
                                            }
                                        }
                                        HT_USE(sidebar::menu_sub_item, {}) {
                                            HT_USE(sidebar::menu_sub_button, {.href = "#"}) {
                                                HT_SPAN() { os << "Security"; }
                                            }
                                        }
                                        HT_USE(sidebar::menu_sub_item, {}) {
                                            HT_USE(sidebar::menu_sub_button, {.href = "#"}) {
                                                HT_SPAN() { os << "Notifications"; }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            HT_USE(sidebar::footer, {}) {
                HT_USE(sidebar::menu, {}) {
                    HT_USE(sidebar::menu_item, {}) {
                        HT_USE(dropdown::dropdown, {}) {
                            HT_USE(dropdown::trigger, {}) {
                                HT_USE(sidebar::menu_button, {.size = sidebar::lg}) {
                                    HT_USE(avatar::avatar, {.class_ = "size-8 rounded-lg"}) {
                                        avatar::image(os, {.src = "https://avatars.githubusercontent.com/u/26936893?v=4"});
                                    }
                                    HT_DIV(class_ = "grid flex-1 text-left text-sm leading-tight") {
                                        HT_SPAN(class_ = "truncate font-medium") {
                                            os << "John Doe";
                                        }
                                        HT_SPAN(class_ = "truncate text-xs") {
                                            os << "john@example.com";
                                        }
                                    }
                                    HT_SPAN(class_ = "ml-auto size-4") {
                                        icon::icon(os, {.glyph = glyph::chevrons_up_down});
                                    }
                                }
                            }
                            HT_USE(dropdown::content, {.class_ = "w-56", .placement = popover::top_start}) {
                                HT_USE(dropdown::label, {}) {
                                    os << "John Doe";
                                }
                                dropdown::separator(os, {});
                                HT_USE(dropdown::item, {}) {
                                    HT_SPAN(class_ = "flex items-center") {
                                        icon::icon(os, {.class_ = "size-4 mr-2", .glyph = glyph::user});
                                        os << "Profile";
                                    }
                                }
                                HT_USE(dropdown::item, {}) {
                                    HT_SPAN(class_ = "flex items-center") {
                                        icon::icon(os, {.class_ = "size-4 mr-2", .glyph = glyph::settings});
                                        os << "Settings";
                                    }
                                }
                                dropdown::separator(os, {});
                                HT_USE(dropdown::item, {}) {
                                    HT_SPAN(class_ = "flex items-center") {
                                        icon::icon(os, {.class_ = "size-4 mr-2", .glyph = glyph::log_out});
                                        os << "Log out";
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        HT_USE(sidebar::inset, {}) {
            HT_DIV(class_ = "flex h-full flex-col") {
                HT_DIV(class_ = "flex h-14 items-center gap-4 px-6") {
                    sidebar::trigger(os, {});
                    HT_SPAN(class_ = "text-sm text-muted-foreground") {
                        os << "Press Ctrl+B to toggle sidebar";
                    }
                }
                HT_DIV(class_ = "flex-1 p-6") {}
            }
        }
    }
}
