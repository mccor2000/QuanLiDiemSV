#include <iostream>
#include <cstring>
#include <ncurses.h>
#include <menu.h>
#include <panel.h>

// void print_in_middle(WINDOW * win, int starty, int startx, int width, char * string, chtype color);
// void render_crud_menu(WINDOW * menu_win, MENU * current_menu, MENU * changed_menu);
class GUI {
private:
  int row, column;
  bool is_running;
  MENU * MAIN_menu;
  MENU * CRUD_menu;

  WINDOW * wins[2];
  PANEL * panels[2];

  void init_scr();
  void init_windows();
  
  MENU * get_main_menu();
  MENU * get_crud_menu();
  
  void run_main_menu();
  void run_crud_menu();

  void print_in_middle(int, int, int, char *, chtype);
public:
  GUI(){;}
  void setup();
  void run();
  void exit();
  void update_menu_window(WINDOW *, MENU *);  
};
