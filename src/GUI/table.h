#pragma once

#include "../core/library.h"

#include <iostream>
#include <string>
#include <ncurses.h>
#include <cstring>

class Table {
private:
  // Properties
  WINDOW * current_window;
  int width, height;
  int page_size, len;
  
  int average_width;
  
  int type;
  char title[64];

  int input;
  int current_line; 
public:
  // Constructor
  Table(WINDOW *);
  Table() {;}
  
  void set_type(int t)                { type = t; }
  void set_title(char * t)            { strcpy(title, t); }

  // Public methods
  bool get_input();
  void display();
  void process_input();

  void render_dsltc(DanhSachLopTC dsltc);
  void render_dslcq(DanhSachLopCQ dslcq);
  void render_dsmh(DanhSachMonHoc dsmh);
  void render_dssv(DanhSachSinhVien dssv);
  void render_dsdk(DanhSachSinhVienDK dsdk);
};
