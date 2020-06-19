#ifndef _TABLE_H
#define _TABLE_H

#include "../database/database.h"
extern Database database;

#include "./form.h"
#include "./color.h"

#include <iostream>
#include <string>
#include <ncurses.h>
#include <cstring>

class Table {
public:
  int type;
  int input;

  // Window 
  WINDOW * current_window;
  int width;
  int height;

  // Title
  char title[64];

  // Fields
  int fields_len;
  int average_width;

  // Display table
  int length;
  int start_index;
  int end_index;
  int current_index;

  // Constructor
  Table(WINDOW *);
  Table() {;}
  
  // Public methods
  short get_input();

  void draw_column_seperator(int);
  void draw_column(int, char **);
};
#endif
