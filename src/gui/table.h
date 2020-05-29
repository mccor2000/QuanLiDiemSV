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
  Table(WINDOW *);
  Table() {;}
  
  void set_type(int t)        { type = t; }
  void set_title(char * t)    { strcpy(title, t); }
  // Public methods
  bool get_input();
  void display();
};
