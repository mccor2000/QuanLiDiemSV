#include "./print.h"

void print_dsmh(WINDOW * current_window, Table &current_table) {
  box(current_window, 0, 0);

  // Print title
  mvwprintw(current_window, 1, (current_table.width - strlen(current_table.title)) / 2, current_table.title);
 
  // Print fields
  char * DSMH_FIELDS[] = {
    (char *)"MA MH",
    (char *)"TEN MH",
    (char *)"STCLT",
    (char *)"STCTH",
  };
  current_table.fields_len = 4;
  current_table.average_width = current_table.width / current_table.fields_len;
  current_table.draw_column(3, DSMH_FIELDS);

  // Print data
  int current_yCoord = 5;
  int i = 0;
  init_pair(1, COLOR_BLUE, COLOR_BLACK);

  database.dsmh.enumerate([&i, &current_yCoord, &current_table, &current_window](MonHoc x) mutable {
    if (i > current_table.length) return;
    if (i >= current_table.start_index && i <= current_table.end_index) {
      current_table.draw_column_seperator(current_yCoord);
      if (current_table.current_index == i)
        wattron(current_window, A_BOLD | COLOR_PAIR(1));

      mvwprintw(current_window, current_yCoord, 1 + (current_table.average_width + 1)*0, x.MAMH);
      mvwprintw(current_window, current_yCoord, 1 + (current_table.average_width + 1)*1, x.TENMH);
      mvwprintw(current_window, current_yCoord, 1 + (current_table.average_width + 1)*2, std::to_string(x.STCLT).c_str());
      mvwprintw(current_window, current_yCoord, 1 + (current_table.average_width + 1)*3, std::to_string(x.STCTH).c_str());

      if (current_table.current_index == i)
        wattroff(current_window, A_BOLD | COLOR_PAIR(1));
    
      current_yCoord += 2;
    }
    i++;
  });
  wrefresh(current_window);
}
