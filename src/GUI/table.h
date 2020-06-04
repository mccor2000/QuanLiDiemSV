#ifndef _TABLE_H
#define _TABLE_H
#include "../core/library.h"
#include "./form.h"
#include "./color.h"

#include <iostream>
#include <string>
#include <ncurses.h>
#include <cstring>

class Table {
private:
  int type;
  int input;

  // Window 
  WINDOW * current_window;
  int width;
  int height;
  
  // Display table
  int length;
  int start_index;
  int end_index;
  int current_index;
  
  // Title
  char title[64];

  // Fields
  int fields_len;
  int average_width;
  
  // Popup form
  Form update_form;
 
  // Colors
  Color title_color;
  Color curr_color;
  Color status_color;

  // Private methods
  char * get_item_data();
  void draw_column_seperator(int);
  void draw_column(int, char **);
  void process_input();

public:
  // Constructor
  Table(WINDOW *);
  Table() {;}
  
  void set_type(int t)                { type = t; }
  void set_title(char * t)            { strcpy(title, t); }
  void set_form(Form f)             { update_form = f; }
  
  // Public methods
  void display();
  bool get_input();

  void render_dsltc(DanhSachLopTC dsltc);
  void render_dslcq(DanhSachLopCQ dslcq);
  void render_dsmh(DanhSachMonHoc dsmh);
  void render_dssv(DanhSachSinhVien dssv);
  void render_dsdk(DanhSachSinhVienDK dsdk);
};
#endif
