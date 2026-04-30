#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(card_default) {
    HT_DIV(class_ = "w-full max-w-sm") {
        HT_USE(card::card, {}) {
            HT_USE(card::header, {}) {
                HT_USE(card::title, {}) {
                    os << "Create Project";
                }
                HT_USE(card::description, {}) {
                    os << "Deploy your new project in one-click.";
                }
            }
            HT_USE(card::content, {}) {
                HT_DIV(class_ = "flex flex-col gap-4") {
                    HT_DIV(class_ = "w-full max-w-sm grid gap-2") {
                        HT_USE(label::label, {.for_ = "name"}) {
                            os << "Name";
                        }
                        input::input(os, {.id = "name", .placeholder = "Enter project name"});
                    }
                    HT_DIV(class_ = "w-full max-w-sm grid gap-2") {
                        HT_USE(label::label, {.for_ = "service"}) {
                            os << "Service";
                        }
                        HT_USE(selectbox::selectbox, {}) {
                            HT_USE(selectbox::trigger, {.id = "service"}) {
                                selectbox::value(os, {.placeholder = "Select"});
                            }
                            HT_USE(selectbox::content, {}) {
                                HT_USE(selectbox::group, {}) {
                                    HT_USE(selectbox::item, {.value = "postgres"}) {
                                        os << "PostgreSQL";
                                    }
                                    HT_USE(selectbox::item, {.value = "mysql"}) {
                                        os << "MySQL";
                                    }
                                    HT_USE(selectbox::item, {.value = "sqlite"}) {
                                        os << "SQLite";
                                    }
                                }
                            }
                        }
                    }
                }
            }
            HT_USE(card::footer, {.class_ = "flex justify-between"}) {
                HT_USE(button::button, {.variant = button::secondary}) {
                    os << "Cancel";
                }
                HT_USE(button::button, {}) {
                    os << "Deploy";
                }
            }
        }
    }
}
