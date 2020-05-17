#include "./ui/ui.h"


int main() {
  /* Initialize ncurses */
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  int rows, cols;
  getmaxyx(stdscr, rows, cols);
  

  /* Initialize 2 panels contain windows */
  WINDOW * wins[2];
  PANEL * panels[2];
  
  //-- Menu window
  wins[0] = newwin(rows, (int)cols/4, 0, 0);
  keypad(wins[0], TRUE);
  box(wins[0], 0, 0);
  panels[0] = new_panel(wins[0]);
  //-- Display window
  wins[1] = newwin(rows, (int)(3*cols)/4, 0, (int)cols/4 + 1);
  keypad(wins[1], TRUE);
  box(wins[1], 0, 0);
  panels[1] = new_panel(wins[1]);
  
  update_panels();
  doupdate();
  refresh();
  
  /* Inital status */
  MENU * core_menu = main_menu();
  set_menu_win(core_menu, wins[0]);
  set_menu_sub(core_menu, derwin(wins[0], 0, 0, 1, 1));
  post_menu(core_menu);
  wrefresh(wins[0]);
  
  print_in_middle(wins[1], 8, 0, 80, "QUAN LI DIEM SINH VIEN", COLOR_PAIR(1));
  wrefresh(wins[1]);
  
  /* Core app's functions */
  int c;
  while((c = wgetch(wins[0])) != KEY_F(1)) {
    switch(c) {
      case KEY_DOWN:
        menu_driver(core_menu, REQ_DOWN_ITEM);
        break;
      case KEY_UP:
        menu_driver(core_menu, REQ_UP_ITEM);
        break;
      case 10:
        break;
    }
    wrefresh(wins[0]);
  }

  endwin();
}
