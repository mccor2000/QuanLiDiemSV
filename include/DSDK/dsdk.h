#ifndef _DANGKY_H
#define _DANGKY_H

#include <iostream>
#include <fstream>
#include <cstring>

#include "../templates/LinkedList.h"

class SinhVienDK {
private:
  char MASV_[15];
  float DIEM_;
public:
  //** Constructor, destructor
  SinhVienDK(){;};
  SinhVienDK(char *);
  SinhVienDK(char *, float);
  
  //** Getters, setters
  char * get_MASV();
  float get_DIEM();
  
  void set_MASV(char *);
  void set_DIEM(float);
  
  //** Operator
  bool operator == (SinhVienDK);
};

class DanhSachSinhVienDK: public LinkedList<SinhVienDK> {
public: 
  DanhSachSinhVienDK();

  Node<SinhVienDK> * get_node_by_index(int index);
  void save(const char *);
  void load(const char *);
};

#endif
