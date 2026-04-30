#include "htpp.hh"
#include "ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace table {
    HT_COMPONENT(table, const table::props &props) {
        HT_TABLE(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("w-full caption-bottom text-sm", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(header, const header_props &props) {
        HT_THEAD(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("[&_tr]:border-b", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(body, const body_props &props) {
        HT_TBODY(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("[&_tr:last-child]:border-0", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(footer, const footer_props &props) {
        HT_TFOOT(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("border-t bg-muted/50 font-medium [&>tr]:last:border-b-0", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(row, const row_props &props) {
        HT_TR(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(
                "border-b transition-colors hover:bg-muted/50",
                props.selected ? "data-[tui-table-state-selected]:bg-muted" : "",
                props.class_
            ),
            attr_if(props.selected, "data-tui-table-state-selected"_a = "")
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(head, const head_props &props) {
        HT_TH(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(
                "h-10 px-2 text-left align-middle font-medium text-muted-foreground "
                "[&:has([role=checkbox])]:pr-0 [&>[role=checkbox]]:translate-y-[2px]",
                props.class_
            )
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(cell, const cell_props &props) {
        HT_TD(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(
                "p-2 align-middle "
                "[&:has([role=checkbox])]:pr-0 [&>[role=checkbox]]:translate-y-[2px]",
                props.class_
            )
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(caption, const caption_props &props) {
        HT_TAG("caption",
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("mt-4 text-sm text-muted-foreground", props.class_)
        ) {
            HT_SLOT();
        }
    }
}
