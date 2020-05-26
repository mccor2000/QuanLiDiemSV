#include <iostream>
#include <cstring>
#include <ncurses.h>
#include <menu.h>
#include <panel.h>
#include "./table.h"

class GUI {
private:
  int row, column;
  bool is_running;
  MENU * MAIN_menu;
  MENU * CRUD_menu;
  MENU * DSMH_table;

  WINDOW * wins[2];
  PANEL * panels[2];

  void init_scr();
  void init_windows();
  
  MENU * get_main_menu();
  MENU * get_crud_menu();

  MENU * get_dsmh_table();  

  void render_main_menu();
  void render_crud_menu();
  
  void render_dsmh();
  void render_dsltc();
  void render_dslcq();
  void render_dssv(char **);
  void render_dsdk(char **);

  void print_in_middle(int, int, int, char *, chtype);
public:
  GUI(){;}
  void setup();
  void run();
  void exit();
};
