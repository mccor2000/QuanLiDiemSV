#pragma once

#include "../templates/LinkedList.h"
#include "../DSSV/dssv.h"

class LopCQ {
public:
  char * MALOP;
  DanhSachSinhVien * DSSV;
  
  //** Constructor 
  LopCQ(char *);
  LopCQ() {;}
};

class DanhSachLopCQ: public LinkedList<LopCQ> {
public:
  DanhSachSinhVien * get_dssv(char *);

  void save_to_file(char *);
  void get_from_file(char *);
};

