#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(chart_area_stacked) {
    HT_USE(card::card, {.class_ = "max-w-sm"}) {
        HT_USE(card::content, {}) {
            chart::chart(os, {
                .variant = chart::line,
                .data = {
                    .labels = {"Jan", "Feb", "March", "April", "May", "June"},
                    .datasets = {
                        {.label = "Mobile", .data = {3, 9, 3, 12, 7, 8}, .border_width = 1, .tension = 0.5, .fill = true},
                        {.label = "Mobile", .data = {7, 16, 5, 20, 14, 15}, .border_width = 1, .tension = 0.5, .fill = true},
                    }
                },
                .show_x_labels = true,
                .show_y_grid = true,
            });
        }
    }
}
