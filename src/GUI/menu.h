#pragma once

#include <iostream>
#include <ncurses.h>
#include <menu.h>

class Menu {
public:
  int type;
  int len;
  MENU * menu;
  WINDOW * current_window;

  // Constructor
  Menu(WINDOW *, int);
  Menu() {;}
  // Public methods
  void display();
  bool get_input();
private:
  void process_input(int);
  char ** get_items();
};
