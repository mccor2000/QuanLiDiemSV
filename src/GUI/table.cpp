#include "./table.h"

char * DSLTC_FIELDS[] = { 
  "Ma LOP",
  "MA MH",
  "NIEN KHOA",
  "HOC KI",
  "NHOM",
  "SO SV MIN",
  "SO SV MAX",
  "HUY",
};

char * DSLCQ_FIELDS[] = {
  "MA LOP",
  "SO SV"
};

char * DSMH_FIELDS[] = {
  "MA MH",
  "TEN MH",
  "STCLT",
  "STCTH",
};

char * DSSV_FIELDS[] = {
  "MA SV",
  "HO",
  "TEN",
  "GIOI TINH",
  "SDT",
};

char * DSDK_FIELDS[] = {
  "MA SV",
  "DIEM",
};

Table::Table(WINDOW * win) {
  current_window = win;
  update_form = Form(win);
  getmaxyx(win, height, width);
  
  top_line = 0; 
  page_size = width - 1;
  current_line = 0;
}

// Handle input
void Table::process_input() {
  int bottom_line = page_size - 1;
  
  switch (input) {
    case KEY_UP:
      if (current_line > top_line) 
        current_line--;
      else
        current_line = top_line;  
      break;
   
    case KEY_DOWN:
      if (current_line < bottom_line) 
        current_line++;
      else 
        current_line = bottom_line;
      break;
    
    case 10:
      break;
  }
}

// Draw column seperator
void Table::draw_column_seperator(int yCoord) {
  int current_xCoord = 0;
  mvwhline(current_window, yCoord - 1, 1, 0, width - 2);
  mvwhline(current_window, yCoord + 1, 1, 0, width - 2);
  for (int i = 0; i < len; i++) {
    if (i > 0) {
      mvwaddch(current_window, yCoord - 1, current_xCoord, ACS_TTEE);
      mvwaddch(current_window, yCoord, current_xCoord, ACS_VLINE);
      mvwaddch(current_window, yCoord + 1, current_xCoord, ACS_PLUS);
    }
    current_xCoord += average_width + 1;
  }
  wrefresh(current_window);
}

// Draw the table
void Table::display() {
  box(current_window, 0, 0);

  // Get infos
  char ** fields;
  switch (type) {
    case 1:
      fields = DSLTC_FIELDS;
      len = 8;
      update_form.set_type(1);
      break;
    case 2:
      fields = DSLCQ_FIELDS;
      len = 2;
      update_form.set_type(2);
      break;
    case 3:
      fields = DSMH_FIELDS;
      len = 4;
      update_form.set_type(3);
      break;
    case 4:
      fields = DSSV_FIELDS;
      len = 5;
      update_form.set_type(4);
      break;
    case 5:
      fields = DSDK_FIELDS;
      len = 2;
      update_form.set_type(5);
      break;
  }
  average_width = width / len;
  
  // Print title
  mvwprintw(current_window, 1, (width - strlen(title)) / 2, title);
  
  // Print fields
  draw_column_seperator(3);
  wrefresh(current_window);
}

// Get input
bool Table::get_input() {
  input = getch();
  if (input == 27) return false;
    
  process_input();
  return true;
}

// Print DSLTC
void Table::render_dsltc(DanhSachLopTC dsltc) {
  int length = dsltc.getN();
  int current_yCoord = 5;
  init_pair(1, COLOR_BLUE, COLOR_BLACK);

  for (int i = 0; i < page_size; i++) {
    if (i >= length) break;
    
    // Print column
    draw_column_seperator(current_yCoord);
    if (current_line == i) 
      wattron(current_window, A_BOLD | COLOR_PAIR(1));
    
    LopTC * curr_loptc = dsltc.node[i];
    mvwprintw(current_window, current_yCoord, 1 + (1 + average_width)*0, std::to_string(curr_loptc->malop).c_str());
    mvwprintw(current_window, current_yCoord, 1 + (1 + average_width)*1, curr_loptc->maMH);
    mvwprintw(current_window, current_yCoord, 1 + (1 + average_width)*2, curr_loptc->nienkhoa);
    mvwprintw(current_window, current_yCoord, 1 + (1 + average_width)*3, std::to_string(curr_loptc->hocki).c_str());
    mvwprintw(current_window, current_yCoord, 1 + (1 + average_width)*4, std::to_string(curr_loptc->nhom).c_str());
    mvwprintw(current_window, current_yCoord, 1 + (1 + average_width)*5, std::to_string(curr_loptc->sv_min).c_str());
    mvwprintw(current_window, current_yCoord, 1 + (1 + average_width)*6, std::to_string(curr_loptc->sv_max).c_str());

    if (current_line == i) 
      wattroff(current_window, A_BOLD | COLOR_PAIR(1));
    
    current_yCoord += 2;
  }
  wrefresh(current_window);
}

// Print DSLCQ
void Table::render_dslcq(DanhSachLopCQ dslcq) {
  int current_yCoord = 5;
  
  Node<LopCQ> * curr_node = dslcq.head();
  while (curr_node != NULL) {
    LopCQ curr_lopcq = curr_node->get_data();
    mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*0, curr_lopcq.MALOP);
    curr_node = curr_node->get_next();

    mvwhline(current_window, current_yCoord + 1, 1, 0, width - 2);
    current_yCoord += 2;
  }
  wrefresh(current_window);
}

// Print DSMH
void Table::render_dsmh(DanhSachMonHoc dsmh) {
  int length = dsmh.length;
  
  int current_yCoord = 5;
  int i = 0;
  dsmh.enumerate([i, current_yCoord, this](MonHoc x) mutable{
    mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*0, x.MAMH);
    mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*1, x.TENMH);
    mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*2, std::to_string(x.STCLT).c_str());
    mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*3, std::to_string(x.STCLT).c_str());
    
    i++;
    mvwhline(current_window, current_yCoord + 1, 1, 0, width - 2);
    current_yCoord += 2;
  });
  wrefresh(current_window);
}

// Print DSSV
void Table::render_dssv(DanhSachSinhVien dssv) {
  int current_yCoord = 5;
 
  Node<SinhVien> * curr_node = dssv.head();
  while (curr_node != NULL) {
    SinhVien curr_sv = curr_node->get_data();
    mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*0, curr_sv.get_MASV());
    mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*1, curr_sv.get_HO());
    mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*2, curr_sv.get_TEN());
    mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*3, (char *)curr_sv.get_PHAI());
    mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*4, curr_sv.get_SDT());
    curr_node = curr_node->get_next();

    mvwhline(current_window, current_yCoord + 1, 1, 0, width - 2);
    current_yCoord += 2;
  }
  wrefresh(current_window);
}

// Print DSDK
void Table::render_dsdk(DanhSachSinhVienDK dsdk) {
  int current_yCoord = 5;
  
  Node<SinhVienDK> * curr_node = dsdk.head();
  while (curr_node != NULL) {
    SinhVienDK curr_svdk = curr_node->get_data();
    mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*0, curr_svdk.get_MASV());
    mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*1, std::to_string(curr_svdk.get_DIEM()).c_str());
    curr_node = curr_node->get_next();

    mvwhline(current_window, current_yCoord + 1, 1, 0, width - 2);
    current_yCoord += 2;
  }
  wrefresh(current_window);
}

