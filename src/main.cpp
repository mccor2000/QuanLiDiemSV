#include "./core/library.h"
#include "./ui/ui.h"

int main() {
  /* Initialize ncurses mode */
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  int rows, cols;
  getmaxyx(stdscr, rows, cols);
  

  /* Initialize 2 panels contain windows
   * -> Menu window includes: 
   *  + Main menu: Quan ly lop cq, quan ly lop tc,... 
   *  + CRUD menu: Hieu chinh, them, xoa,...
   *
   * -> Display window includes:
   *  + Tables: Danh sach, bang diem,...
   *  + Form input: -> Hieu chinh
   * 
   * */
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
  

  /* Inital status 
   * -> Menu window: Main menu
   * -> Display: App's infos
   * 
   * */

  //-- Menus:
  MENU * MAIN_menu = main_menu();
  MENU * CRUD_menu = crud_menu();

  set_menu_win(MAIN_menu, wins[0]);
  set_menu_sub(MAIN_menu, derwin(wins[0], 0, 0, 1, 1));
  post_menu(MAIN_menu);
  wrefresh(wins[0]);
  //-- App's infos:
  print_in_middle(wins[1], 8, 0, 80, "QUAN LI DIEM SINH VIEN", COLOR_PAIR(1));
  wrefresh(wins[1]);
  
  /* Core app's functions 
   * 
   * Install functionality for menu's options
   *
   * */
  int c;
  while((c = wgetch(wins[0])) != KEY_F(1)) {
    switch(c) {
      //-- Navigate between options
      case KEY_DOWN:
        menu_driver(MAIN_menu, REQ_DOWN_ITEM);
        break;
      case KEY_UP:
        menu_driver(MAIN_menu, REQ_UP_ITEM);
        break;
      //-- Pick an option
      case 10:
        unpost_menu(MAIN_menu);
        set_menu_win(CRUD_menu, wins[0]);
        set_menu_sub(CRUD_menu, derwin(wins[0], 0, 0, 1, 1));
        post_menu(CRUD_menu);
        wrefresh(wins[0]);
        while ((c = wgetch(wins[0])) != KEY_F(1)) {
          switch (c) {
            case KEY_DOWN:
              menu_driver(CRUD_menu, REQ_DOWN_ITEM);
              break;
            case KEY_UP:
              menu_driver(CRUD_menu, REQ_UP_ITEM);
              break;
          }
        }
        break;
    }
    wrefresh(wins[0]);
  }
  endwin();
}
