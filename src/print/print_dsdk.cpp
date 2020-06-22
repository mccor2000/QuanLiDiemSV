#include "./print.h"

void print_dsdk(WINDOW * current_window, Table &current_table) {
  box(current_window, 0, 0);

  // Print title
  mvwprintw(current_window, 1, (current_table.width - strlen(current_table.title)) / 2, current_table.title);
 
  // Print fields
  char * DSDK_FIELDS[] = {
    (char *)"STT",
    (char *)"MASV",
    (char *)"HO",
    (char *)"TEN",
    (char *)"DIEM",
  };
  current_table.fields_len = 5;
  current_table.average_width = current_table.width / current_table.fields_len;
  current_table.draw_column(3, DSDK_FIELDS);
  
  // Print data
  int current_yCoord = 5;
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  
  int i = current_table.start_index;

  Node<SinhVienDK> * curr_node = database.get_current_dsdk()->get_node_by_index(current_table.start_index);
  while (curr_node != NULL && i < current_table.length) {
    if (i > current_table.end_index) break;

    // Get SV info
    SinhVienDK curr_svdk = curr_node->get_data();
  
    database.set_current_sv(curr_svdk.get_MASV());
    SinhVien curr_sv;
    if (database.get_current_sv() != NULL)
      curr_sv = database.get_current_sv()->get_data();

    // Print info
    current_table.draw_column_seperator(current_yCoord);

    if (current_table.current_index == i)
      wattron(current_window, A_BOLD | COLOR_PAIR(1));

    mvwprintw(current_window, current_yCoord, 1 + (current_table.average_width + 1)*0, std::to_string(i+1).c_str());
    mvwprintw(current_window, current_yCoord, 1 + (current_table.average_width + 1)*1, curr_svdk.get_MASV());
    mvwprintw(current_window, current_yCoord, 1 + (current_table.average_width + 1)*2, curr_sv.get_HO());
    mvwprintw(current_window, current_yCoord, 1 + (current_table.average_width + 1)*3, curr_sv.get_TEN());

    std::string diem = std::to_string(curr_svdk.get_DIEM());
    diem.resize(4);
    mvwprintw(current_window, current_yCoord, 1 + (current_table.average_width + 1)*4, (curr_svdk.get_DIEM() == 0) ? "" : diem.c_str());

    if (current_table.current_index == i)
      wattroff(current_window, A_BOLD | COLOR_PAIR(1));

    current_yCoord += 2;
    curr_node = curr_node->get_next();
    i++;
  }
  wrefresh(current_window);
}
