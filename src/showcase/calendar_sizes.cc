#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(calendar_sizes) {
    HT_DIV() {
        HT_USE(card::card, {}) {
            HT_USE(card::content, {}) {
                calendar::calendar(os, {.class_ = "[--cell-size:2.5rem]"});
            }
        }
    }
}
