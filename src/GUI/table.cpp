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
  "STT",
  "MASV",
  "HO",
  "TEN",
  "DIEM",
};

char * DSDK_NHAP_DIEM_FIELDS[] = {
  "MASV",
  "DIEM",
};

Table::Table(WINDOW * win) {
  current_window = win;
  getmaxyx(win, height, width);

  length = 0;
  start_index = 0;
  end_index = (height - 5) / 2 - 1;
  current_index = 0;
  is_picked = false;
}

// Draw column seperator
void Table::draw_column_seperator(int ycoord) {
  int current_xcoord = 0;
  mvwhline(current_window, ycoord - 1, 1, 0, width - 2);
  mvwhline(current_window, ycoord + 1, 1, 0, width - 2);
  for (int i = 0; i < fields_len; i++) {
    if (i > 0) {
      mvwaddch(current_window, ycoord - 1, current_xcoord, ACS_TTEE);
      mvwaddch(current_window, ycoord, current_xcoord, ACS_VLINE);
      mvwaddch(current_window, ycoord + 1, current_xcoord, ACS_PLUS);
    }
    current_xcoord += average_width + 1;
  }
  wrefresh(current_window);
}

void Table::draw_column(int ycoord, char ** data) {
  int current_xcoord = 0;
  mvwhline(current_window, ycoord - 1, 1, 0, width - 2);
  mvwhline(current_window, ycoord + 1, 1, 0, width - 2);

  for (int i = 0; i < fields_len; i++) {
    if (i > 0) {
      mvwaddch(current_window, ycoord - 1, current_xcoord, ACS_TTEE);
      mvwaddch(current_window, ycoord, current_xcoord, ACS_VLINE);
      mvwaddch(current_window, ycoord + 1, current_xcoord, ACS_PLUS);
    }
    mvwprintw(current_window, ycoord, current_xcoord + 1, data[i]);
    current_xcoord += average_width + 1;
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
      fields_len = 8;
      break;
    case 2:
      fields = DSLCQ_FIELDS;
      fields_len = 2;
      break;
    case 3:
      fields = DSMH_FIELDS;
      fields_len = 4;
      break;
    case 4:
      fields = DSSV_FIELDS;
      fields_len = 5;
      break;
    case 5:
      fields = DSDK_FIELDS;
      fields_len = 5;
      break;
    case 6:
      fields = DSDK_NHAP_DIEM_FIELDS;
      fields_len = 2;
  }
  average_width = width / fields_len;
  
  // Print title
  mvwprintw(current_window, 1, (width - strlen(title)) / 2, title);
 
  // Print fields
  draw_column(3, fields);
  wrefresh(current_window);
}

// Get input
bool Table::get_input() {
  input = getch();
    
  switch (input) {
    case KEY_UP:
      if (current_index > start_index) {
        current_index--;
      } else if (start_index > 0) {
        start_index --;
        end_index --;
        current_index = start_index;  
      }
      break;
   
    case KEY_DOWN:
      if (current_index < end_index) { 
        current_index ++;
      } else if (end_index < length) {
        start_index ++;
        end_index ++;
        current_index = end_index;
      }
      break;

    case 27:
    case KEY_LEFT:
      return false;
   
    case 10:
      is_picked = true;
      return false;
  }

  return true;
}

// Print DSLTC
void Table::render_dsltc(DanhSachLopTC dsltc) {
  length = dsltc.getN();
  int current_yCoord = 5;
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  
  for (int i = start_index; i <= end_index; i++) {
    if (i >= length) break;
    
    // Print column
    draw_column_seperator(current_yCoord);
    if (current_index == i) 
      wattron(current_window, A_BOLD | COLOR_PAIR(1));
    
    LopTC * curr_loptc = dsltc.node[i];
    mvwprintw(current_window, current_yCoord, 1 + (1 + average_width)*0, std::to_string(curr_loptc->malop).c_str());
    mvwprintw(current_window, current_yCoord, 1 + (1 + average_width)*1, curr_loptc->maMH);
    mvwprintw(current_window, current_yCoord, 1 + (1 + average_width)*2, curr_loptc->nienkhoa);
    mvwprintw(current_window, current_yCoord, 1 + (1 + average_width)*3, std::to_string(curr_loptc->hocki).c_str());
    mvwprintw(current_window, current_yCoord, 1 + (1 + average_width)*4, std::to_string(curr_loptc->nhom).c_str());
    mvwprintw(current_window, current_yCoord, 1 + (1 + average_width)*5, std::to_string(curr_loptc->sv_min).c_str());
    mvwprintw(current_window, current_yCoord, 1 + (1 + average_width)*6, std::to_string(curr_loptc->sv_max).c_str());

    if (current_index == i) 
      wattroff(current_window, A_BOLD | COLOR_PAIR(1));
    
    current_yCoord += 2;
  }
  wrefresh(current_window);
}

// Print DSLCQ
void Table::render_dslcq(DanhSachLopCQ dslcq) {
  int current_yCoord = 5;
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  
  int i = start_index;
  length = dslcq.count();
  if (length == 0) return;

  Node<LopCQ> * curr_node = dslcq.get_node_by_index(start_index);
  while (curr_node != NULL && i < length) {
    if (i > end_index) break;

    draw_column_seperator(current_yCoord);
    LopCQ curr_lopcq = curr_node->get_data();

    if (current_index == i)
      wattron(current_window, A_BOLD | COLOR_PAIR(1));

    // mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*0, curr_lopcq.MALOP);
    // mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*1, std::to_string(curr_lopcq.DSSV->count()).c_str());
    if (current_index == i)
      wattroff(current_window, A_BOLD | COLOR_PAIR(1));

    current_yCoord += 2;
    curr_node = curr_node->get_next();
    i++;
  }
  wrefresh(current_window);
}

// Print DSMH
void Table::render_dsmh(DanhSachMonHoc dsmh) {
  length = dsmh.length;
  int current_yCoord = 5;
  int i = 0;
  init_pair(1, COLOR_BLUE, COLOR_BLACK);

  dsmh.enumerate([i, current_yCoord, this](MonHoc x) mutable {
    if (i >= start_index && i <= end_index) {
      if (i >= length) return;
      draw_column_seperator(current_yCoord);
      if (current_index == i)
        wattron(current_window, A_BOLD | COLOR_PAIR(1));

      mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*0, x.MAMH);
      mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*1, x.TENMH);
      mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*2, std::to_string(x.STCLT).c_str());
      mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*3, std::to_string(x.STCLT).c_str());

      if (current_index == i)
        wattroff(current_window, A_BOLD | COLOR_PAIR(1));
    
      current_yCoord += 2;
    }
    i++;
  });
  wrefresh(current_window);
}

// Print DSSV
void Table::render_dssv(DanhSachSinhVien dssv) {
  // int current_yCoord = 5;

  // Node<SinhVien> * curr_node = dssv.head();
  // while (curr_node != NULL) {
    // SinhVien curr_sv = curr_node->get_data();
    // mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*0, curr_sv.get_MASV());
    // mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*1, curr_sv.get_HO());
    // mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*2, curr_sv.get_TEN());
    // mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*3, (char *)curr_sv.get_PHAI());
    // mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*4, curr_sv.get_SDT());
    // curr_node = curr_node->get_next();

    // mvwhline(current_window, current_yCoord + 1, 1, 0, width - 2);
    // current_yCoord += 2;
  // }
  // wrefresh(current_window);
}

// Print DSDK
void Table::render_dsdk(DanhSachSinhVienDK dsdk) {
  int current_yCoord = 5;
  int i = 1;
  Node<SinhVienDK> * curr_node = dsdk.head();
  while (curr_node != NULL) {
    // Get SV info
    SinhVienDK curr_svdk = curr_node->get_data();
    SinhVien * curr_sv = dslcq.search_sv(curr_svdk.get_MASV());

    // Print
    mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*0, std::to_string(1).c_str());
    mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*1, curr_svdk.get_MASV());
    mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*2, curr_sv->get_HO());
    mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*3, curr_sv->get_TEN());
    mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*4, std::to_string(curr_svdk.get_DIEM()).c_str());

    curr_node = curr_node->get_next();
    mvwhline(current_window, current_yCoord + 1, 1, 0, width - 2);
    current_yCoord += 2;
  }
  wrefresh(current_window);
}

void Table::render_dsdk_nhap_diem(DanhSachSinhVienDK dsdk) {
  int current_yCoord = 5;
  int i = 1;
  Node<SinhVienDK> * curr_node = dsdk.head();
  while (curr_node != NULL) {
    // Get SV info
    SinhVienDK curr_svdk = curr_node->get_data();
    SinhVien * curr_sv = dslcq.search_sv(curr_svdk.get_MASV());

    // Print
    mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*0, curr_svdk.get_MASV());
    mvwprintw(current_window, current_yCoord, 1 + (average_width + 1)*1, std::to_string(curr_svdk.get_DIEM()).c_str());

    curr_node = curr_node->get_next();
    mvwhline(current_window, current_yCoord + 1, 1, 0, width - 2);
    current_yCoord += 2;
  }
  wrefresh(current_window);
}
