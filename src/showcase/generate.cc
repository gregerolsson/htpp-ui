#include "htpp.hh"
#include "htpp.sc.hh"
#include <fstream>

using namespace htpp::attr;

struct layout_props {
    std::string_view name;
};

HT_COMPONENT_DECL(layout, const layout_props &props);

HT_COMPONENT(layout, const layout_props &props) {
    HT_DOCTYPE();
    HT_HTML(lang = "en") {
        HT_HEAD() {
            HT_META(charset = "utf-8");
            HT_TITLE() { os << props.name; }
            HT_LINK(rel = "stylesheet", href = "./index.css");
        }
        HT_BODY() { HT_SLOT(); }
        HT_SCRIPT(src="./index.js") { }
    }
}

int main() {
    {
        std::ofstream os("./htm/accordion_default.html");
        HT_USE(layout, {.name = "accordion_default"}) { accordion_default(os); }
    }
    {
        std::ofstream os("./htm/alert_default.html");
        HT_USE(layout, {.name = "alert_default"}) { alert_default(os); }
    }
    {
        std::ofstream os("./htm/alert_destructive.html");
        HT_USE(layout, {.name = "alert_destructive"}) { alert_destructive(os); }
    }
    {
        std::ofstream os("./htm/aspect_ratio_default.html");
        HT_USE(layout, {.name = "aspect_ratio_default"}) { aspect_ratio_default(os); }
    }
    {
        std::ofstream os("./htm/avatar_default.html");
        HT_USE(layout, {.name = "avatar_default"}) { avatar_default(os); }
    }
    {
        std::ofstream os("./htm/avatar_fallback.html");
        HT_USE(layout, {.name = "avatar_fallback"}) { avatar_fallback(os); }
    }
    {
        std::ofstream os("./htm/avatar_group.html");
        HT_USE(layout, {.name = "avatar_group"}) { avatar_group(os); }
    }
    {
        std::ofstream os("./htm/avatar_sizes.html");
        HT_USE(layout, {.name = "avatar_sizes"}) { avatar_sizes(os); }
    }
    {
        std::ofstream os("./htm/avatar_with_icon.html");
        HT_USE(layout, {.name = "avatar_with_icon"}) { avatar_with_icon(os); }
    }
    {
        std::ofstream os("./htm/badge_default.html");
        HT_USE(layout, {.name = "badge_default"}) { badge_default(os); }
    }
    {
        std::ofstream os("./htm/badge_destructive.html");
        HT_USE(layout, {.name = "badge_destructive"}) { badge_destructive(os); }
    }
    {
        std::ofstream os("./htm/badge_outline.html");
        HT_USE(layout, {.name = "badge_outline"}) { badge_outline(os); }
    }
    {
        std::ofstream os("./htm/badge_secondary.html");
        HT_USE(layout, {.name = "badge_secondary"}) { badge_secondary(os); }
    }
    {
        std::ofstream os("./htm/badge_with_icon.html");
        HT_USE(layout, {.name = "badge_with_icon"}) { badge_with_icon(os); }
    }
    {
        std::ofstream os("./htm/breadcrumb_custom_separator.html");
        HT_USE(layout, {.name = "breadcrumb_custom_separator"}) { breadcrumb_custom_separator(os); }
    }
    {
        std::ofstream os("./htm/breadcrumb_default.html");
        HT_USE(layout, {.name = "breadcrumb_default"}) { breadcrumb_default(os); }
    }
    {
        std::ofstream os("./htm/breadcrumb_responsive.html");
        HT_USE(layout, {.name = "breadcrumb_responsive"}) { breadcrumb_responsive(os); }
    }
    {
        std::ofstream os("./htm/breadcrumb_with_icons.html");
        HT_USE(layout, {.name = "breadcrumb_with_icons"}) { breadcrumb_with_icons(os); }
    }
    {
        std::ofstream os("./htm/button_default.html");
        HT_USE(layout, {.name = "button_default"}) { button_default(os); }
    }
    {
        std::ofstream os("./htm/button_destructive.html");
        HT_USE(layout, {.name = "button_destructive"}) { button_destructive(os); }
    }
    {
        std::ofstream os("./htm/button_ghost.html");
        HT_USE(layout, {.name = "button_ghost"}) { button_ghost(os); }
    }
    {
        std::ofstream os("./htm/button_icon.html");
        HT_USE(layout, {.name = "button_icon"}) { button_icon(os); }
    }
    {
        std::ofstream os("./htm/button_link.html");
        HT_USE(layout, {.name = "button_link"}) { button_link(os); }
    }
    {
        std::ofstream os("./htm/button_loading.html");
        HT_USE(layout, {.name = "button_loading"}) { button_loading(os); }
    }
    {
        std::ofstream os("./htm/button_outline.html");
        HT_USE(layout, {.name = "button_outline"}) { button_outline(os); }
    }
    {
        std::ofstream os("./htm/button_primary.html");
        HT_USE(layout, {.name = "button_primary"}) { button_primary(os); }
    }
    {
        std::ofstream os("./htm/button_secondary.html");
        HT_USE(layout, {.name = "button_secondary"}) { button_secondary(os); }
    }
    {
        std::ofstream os("./htm/button_sizes.html");
        HT_USE(layout, {.name = "button_sizes"}) { button_sizes(os); }
    }
    {
        std::ofstream os("./htm/button_with_icon.html");
        HT_USE(layout, {.name = "button_with_icon"}) { button_with_icon(os); }
    }
    {
        std::ofstream os("./htm/calendar_default.html");
        HT_USE(layout, {.name = "calendar_default"}) { calendar_default(os); }
    }
    {
        std::ofstream os("./htm/calendar_sizes.html");
        HT_USE(layout, {.name = "calendar_sizes"}) { calendar_sizes(os); }
    }
    {
        std::ofstream os("./htm/card_default.html");
        HT_USE(layout, {.name = "card_default"}) { card_default(os); }
    }
    {
        std::ofstream os("./htm/card_with_image.html");
        HT_USE(layout, {.name = "card_with_image"}) { card_with_image(os); }
    }
    {
        std::ofstream os("./htm/carousel_default.html");
        HT_USE(layout, {.name = "carousel_default"}) { carousel_default(os); }
    }
    {
        std::ofstream os("./htm/chart_area_linear.html");
        HT_USE(layout, {.name = "chart_area_linear"}) { chart_area_linear(os); }
    }
    {
        std::ofstream os("./htm/chart_area_stacked.html");
        HT_USE(layout, {.name = "chart_area_stacked"}) { chart_area_stacked(os); }
    }
    {
        std::ofstream os("./htm/chart_area_step.html");
        HT_USE(layout, {.name = "chart_area_step"}) { chart_area_step(os); }
    }
    {
        std::ofstream os("./htm/chart_area.html");
        HT_USE(layout, {.name = "chart_area"}) { chart_area(os); }
    }
    {
        std::ofstream os("./htm/chart_bar_horizontal.html");
        HT_USE(layout, {.name = "chart_bar_horizontal"}) { chart_bar_horizontal(os); }
    }
    {
        std::ofstream os("./htm/chart_bar_multiple.html");
        HT_USE(layout, {.name = "chart_bar_multiple"}) { chart_bar_multiple(os); }
    }
    {
        std::ofstream os("./htm/chart_bar_negative.html");
        HT_USE(layout, {.name = "chart_bar_negative"}) { chart_bar_negative(os); }
    }
    {
        std::ofstream os("./htm/chart_bar_stacked.html");
        HT_USE(layout, {.name = "chart_bar_stacked"}) { chart_bar_stacked(os); }
    }
    {
        std::ofstream os("./htm/chart_default.html");
        HT_USE(layout, {.name = "chart_default"}) { chart_default(os); }
    }
    {
        std::ofstream os("./htm/chart_doughnut_legend.html");
        HT_USE(layout, {.name = "chart_doughnut_legend"}) { chart_doughnut_legend(os); }
    }
    {
        std::ofstream os("./htm/chart_doughnut_stacked.html");
        HT_USE(layout, {.name = "chart_doughnut_stacked"}) { chart_doughnut_stacked(os); }
    }
    {
        std::ofstream os("./htm/chart_doughnut.html");
        HT_USE(layout, {.name = "chart_doughnut"}) { chart_doughnut(os); }
    }
    {
        std::ofstream os("./htm/chart_line_linear.html");
        HT_USE(layout, {.name = "chart_line_linear"}) { chart_line_linear(os); }
    }
    {
        std::ofstream os("./htm/chart_line_multiple.html");
        HT_USE(layout, {.name = "chart_line_multiple"}) { chart_line_multiple(os); }
    }
    {
        std::ofstream os("./htm/chart_line_step.html");
        HT_USE(layout, {.name = "chart_line_step"}) { chart_line_step(os); }
    }
    {
        std::ofstream os("./htm/chart_line.html");
        HT_USE(layout, {.name = "chart_line"}) { chart_line(os); }
    }
    {
        std::ofstream os("./htm/chart_pie_legend.html");
        HT_USE(layout, {.name = "chart_pie_legend"}) { chart_pie_legend(os); }
    }
    {
        std::ofstream os("./htm/chart_pie_stacked.html");
        HT_USE(layout, {.name = "chart_pie_stacked"}) { chart_pie_stacked(os); }
    }
    {
        std::ofstream os("./htm/chart_pie.html");
        HT_USE(layout, {.name = "chart_pie"}) { chart_pie(os); }
    }
    {
        std::ofstream os("./htm/chart_radar_stacked.html");
        HT_USE(layout, {.name = "chart_radar_stacked"}) { chart_radar_stacked(os); }
    }
    {
        std::ofstream os("./htm/chart_radar.html");
        HT_USE(layout, {.name = "chart_radar"}) { chart_radar(os); }
    }
    {
        std::ofstream os("./htm/chart_raw_config.html");
        HT_USE(layout, {.name = "chart_raw_config"}) { chart_raw_config(os); }
    }
    {
        std::ofstream os("./htm/checkbox_default.html");
        HT_USE(layout, {.name = "checkbox_default"}) { checkbox_default(os); }
    }
    {
        std::ofstream os("./htm/checkbox_form.html");
        HT_USE(layout, {.name = "checkbox_form"}) { checkbox_form(os); }
    }
    {
        std::ofstream os("./htm/checkbox_indeterminate.html");
        HT_USE(layout, {.name = "checkbox_indeterminate"}) { checkbox_indeterminate(os); }
    }
    {
        std::ofstream os("./htm/collapsible_default.html");
        HT_USE(layout, {.name = "collapsible_default"}) { collapsible_default(os); }
    }
    {
        std::ofstream os("./htm/copybutton_default.html");
        HT_USE(layout, {.name = "copybutton_default"}) { copybutton_default(os); }
    }
    {
        std::ofstream os("./htm/copybutton_with_input.html");
        HT_USE(layout, {.name = "copybutton_with_input"}) { copybutton_with_input(os); }
    }
    {
        std::ofstream os("./htm/date_picker_custom_placeholder.html");
        HT_USE(layout, {.name = "date_picker_custom_placeholder"}) { date_picker_custom_placeholder(os); }
    }
    {
        std::ofstream os("./htm/date_picker_default.html");
        HT_USE(layout, {.name = "date_picker_default"}) { date_picker_default(os); }
    }
    {
        std::ofstream os("./htm/date_picker_disabled.html");
        HT_USE(layout, {.name = "date_picker_disabled"}) { date_picker_disabled(os); }
    }
    {
        std::ofstream os("./htm/date_picker_form.html");
        HT_USE(layout, {.name = "date_picker_form"}) { date_picker_form(os); }
    }
    {
        std::ofstream os("./htm/date_picker_formats.html");
        HT_USE(layout, {.name = "date_picker_formats"}) { date_picker_formats(os); }
    }
    {
        std::ofstream os("./htm/date_picker_selected_date.html");
        HT_USE(layout, {.name = "date_picker_selected_date"}) { date_picker_selected_date(os); }
    }
    {
        std::ofstream os("./htm/date_picker_with_label.html");
        HT_USE(layout, {.name = "date_picker_with_label"}) { date_picker_with_label(os); }
    }
    {
        std::ofstream os("./htm/date_picker_with_time.html");
        HT_USE(layout, {.name = "date_picker_with_time"}) { date_picker_with_time(os); }
    }
    {
        std::ofstream os("./htm/dialog_default.html");
        HT_USE(layout, {.name = "dialog_default"}) { dialog_default(os); }
    }
    {
        std::ofstream os("./htm/dialog_external_trigger.html");
        HT_USE(layout, {.name = "dialog_external_trigger"}) { dialog_external_trigger(os); }
    }
    {
        std::ofstream os("./htm/dialog_no_modal.html");
        HT_USE(layout, {.name = "dialog_no_modal"}) { dialog_no_modal(os); }
    }
    {
        std::ofstream os("./htm/dropdown_default.html");
        HT_USE(layout, {.name = "dropdown_default"}) { dropdown_default(os); }
    }
    {
        std::ofstream os("./htm/icon_colored.html");
        HT_USE(layout, {.name = "icon_colored"}) { icon_colored(os); }
    }
    {
        std::ofstream os("./htm/icon_default.html");
        HT_USE(layout, {.name = "icon_default"}) { icon_default(os); }
    }
    {
        std::ofstream os("./htm/icon_filled.html");
        HT_USE(layout, {.name = "icon_filled"}) { icon_filled(os); }
    }
    {
        std::ofstream os("./htm/icon_sizes.html");
        HT_USE(layout, {.name = "icon_sizes"}) { icon_sizes(os); }
    }
    {
        std::ofstream os("./htm/input_default.html");
        HT_USE(layout, {.name = "input_default"}) { input_default(os); }
    }
    {
        std::ofstream os("./htm/input_disabled.html");
        HT_USE(layout, {.name = "input_disabled"}) { input_disabled(os); }
    }
    {
        std::ofstream os("./htm/input_file.html");
        HT_USE(layout, {.name = "input_file"}) { input_file(os); }
    }
    {
        std::ofstream os("./htm/input_form.html");
        HT_USE(layout, {.name = "input_form"}) { input_form(os); }
    }
    {
        std::ofstream os("./htm/input_otp_custom_length.html");
        HT_USE(layout, {.name = "input_otp_custom_length"}) { input_otp_custom_length(os); }
    }
    {
        std::ofstream os("./htm/input_otp_custom_styling.html");
        HT_USE(layout, {.name = "input_otp_custom_styling"}) { input_otp_custom_styling(os); }
    }
    {
        std::ofstream os("./htm/input_otp_default.html");
        HT_USE(layout, {.name = "input_otp_default"}) { input_otp_default(os); }
    }
    {
        std::ofstream os("./htm/input_otp_form.html");
        HT_USE(layout, {.name = "input_otp_form"}) { input_otp_form(os); }
    }
    {
        std::ofstream os("./htm/input_otp_password_type.html");
        HT_USE(layout, {.name = "input_otp_password_type"}) { input_otp_password_type(os); }
    }
    {
        std::ofstream os("./htm/input_otp_placeholder.html");
        HT_USE(layout, {.name = "input_otp_placeholder"}) { input_otp_placeholder(os); }
    }
    {
        std::ofstream os("./htm/input_otp_with_label.html");
        HT_USE(layout, {.name = "input_otp_with_label"}) { input_otp_with_label(os); }
    }
    {
        std::ofstream os("./htm/input_password.html");
        HT_USE(layout, {.name = "input_password"}) { input_password(os); }
    }
    {
        std::ofstream os("./htm/input_time_default.html");
        HT_USE(layout, {.name = "input_time_default"}) { input_time_default(os); }
    }
    {
        std::ofstream os("./htm/input_time_styled.html");
        HT_USE(layout, {.name = "input_time_styled"}) { input_time_styled(os); }
    }
    {
        std::ofstream os("./htm/input_with_label.html");
        HT_USE(layout, {.name = "input_with_label"}) { input_with_label(os); }
    }
    {
        std::ofstream os("./htm/pagination_default.html");
        HT_USE(layout, {.name = "pagination_default"}) { pagination_default(os); }
    }
    {
        std::ofstream os("./htm/pagination_with_helper.html");
        HT_USE(layout, {.name = "pagination_with_helper"}) { pagination_with_helper(os); }
    }
    {
        std::ofstream os("./htm/popover_default.html");
        HT_USE(layout, {.name = "popover_default"}) { popover_default(os); }
    }
    {
        std::ofstream os("./htm/popover_positions.html");
        HT_USE(layout, {.name = "popover_positions"}) { popover_positions(os); }
    }
    {
        std::ofstream os("./htm/popover_triggers.html");
        HT_USE(layout, {.name = "popover_triggers"}) { popover_triggers(os); }
    }
    {
        std::ofstream os("./htm/progress_default.html");
        HT_USE(layout, {.name = "progress_default"}) { progress_default(os); }
    }
    {
        std::ofstream os("./htm/progress_sizes.html");
        HT_USE(layout, {.name = "progress_sizes"}) { progress_sizes(os); }
    }
    {
        std::ofstream os("./htm/progress_variants.html");
        HT_USE(layout, {.name = "progress_variants"}) { progress_variants(os); }
    }
    {
        std::ofstream os("./htm/radio_default.html");
        HT_USE(layout, {.name = "radio_default"}) { radio_default(os); }
    }
    {
        std::ofstream os("./htm/radio_form.html");
        HT_USE(layout, {.name = "radio_form"}) { radio_form(os); }
    }
    {
        std::ofstream os("./htm/rating_default.html");
        HT_USE(layout, {.name = "rating_default"}) { rating_default(os); }
    }
    {
        std::ofstream os("./htm/rating_form.html");
        HT_USE(layout, {.name = "rating_form"}) { rating_form(os); }
    }
    {
        std::ofstream os("./htm/rating_max_values.html");
        HT_USE(layout, {.name = "rating_max_values"}) { rating_max_values(os); }
    }
    {
        std::ofstream os("./htm/rating_precision.html");
        HT_USE(layout, {.name = "rating_precision"}) { rating_precision(os); }
    }
    {
        std::ofstream os("./htm/rating_styles.html");
        HT_USE(layout, {.name = "rating_styles"}) { rating_styles(os); }
    }
    {
        std::ofstream os("./htm/rating_with_label.html");
        HT_USE(layout, {.name = "rating_with_label"}) { rating_with_label(os); }
    }
    {
        std::ofstream os("./htm/select_box_default.html");
        HT_USE(layout, {.name = "select_box_default"}) { select_box_default(os); }
    }
    {
        std::ofstream os("./htm/select_box_disabled.html");
        HT_USE(layout, {.name = "select_box_disabled"}) { select_box_disabled(os); }
    }
    {
        std::ofstream os("./htm/select_box_form.html");
        HT_USE(layout, {.name = "select_box_form"}) { select_box_form(os); }
    }
    {
        std::ofstream os("./htm/select_box_multiple.html");
        HT_USE(layout, {.name = "select_box_multiple"}) { select_box_multiple(os); }
    }
    {
        std::ofstream os("./htm/select_box_no_search.html");
        HT_USE(layout, {.name = "select_box_no_search"}) { select_box_no_search(os); }
    }
    {
        std::ofstream os("./htm/select_box_pills.html");
        HT_USE(layout, {.name = "select_box_pills"}) { select_box_pills(os); }
    }
    {
        std::ofstream os("./htm/select_box_with_label.html");
        HT_USE(layout, {.name = "select_box_with_label"}) { select_box_with_label(os); }
    }
    {
        std::ofstream os("./htm/separator_decorated.html");
        HT_USE(layout, {.name = "separator_decorated"}) { separator_decorated(os); }
    }
    {
        std::ofstream os("./htm/separator_default.html");
        HT_USE(layout, {.name = "separator_default"}) { separator_default(os); }
    }
    {
        std::ofstream os("./htm/separator_label.html");
        HT_USE(layout, {.name = "separator_label"}) { separator_label(os); }
    }
    {
        std::ofstream os("./htm/separator_vertical.html");
        HT_USE(layout, {.name = "separator_vertical"}) { separator_vertical(os); }
    }
    {
        std::ofstream os("./htm/sheet_default.html");
        HT_USE(layout, {.name = "sheet_default"}) { sheet_default(os); }
    }
    {
        std::ofstream os("./htm/sheet_external_trigger.html");
        HT_USE(layout, {.name = "sheet_external_trigger"}) { sheet_external_trigger(os); }
    }
    {
        std::ofstream os("./htm/sheet_sides.html");
        HT_USE(layout, {.name = "sheet_sides"}) { sheet_sides(os); }
    }
    {
        std::ofstream os("./htm/sidebar_default.html");
        HT_USE(layout, {.name = "sidebar_default"}) { sidebar_default(os); }
    }
    {
        std::ofstream os("./htm/skeleton_card.html");
        HT_USE(layout, {.name = "skeleton_card"}) { skeleton_card(os); }
    }
    {
        std::ofstream os("./htm/skeleton_dashboard.html");
        HT_USE(layout, {.name = "skeleton_dashboard"}) { skeleton_dashboard(os); }
    }
    {
        std::ofstream os("./htm/skeleton_default.html");
        HT_USE(layout, {.name = "skeleton_default"}) { skeleton_default(os); }
    }
    {
        std::ofstream os("./htm/skeleton_profile.html");
        HT_USE(layout, {.name = "skeleton_profile"}) { skeleton_profile(os); }
    }
    {
        std::ofstream os("./htm/slider_default.html");
        HT_USE(layout, {.name = "slider_default"}) { slider_default(os); }
    }
    {
        std::ofstream os("./htm/slider_disabled.html");
        HT_USE(layout, {.name = "slider_disabled"}) { slider_disabled(os); }
    }
    {
        std::ofstream os("./htm/slider_external_value.html");
        HT_USE(layout, {.name = "slider_external_value"}) { slider_external_value(os); }
    }
    {
        std::ofstream os("./htm/slider_range.html");
        HT_USE(layout, {.name = "slider_range"}) { slider_range(os); }
    }
    {
        std::ofstream os("./htm/slider_steps.html");
        HT_USE(layout, {.name = "slider_steps"}) { slider_steps(os); }
    }
    {
        std::ofstream os("./htm/slider_value.html");
        HT_USE(layout, {.name = "slider_value"}) { slider_value(os); }
    }
    {
        std::ofstream os("./htm/switch_default.html");
        HT_USE(layout, {.name = "switch_default"}) { switch_default(os); }
    }
    {
        std::ofstream os("./htm/switch_form.html");
        HT_USE(layout, {.name = "switch_form"}) { switch_form(os); }
    }
    {
        std::ofstream os("./htm/table_.html");
        HT_USE(layout, {.name = "table_"}) { table_(os); }
    }
    {
        std::ofstream os("./htm/account_tab.html");
        HT_USE(layout, {.name = "account_tab"}) { account_tab(os); }
    }
    {
        std::ofstream os("./htm/password_tab.html");
        HT_USE(layout, {.name = "password_tab"}) { password_tab(os); }
    }
    {
        std::ofstream os("./htm/tabs_default.html");
        HT_USE(layout, {.name = "tabs_default"}) { tabs_default(os); }
    }
    {
        std::ofstream os("./htm/tagsinput_default.html");
        HT_USE(layout, {.name = "tagsinput_default"}) { tagsinput_default(os); }
    }
    {
        std::ofstream os("./htm/tagsinput_disabled.html");
        HT_USE(layout, {.name = "tagsinput_disabled"}) { tagsinput_disabled(os); }
    }
    {
        std::ofstream os("./htm/tagsinput_form.html");
        HT_USE(layout, {.name = "tagsinput_form"}) { tagsinput_form(os); }
    }
    {
        std::ofstream os("./htm/tagsinput_suggestions.html");
        HT_USE(layout, {.name = "tagsinput_suggestions"}) { tagsinput_suggestions(os); }
    }
    {
        std::ofstream os("./htm/tagsinput_with_label.html");
        HT_USE(layout, {.name = "tagsinput_with_label"}) { tagsinput_with_label(os); }
    }
    {
        std::ofstream os("./htm/textarea_auto_resize.html");
        HT_USE(layout, {.name = "textarea_auto_resize"}) { textarea_auto_resize(os); }
    }
    {
        std::ofstream os("./htm/textarea_custom_rows.html");
        HT_USE(layout, {.name = "textarea_custom_rows"}) { textarea_custom_rows(os); }
    }
    {
        std::ofstream os("./htm/textarea_default.html");
        HT_USE(layout, {.name = "textarea_default"}) { textarea_default(os); }
    }
    {
        std::ofstream os("./htm/textarea_disabled.html");
        HT_USE(layout, {.name = "textarea_disabled"}) { textarea_disabled(os); }
    }
    {
        std::ofstream os("./htm/textarea_form.html");
        HT_USE(layout, {.name = "textarea_form"}) { textarea_form(os); }
    }
    {
        std::ofstream os("./htm/textarea_with_label.html");
        HT_USE(layout, {.name = "textarea_with_label"}) { textarea_with_label(os); }
    }
    {
        std::ofstream os("./htm/time_picker_12hour.html");
        HT_USE(layout, {.name = "time_picker_12hour"}) { time_picker_12hour(os); }
    }
    {
        std::ofstream os("./htm/time_picker_custom_placeholder.html");
        HT_USE(layout, {.name = "time_picker_custom_placeholder"}) { time_picker_custom_placeholder(os); }
    }
    {
        std::ofstream os("./htm/time_picker_default.html");
        HT_USE(layout, {.name = "time_picker_default"}) { time_picker_default(os); }
    }
    {
        std::ofstream os("./htm/time_picker_form.html");
        HT_USE(layout, {.name = "time_picker_form"}) { time_picker_form(os); }
    }
    {
        std::ofstream os("./htm/time_picker_label.html");
        HT_USE(layout, {.name = "time_picker_label"}) { time_picker_label(os); }
    }
    {
        std::ofstream os("./htm/time_picker_min_max.html");
        HT_USE(layout, {.name = "time_picker_min_max"}) { time_picker_min_max(os); }
    }
    {
        std::ofstream os("./htm/time_picker_selected_time.html");
        HT_USE(layout, {.name = "time_picker_selected_time"}) { time_picker_selected_time(os); }
    }
    {
        std::ofstream os("./htm/time_picker_step.html");
        HT_USE(layout, {.name = "time_picker_step"}) { time_picker_step(os); }
    }
    {
        std::ofstream os("./htm/toast_default.html");
        HT_USE(layout, {.name = "toast_default"}) { toast_default(os); }
    }
    {
        std::ofstream os("./htm/toast_playground.html");
        HT_USE(layout, {.name = "toast_playground"}) { toast_playground(os); }
    }
    {
        std::ofstream os("./htm/tooltip_default.html");
        HT_USE(layout, {.name = "tooltip_default"}) { tooltip_default(os); }
    }
    {
        std::ofstream os("./htm/tooltip_positions.html");
        HT_USE(layout, {.name = "tooltip_positions"}) { tooltip_positions(os); }
    }
}
