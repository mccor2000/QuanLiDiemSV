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
private:
  char db[32] = "../../database/dslcq.d";

public:
  DanhSachSinhVien * get_dssv(char *);
  SinhVien * search_sv(char *);

  void save();
  void load();
};

