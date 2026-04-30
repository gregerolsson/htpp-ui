#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(table_) {
    HT_USE(table::table, {}) {
        HT_USE(table::caption, {}) {
            os << "A list of your recent hires.";
        }
        HT_USE(table::header, {}) {
            HT_USE(table::row, {}) {
                HT_USE(table::head, {}) {
                    os << "Name";
                }
                HT_USE(table::head, {}) {
                    os << "Role";
                }
                HT_USE(table::head, {}) {
                    os << "Status";
                }
                HT_USE(table::head, {}) {
                    os << "Actions";
                }
            }
        }
        HT_USE(table::body, {}) {
            HT_USE(table::row, {}) {
                HT_USE(table::cell, {}) {
                    os << "John Doe";
                }
                HT_USE(table::cell, {}) {
                    os << "Software Engineer";
                }
                HT_USE(table::cell, {}) {
                    os << "Active";
                }
                HT_USE(table::cell, {}) {
                    os << "Edit";
                }
            }
            HT_USE(table::row, {}) {
                HT_USE(table::cell, {}) {
                    os << "Jane Smith";
                }
                HT_USE(table::cell, {}) {
                    os << "Designer";
                }
                HT_USE(table::cell, {}) {
                    os << "Active";
                }
                HT_USE(table::cell, {}) {
                    os << "Edit";
                }
            }
            HT_USE(table::row, {}) {
                HT_USE(table::cell, {}) {
                    os << "Bob Johnson";
                }
                HT_USE(table::cell, {}) {
                    os << "Product Manager";
                }
                HT_USE(table::cell, {}) {
                    os << "Inactive";
                }
                HT_USE(table::cell, {}) {
                    os << "Edit";
                }
            }
            HT_USE(table::footer, {}) {
                HT_USE(table::row, {}) {
                    HT_USE(table::head, {}) {
                        os << "3 items";
                    }
                    HT_USE(table::head, {}) {
                        os << "1 page";
                    }
                    HT_USE(table::head, {}) {
                        os << "1-3 of 3";
                    }
                    HT_USE(table::head, {}) {
                        os << "Next";
                    }
                }
            }
        }
    }
}
