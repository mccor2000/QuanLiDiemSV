#include "print.h"

void print_filtered_dsltc(WINDOW * current_window, Table &current_table) {
  box(current_window, 0, 0);

  // Print title
  mvwprintw(current_window, 1, (current_table.width - strlen(current_table.title)) / 2, current_table.title);

  // Print fields
  char * DSLTC_FIELDS[] = {
    (char *)"Ma LOP",
    (char *)"MA MH",
    (char *)"NIEN KHOA",
    (char *)"HOC KI",
    (char *)"NHOM",
    (char *)"DA DANG KY",
    (char *)"CON LAI",
    (char *)"HUY",
  };
  current_table.fields_len = 8;
  current_table.average_width = current_table.width / current_table.fields_len;
  current_table.draw_column(3, DSLTC_FIELDS);

  // Print data
  int current_yCoord = 5;
  init_pair(1, COLOR_BLUE, COLOR_BLACK);

  for (int i = current_table.start_index; i <= current_table.end_index; i++) {
    if (i >= current_table.length) break;

    // Print column
    LopTC * curr_loptc = database.filtered_dsltc->node[i];

    current_table.draw_column_seperator(current_yCoord);
    if (current_table.current_index == i)
      wattron(current_window, A_BOLD | COLOR_PAIR(1));

    mvwprintw(current_window, current_yCoord, 1 + (1 + current_table.average_width)*0, std::to_string(curr_loptc->malop).c_str());
    mvwprintw(current_window, current_yCoord, 1 + (1 + current_table.average_width)*1, curr_loptc->maMH);
    mvwprintw(current_window, current_yCoord, 1 + (1 + current_table.average_width)*2, curr_loptc->nienkhoa);
    mvwprintw(current_window, current_yCoord, 1 + (1 + current_table.average_width)*3, std::to_string(curr_loptc->hocki).c_str());
    mvwprintw(current_window, current_yCoord, 1 + (1 + current_table.average_width)*4, std::to_string(curr_loptc->nhom).c_str());
    mvwprintw(current_window, current_yCoord, 1 + (1 + current_table.average_width)*5, std::to_string(curr_loptc->dsdk->count()).c_str());
    mvwprintw(current_window, current_yCoord, 1 + (1 + current_table.average_width)*6, std::to_string(curr_loptc->sv_max - curr_loptc->dsdk->count()).c_str());
    mvwprintw(current_window, current_yCoord, 1 + (1 + current_table.average_width)*7, curr_loptc->huylop ? "v" : "");

    if (current_table.current_index == i)
      wattroff(current_window, A_BOLD | COLOR_PAIR(1));

    current_yCoord += 2;
  }
  wrefresh(current_window);
}
