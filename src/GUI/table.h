#pragma once

#include "../core/library.h"
#include "./form.h"

#include <iostream>
#include <string>
#include <ncurses.h>
#include <cstring>

class Table {
private:
  // Properties
  WINDOW * current_window;
  Form update_form;

  int width, height;
  int page_size, len;
  int average_width;
  
  int type;
  char title[64];

  int current_index;
  int current_line; 
  
  char * get_item_data();
public:
  // Constructor
  Table(WINDOW *);
  Table() {;}
  
  void set_type(int t)                { type = t; }
  void set_title(char * t)            { strcpy(title, t); }
  void set_form(Form f)             { update_form = f; }
  
  // Public methods
  void display();
  void process_input();

  void render_dsltc(DanhSachLopTC dsltc);
  void render_dslcq(DanhSachLopCQ dslcq);
  void render_dsmh(DanhSachMonHoc dsmh);
  void render_dssv(DanhSachSinhVien dssv);
  void render_dsdk(DanhSachSinhVienDK dsdk);
};
