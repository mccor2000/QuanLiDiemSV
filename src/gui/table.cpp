#include "./table.h"

char * DSLTC_FIELDS[] = { 
  "MA",
  "MA MH",
  "NIEN KHOA",
  "HOC KI",
  "NHOM",
  "SO SV MIN",
  "SO SV MAX",
};

char * DSLCQ_FIELDS[] = {
  "MA",
  "SO SV"
};

char * DSMH_FIELDS[] = {
  "MA",
  "TEN",
  "STCLT",
  "STCTH",
};

char * DSSV_FIELDS[] = {
  "MA",
  "HO",
  "TEN",
  "GIOI TINH",
  "SDT",
};

char * DSDK_FIELDS[] = {
  "MA",
  "DIEM",
};

Table::Table(WINDOW * win, int t) {
  current_window = win;
  getmaxyx(win, height, width);
  
  type = t;
  switch (type) {
    case 1:
      strcpy(title,"DANH SACH LOP TIN CHI");
      break;
    case 2:
      strcpy(title, "DANH SACH LOP CHINH QUY");
      break;
    case 3:
      strcpy(title, "DANH SACH MON HOC");
      break;
    case 4:
      strcpy(title, "DANH SACH SINH VIEN");
      break;
    case 5:
      strcpy(title, "DANH SACH DANG KY");
      break;
  }
  current_line = 0;
  input = 0;
}

bool Table::get_input() {
  input = getch();
  if (input == KEY_F(1)) {
    return false;
  }

  process_input();
  return true;
}

void Table::process_input() {
  int top_char;
  int bottom_char;

  switch (input) {
    case KEY_UP:
      current_line--;
      break;
    case KEY_DOWN:
      current_line++;
      break;
  }
}

void Table::display() {
  // start_color();
  box(current_window, 0, 0);
  display_table();
  wrefresh(current_window);
}

void Table::display_table() {
  int len;
  char ** fields;
  switch (type) {
    case 1:
      fields = DSLTC_FIELDS;
      len = 7; 
      break;
    case 2:
      fields = DSLCQ_FIELDS;
      len = 2;
      break;
    case 3:
      fields = DSMH_FIELDS;
      len = 4;
      break;
    case 4:
      fields = DSSV_FIELDS;
      len = 5;
      break;
    case 5:
      fields = DSDK_FIELDS;
      len = 2;
      break;
  }
  
  int current_xCoord = 0;
  // Title
  mvwprintw(current_window, 1, (width - strlen(title)) / 2, title);
  mvwhline(current_window, 2, 1, 0, width - 2);
  mvwhline(current_window, 4, 1, 0, width - 2);
    
  // Fields
  for (int i = 0; i < len; i++) {
    mvwprintw(current_window, 3, current_xCoord + 1, fields[i]);
    current_xCoord += strlen(fields[i]) + 1;
    mvwvline(current_window, 5, current_xCoord, 0, height - 6);

    mvwaddch(current_window, 2, current_xCoord, ACS_TTEE);
    mvwaddch(current_window, 3, current_xCoord, ACS_VLINE);
    mvwaddch(current_window, 4, current_xCoord, ACS_PLUS);
  }
  wrefresh(current_window);
}
