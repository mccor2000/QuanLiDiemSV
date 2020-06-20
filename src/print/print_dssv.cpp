#include "./print.h"

void print_dssv(WINDOW * current_window, Table &current_table) {
  box(current_window, 0, 0);

  // Print title
  mvwprintw(current_window, 1, (current_table.width - strlen(current_table.title)) / 2, current_table.title);
 
  // Print fields
  char * DSSV_FIELDS[] = {
    (char *)"MA SV",
    (char *)"HO",
    (char *)"TEN",
    (char *)"GIOI TINH",
    (char *)"SDT",
  };
  current_table.fields_len = 5;
  current_table.average_width = current_table.width / current_table.fields_len;
  current_table.draw_column(3, DSSV_FIELDS);
  
  // Print data
  int current_yCoord = 5;
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  
  int i = current_table.start_index;

  Node<SinhVien> * curr_node = database.get_current_dssv()->get_node_by_index(current_table.start_index);
  while (curr_node != NULL && i < current_table.length) {
    if (i > current_table.end_index) break;
    current_table.draw_column_seperator(current_yCoord);

    if (current_table.current_index == i)
      wattron(current_window, A_BOLD | COLOR_PAIR(1));

    mvwprintw(current_window, current_yCoord, 1 + (current_table.average_width + 1)*0, curr_node->get_data().get_MASV());
    mvwprintw(current_window, current_yCoord, 1 + (current_table.average_width + 1)*1, curr_node->get_data().get_HO());
    mvwprintw(current_window, current_yCoord, 1 + (current_table.average_width + 1)*2, curr_node->get_data().get_TEN());
    mvwprintw(current_window, current_yCoord, 1 + (current_table.average_width + 1)*3, curr_node->get_data().get_PHAI() == 1 ? "NAM" : "NU");
    mvwprintw(current_window, current_yCoord, 1 + (current_table.average_width + 1)*4, curr_node->get_data().get_SDT());
    
    if (current_table.current_index == i)
      wattroff(current_window, A_BOLD | COLOR_PAIR(1));
    
    current_yCoord += 2;
    curr_node = curr_node->get_next();
    i++;
  }
  wrefresh(current_window);
}
