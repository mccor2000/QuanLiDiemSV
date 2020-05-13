#ifndef _DANGKY_H
#define _DANGKY_H

#include <iostream>
#include <fstream>
#include <cstring>

#include "../templates/LinkedList.h"

class SinhVienDK {
private:
  char MASV_[15];
  short DIEM_;
public:
  //** Constructor, destructor
  SinhVienDK(){;};
  SinhVienDK(char *, short);
  ~SinhVienDK(){;};
  
  //** Getters, setters
  char * get_MASV();
  short get_DIEM();
  
  void set_MASV(char *);
  void set_DIEM(short);

  //** Methods
  void info();
};

class DanhSachSinhVienDK: public LinkedList<SinhVienDK> {
public: 
  void print();
  void save(const char *);
  void load(const char *);
};

#endif
