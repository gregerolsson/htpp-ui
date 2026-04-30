#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(chart_line_multiple) {
    HT_USE(card::card, {.class_ = "max-w-sm"}) {
        HT_USE(card::content, {}) {
            chart::chart(os, {
                .variant = chart::line,
                .data = {
                    .labels = {"Jan", "Feb", "March", "April", "May", "June"},
                    .datasets = {
                        {.label = "Mobile", .data = {12, 3, 9, 3, 12, 7}, .tension = 0.5},
                        {.label = "Desktop", .data = {7, 14, 12, 21, 2, 9}, .tension = 0.5},
                    }
                },
                .show_x_labels = true,
                .show_y_grid = true,
            });
        }
    }
}
