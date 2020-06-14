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
private:
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
  
  // Colors
  Color title_color;
  Color curr_color;
  Color status_color;

  // Private methods
  void draw_column_seperator(int);
  void draw_column(int, char **);

public:
  // Display table
  int length;
  int start_index;
  int end_index;
  int current_index;

  bool is_picked;
  bool is_exist;

  // Constructor
  Table(WINDOW *);
  Table() {;}
  
  // Getters, setters
  int get_current_index()             { return current_index; }
  int get_width()                     { return width; } 
  int get_height()                    { return height; } 
  char * get_title()                  { return title; }

  void set_type(int t)                { type = t; }
  void set_title(char * t)            { strcpy(title, t); }

  // Public methods
  void display();
  short get_input();

  void render_dsltc(DanhSachLopTC dsltc);
  void render_filtered_dsltc(DanhSachLopTC dsltc, char ** filter_data);
  void render_dslcq(DanhSachLopCQ dslcq);
  void render_dsmh(DanhSachMonHoc dsmh);
  void render_dssv(DanhSachSinhVien dssv);
  void render_dsdk(DanhSachSinhVienDK dsdk);
  void render_dsdk_nhap_diem(DanhSachSinhVienDK dsdk);
};
#endif
