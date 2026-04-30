#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(chart_default) {
    HT_USE(card::card, {.class_ = "max-w-sm"}) {
        HT_USE(card::content, {}) {
            chart::chart(os, {
                .variant = chart::bar,
                .data = {
                    .labels = {"Jan", "Feb", "March", "April", "May", "June"},
                    .datasets = {
                        {.data = {12, 19, 12, 5, 2, 3}},
                    }
                },
                .show_x_labels = true,
                .show_y_grid = true,
            });
        }
    }
}
