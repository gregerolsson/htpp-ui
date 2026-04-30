#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(chart_line_step) {
    HT_USE(card::card, {.class_ = "max-w-sm"}) {
        HT_USE(card::content, {}) {
            chart::chart(os, {
                .variant = chart::line,
                .data = {
                    .labels = {"Jan", "Feb", "March", "April", "May", "June"},
                    .datasets = {
                        {.data = {12, 3, 9, 3, 12, 7}, .stepped = true},
                    }
                },
                .show_x_labels = true,
                .show_y_grid = true,
            });
        }
    }
}
