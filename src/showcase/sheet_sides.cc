#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(sheet_sides) {
    HT_DIV(class_ = "grid grid-cols-2 gap-4") {
        HT_USE(sheet::sheet, {.side = sheet::top}) {
            HT_USE(sheet::trigger, {}) {
                HT_USE(button::button, {.class_ = "w-full", .variant = button::outline}) {
                    os << "Open from Top";
                }
            }
            HT_USE(sheet::content, {}) {
                HT_USE(sheet::header, {}) {
                    HT_USE(sheet::title, {}) {
                        os << "Top Sheet";
                    }
                    HT_USE(sheet::description, {}) {
                        os << "This slides in from the top.";
                    }
                }
                HT_DIV(class_ = "px-4 py-6") {
                    HT_P(class_ = "text-sm") {
                        os << "Content for the top sheet.";
                    }
                }
                HT_USE(sheet::footer, {}) {
                    HT_USE(sheet::close, {}) {
                        HT_USE(button::button, {}) {
                            os << "Close";
                        }
                    }
                }
            }
        }
        HT_USE(sheet::sheet, {.side = sheet::right}) {
            HT_USE(sheet::trigger, {}) {
                HT_USE(button::button, {.class_ = "w-full", .variant = button::outline}) {
                    os << "Open from Right";
                }
            }
            HT_USE(sheet::content, {}) {
                HT_USE(sheet::header, {}) {
                    HT_USE(sheet::title, {}) {
                        os << "Right Sheet";
                    }
                    HT_USE(sheet::description, {}) {
                        os << "This slides in from the right.";
                    }
                }
                HT_DIV(class_ = "px-4 py-6") {
                    HT_P(class_ = "text-sm") {
                        os << "Content for the right sheet.";
                    }
                }
                HT_USE(sheet::footer, {}) {
                    HT_USE(sheet::close, {}) {
                        HT_USE(button::button, {}) {
                            os << "Close";
                        }
                    }
                }
            }
        }
        HT_USE(sheet::sheet, {.side = sheet::bottom}) {
            HT_USE(sheet::trigger, {}) {
                HT_USE(button::button, {.class_ = "w-full", .variant = button::outline}) {
                    os << "Open from Bottom";
                }
            }
            HT_USE(sheet::content, {}) {
                HT_USE(sheet::header, {}) {
                    HT_USE(sheet::title, {}) {
                        os << "Bottom Sheet";
                    }
                    HT_USE(sheet::description, {}) {
                        os << "This slides in from the bottom.";
                    }
                }
                HT_DIV(class_ = "px-4 py-6") {
                    HT_P(class_ = "text-sm") {
                        os << "Content for the bottom sheet.";
                    }
                }
                HT_USE(sheet::footer, {}) {
                    HT_USE(sheet::close, {}) {
                        HT_USE(button::button, {}) {
                            os << "Close";
                        }
                    }
                }
            }
        }
        HT_USE(sheet::sheet, {.side = sheet::left}) {
            HT_USE(sheet::trigger, {}) {
                HT_USE(button::button, {.class_ = "w-full", .variant = button::outline}) {
                    os << "Open from Left";
                }
            }
            HT_USE(sheet::content, {}) {
                HT_USE(sheet::header, {}) {
                    HT_USE(sheet::title, {}) {
                        os << "Left Sheet";
                    }
                    HT_USE(sheet::description, {}) {
                        os << "This slides in from the left.";
                    }
                }
                HT_DIV(class_ = "px-4 py-6") {
                    HT_P(class_ = "text-sm") {
                        os << "Content for the left sheet.";
                    }
                }
                HT_USE(sheet::footer, {}) {
                    HT_USE(sheet::close, {}) {
                        HT_USE(button::button, {}) {
                            os << "Close";
                        }
                    }
                }
            }
        }
    }
}
