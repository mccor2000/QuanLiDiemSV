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
  void render_data();
public:
  // Constructor
  Table(WINDOW *, int);

  // Getters 
  int get_width()           { return width; }
  int get_height()          { return height; }
  int get_current_line()    { return current_line; }

  char * get_title()        { return title; }
  WINDOW * get_window()     { return current_window; }

  // Public methods
  bool get_input();
  void display();
};
