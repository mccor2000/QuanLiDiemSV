#include "./ui/ui.h"


int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
init_pair(1, COLOR_RED, COLOR_BLACK);
  WINDOW * wins[2];
  PANEL * panels[2];
  int rows, cols;

  /* Get scr size */
  getmaxyx(stdscr, rows, cols);
  
  /* Create windows */
  wins[0] = newwin(rows, (int)cols/4, 0, 0);
  wins[1] = newwin(rows, (int)(3*cols)/4, 0, (int)cols/4 + 1);
  
  keypad(wins[0], TRUE);
  keypad(wins[1], TRUE);
  
  box(wins[0], 0, 0);
  box(wins[1], 0, 0);
  refresh();

  MENU * core_menu = main_menu();
  set_menu_win(core_menu, wins[0]);
  set_menu_sub(core_menu, derwin(wins[0], 0, 0, 1, 1));

  post_menu(core_menu);
  wrefresh(wins[0]);

  print_in_middle(stdscr, rows/2, (int)cols/4 + 2, 40, "QUAN LI DIEM SINH VIEN", COLOR_PAIR(1));

  int c;
  while((c = wgetch(wins[0])) != KEY_F(1)) {
    switch(c) {
      case KEY_DOWN:
        menu_driver(core_menu, REQ_DOWN_ITEM);
        break;
      case KEY_UP:
        menu_driver(core_menu, REQ_UP_ITEM);
        break;
    }
    wrefresh(wins[0]);
  }
  endwin();
}
