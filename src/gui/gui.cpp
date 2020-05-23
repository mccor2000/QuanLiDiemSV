#include "./gui.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

void GUI::init_scr() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  init_pair(1, COLOR_RED, COLOR_BLACK);

  getmaxyx(stdscr, row, column);
}

void GUI::init_windows() {
  //-- Menu window
  wins[0] = newwin(row, (int)column/4, 0, 0);
  keypad(wins[0], TRUE);
  box(wins[0], 0, 0);
  panels[0] = new_panel(wins[0]);
  //-- Display window
  wins[1] = newwin(row, (int)(3*column)/4, 0, (int)column/4 + 1);
  keypad(wins[1], TRUE);
  box(wins[1], 0, 0);
  panels[1] = new_panel(wins[1]);

  update_panels();
  doupdate();
  refresh();
}

MENU * GUI::get_crud_menu() {
  char * choices[] = {
    "Them",
    "Hieu chinh",
    "Xoa",
    "Quay lai",
    (char *)NULL,
  };

  ITEM **items;
  int n_choices, c;
	
	n_choices = ARRAY_SIZE(choices);
	items = (ITEM **)calloc(n_choices, sizeof(ITEM *));

	for(int i = 0; i < n_choices; ++i) {
    items[i] = new_item(choices[i], "");
  }

  return new_menu((ITEM **)items);
}

MENU * GUI::get_main_menu() {
  char * choices[] = {
    "Quan ly lop tin chi",
    "Quan ly lop chinh quy",
    "Quan ly mon hoc",
    "Nhap diem",
    "Dang ki",
    "Thoat",
    (char *)NULL,
  };

  ITEM **items;
  int n_choices, c;
	
	n_choices = ARRAY_SIZE(choices);
	items = (ITEM **)calloc(n_choices, sizeof(ITEM *));

	for(int i = 0; i < n_choices; ++i) {
    items[i] = new_item(choices[i], "");
  }

  return new_menu((ITEM **)items);
}

void GUI::run_main_menu() {
  wclear(wins[0]);
  unpost_menu(CRUD_menu);

  box(wins[0], 0, 0);
  set_menu_win(MAIN_menu, wins[0]);
  set_menu_sub(MAIN_menu, derwin(wins[0], 0, 0, 1, 1));
  post_menu(MAIN_menu);
  wrefresh(wins[0]);
  
  int c;
  while((c = wgetch(wins[0])) != KEY_F(1) && is_running) {
    switch(c) {
      //-- Navigate
      case KEY_DOWN:
        menu_driver(MAIN_menu, REQ_DOWN_ITEM);
        break;
      case KEY_UP:
        menu_driver(MAIN_menu, REQ_UP_ITEM);
        break;
      //-- Choose
      case 10:
        bool back = false;
        switch (item_index(current_item(MAIN_menu))) {
          case 0:
            unpost_menu(MAIN_menu);
            run_crud_menu();
            break;
          case 1:
            unpost_menu(MAIN_menu);
            run_crud_menu();
            break;
          case 2:
            unpost_menu(MAIN_menu);
            run_crud_menu();
            break;
          case 3:
            break;
          case 4:
            break;
          case 5:
            exit();
            break;
        }
        break;
    }
  }
}

void GUI::run_crud_menu() {
  wclear(wins[0]);
  unpost_menu(MAIN_menu);

  box(wins[0], 0, 0);
  set_menu_win(CRUD_menu, wins[0]);
  set_menu_sub(CRUD_menu, derwin(wins[0], 0, 0, 1, 1));
  post_menu(CRUD_menu);
  wrefresh(wins[0]);
  
  int c;
  while((c = wgetch(wins[0])) != KEY_F(1) && is_running) {
    switch(c) {
      //-- Navigate
      case KEY_DOWN:
        menu_driver(CRUD_menu, REQ_DOWN_ITEM);
        break;
      case KEY_UP:
        menu_driver(CRUD_menu, REQ_UP_ITEM);
        break;
      //-- Choose
      case 10:
        bool back = false;
        switch (item_index(current_item(CRUD_menu))) {
          case 0:
            break;
          case 1:
            break;
          case 2:
            break;
          case 3:
            unpost_menu(CRUD_menu);
            run_main_menu();
            break;
        }
        break;
    }
  }

}

void GUI::print_in_middle(int starty, int startx, int width, char * string, chtype color) {
  int length, x, y;
  float temp;
  
  getyx(wins[1], y, x);
  if (startx != 0) x = startx;
  if (starty != 0) y = starty;
  if (width == 0) width = 80;
  
  length = strlen(string);
  temp = (width - length)/2;

  x = startx + (int)temp;
  mvwprintw(wins[1], y, x, "%s", string);
  wrefresh(wins[1]);
}

void GUI::setup() {
  init_scr();
  MAIN_menu = get_main_menu();
  CRUD_menu = get_crud_menu();
  init_windows();
}


void GUI::run() {
  wrefresh(wins[0]);
  wrefresh(wins[1]);
  refresh();
  
  print_in_middle(8, 0, 80, "QUAN LI DIEM SINH VIEN", COLOR_PAIR(1));
  run_main_menu();
}

void GUI::exit() {
  is_running = false;
  clear();
  endwin();
}
