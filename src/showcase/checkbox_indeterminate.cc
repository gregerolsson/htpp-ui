#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(checkbox_indeterminate) {
    HT_DIV(class_ = "flex flex-col gap-4") {
        HT_DIV(class_ = "flex items-center gap-3 border-b pb-3") {
            checkbox::checkbox(os, {.id = "select-all", .group = "items", .group_parent = true});
            HT_USE(label::label, {.class_ = "font-medium", .for_ = "select-all"}) {
                os << "Select all";
            }
        }
        HT_DIV(class_ = "flex flex-col gap-3 pl-6") {
            HT_DIV(class_ = "flex items-center gap-3") {
                checkbox::checkbox(os, {.id = "item-1", .name = "items", .value = "1", .checked = true, .group = "items"});
                HT_USE(label::label, {.for_ = "item-1"}) {
                    os << "Item 1";
                }
            }
            HT_DIV(class_ = "flex items-center gap-3") {
                checkbox::checkbox(os, {.id = "item-2", .name = "items", .value = "2", .checked = true, .group = "items"});
                HT_USE(label::label, {.for_ = "item-2"}) {
                    os << "Item 2";
                }
            }
            HT_DIV(class_ = "flex items-center gap-3") {
                checkbox::checkbox(os, {.id = "item-3", .name = "items", .value = "3", .group = "items"});
                HT_USE(label::label, {.for_ = "item-3"}) {
                    os << "Item 3";
                }
            }
        }
    }
}
