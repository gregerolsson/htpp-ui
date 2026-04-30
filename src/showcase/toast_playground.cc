#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(toast_playground) {
    HT_DIV(class_ = "w-full max-w-4xl mx-auto p-8") {
        HT_SECTION(class_ = "mb-12") {
            HT_USE(card::card, {}) {
                HT_USE(card::content, {}) {
                    HT_FORM(class_ = "flex flex-col gap-2", hx_post = "/docs/toast/demo", hx_trigger = "submit", hx_target = "#toast-advanced-container") {
                        HT_USE(form::item, {}) {
                            HT_USE(form::label, {.for_ = "title"}) {
                                os << "Message";
                            }
                            input::input(os, {.id = "title", .name = "title", .value = "You have a new notification"});
                        }
                        HT_USE(form::item, {}) {
                            HT_USE(form::label, {.for_ = "description"}) {
                                os << "Description";
                            }
                            input::input(os, {.id = "description", .name = "description", .value = "Test Notification"});
                        }
                        HT_USE(form::item, {}) {
                            HT_USE(form::label, {.for_ = "type"}) {
                                os << "Type";
                            }
                            HT_USE(selectbox::selectbox, {}) {
                                HT_USE(selectbox::trigger, {.id = "type", .name = "type"}) {
                                    HT_USE(selectbox::value, {.placeholder = "Default"}) {}
                                }
                                HT_USE(selectbox::content, {}) {
                                    HT_USE(selectbox::group, {}) {
                                        HT_USE(selectbox::item, {.value = "default", .selected = true}) {
                                            os << "Default";
                                        }
                                        HT_USE(selectbox::item, {.value = "success"}) {
                                            os << "Success";
                                        }
                                        HT_USE(selectbox::item, {.value = "error"}) {
                                            os << "Error";
                                        }
                                        HT_USE(selectbox::item, {.value = "warning"}) {
                                            os << "Warning";
                                        }
                                        HT_USE(selectbox::item, {.value = "info"}) {
                                            os << "Info";
                                        }
                                    }
                                }
                            }
                        }
                        HT_USE(form::item, {}) {
                            HT_USE(form::label, {.for_ = "position"}) {
                                os << "Position";
                            }
                            HT_USE(selectbox::selectbox, {}) {
                                HT_USE(selectbox::trigger, {.id = "position", .name = "position"}) {
                                    HT_USE(selectbox::value, {.placeholder = "Bottom Right"}) {}
                                }
                                HT_USE(selectbox::content, {}) {
                                    HT_USE(selectbox::group, {}) {
                                        HT_USE(selectbox::item, {.value = "top-right"}) {
                                            os << "Top Right";
                                        }
                                        HT_USE(selectbox::item, {.value = "top-left"}) {
                                            os << "Top Left";
                                        }
                                        HT_USE(selectbox::item, {.value = "top-center"}) {
                                            os << "Top Center";
                                        }
                                        HT_USE(selectbox::item, {.value = "bottom-right", .selected = true}) {
                                            os << "Bottom Right";
                                        }
                                        HT_USE(selectbox::item, {.value = "bottom-left"}) {
                                            os << "Bottom Left";
                                        }
                                        HT_USE(selectbox::item, {.value = "bottom-center"}) {
                                            os << "Bottom Center";
                                        }
                                    }
                                }
                            }
                        }
                        HT_USE(form::item, {}) {
                            HT_USE(form::label, {.for_ = "duration"}) {
                                os << "Duration (ms)";
                            }
                            input::input(os, {.id = "duration", .name = "duration", .type_ = input::number, .value = "3000"});
                        }
                        HT_USE(form::item, {}) {
                            HT_USE(form::label, {.for_ = "dismissible"}) {
                                os << "Dismissible";
                            }
                            HT_USE(form::item_flex, {}) {
                                switch_::switch_(os, {.id = "dismissible", .name = "dismissible", .checked = true});
                                HT_USE(label::label, {.for_ = "dismissible"}) {
                                    os << "Dimissible";
                                }
                            }
                            HT_USE(form::item_flex, {}) {
                                switch_::switch_(os, {.name = "icon", .checked = true});
                                HT_USE(label::label, {.for_ = "icon"}) {
                                    os << "Show Icon";
                                }
                            }
                            HT_USE(form::item_flex, {}) {
                                switch_::switch_(os, {.id = "indicator", .name = "indicator", .checked = true});
                                HT_USE(label::label, {.for_ = "indicator"}) {
                                    os << "Show Indicator";
                                }
                            }
                        }
                        HT_USE(button::button, {.class_ = "w-full", .variant = button::outline, .type_ = button::submit}) {
                            os << "Show Toast";
                        }
                    }
                }
            }
        }
        HT_DIV(id = "toast-advanced-container") {}
    }
}
