#pragma once

#include <iostream>
#include <string>
#include <ncurses.h>
#include <cstring>
#include "../core/library.h"

class Table {
private:
  // Properties
  WINDOW * current_window;
  int width, height;

  int type;
  char title[64];
  int input;
  int current_line; 

  // Private methods
  void process_input();
  void display_table();
public:
  // Constructor
  Table(WINDOW *, int);
  Table() {;}
  // Public methods
  bool get_input();
  void display();
};
