#include "./print.h"

void print_bang_diem_TK(WINDOW * current_window, Table &current_table) {
  DanhSachSinhVien * current_dssv = database.get_current_dssv();
  
  LinkedList<char *> list_ma_mh;
  // Get list MonHoc
  Node<SinhVien> * current_sv = current_dssv->p_head_;
  while (current_sv != NULL) {
    // ......
    Node<int> * curr_malop = current_sv->get_data().DS_LOPTC->p_head_;
    while (curr_malop != NULL) {
      LopTC * curr_ltc = database.dsltc.node[database.dsltc.search(curr_malop->get_data())];
      if (!list_ma_mh.is_exist(curr_ltc->maMH))
        list_ma_mh.push_back(curr_ltc->maMH);
      
      curr_malop = curr_malop->get_next();
    }
    current_sv = current_sv->get_next();
  }
  
  // Print
  
  /*************** Print title, fields ******************/
  box(current_window, 0, 0);
  int current_xcoord = 0;
  // Print title
  mvwprintw(current_window, 1, (current_table.get_width() - strlen(current_table.get_title())) / 2, current_table.get_title());
  mvwhline(current_window, 2, 1, 0, current_table.get_width() - 2);
  
  // Print fields
  int average_width = current_table.get_width() / (list_ma_mh.count() + 4);
  char * static_fields[] = {
    "STT",
    "MA SV",
    "HO TEN",
  };
  for (int i = 0; i < 3; i++) {
    mvwprintw(current_window, 3, current_xcoord + 1, static_fields[i]);
    current_xcoord += average_width + 1;

    mvwaddch(current_window, 2, current_xcoord, ACS_TTEE);
    mvwaddch(current_window, 3, current_xcoord, ACS_VLINE);
    mvwaddch(current_window, 4, current_xcoord, ACS_PLUS);
  }

  Node<char *> * current_ma_mh = list_ma_mh.p_head_;
  while (current_ma_mh != NULL) {
    mvwprintw(current_window, 3, current_xcoord + 1, current_ma_mh->get_data());
    current_xcoord += average_width + 1;

    mvwaddch(current_window, 2, current_xcoord, ACS_TTEE);
    mvwaddch(current_window, 3, current_xcoord, ACS_VLINE);
    mvwaddch(current_window, 4, current_xcoord, ACS_PLUS);

    current_ma_mh = current_ma_mh->get_next();
  }
  mvwprintw(current_window, 3, current_xcoord + 1, "Diem TB");
  mvwhline(current_window, 4, 1, 0, current_table.get_width() - 2);
  
  // Print data
  int current_ycoord = 5;
  while (current_sv != NULL) {
    

    current_ycoord += 2;
    current_sv = current_sv->get_next();
  }
  wrefresh(current_window);
}
