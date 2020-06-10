#ifndef _SINHVIEN_H
#define _SINHVIEN_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <ncurses.h>

#include "../templates/LinkedList.h"

class SinhVien{
private:
  char MASV_[15];
  char HO_[16];
  char TEN_[16];
  bool PHAI_;
  char SDT_[16];
  char MALOP_[15];
public:
  //** Constructors
  SinhVien();
  SinhVien(char *, char *, char *, bool, char *, char *);
  
  //** Getters, setters
  char * get_MASV()              { return MASV_; }
  char * get_HO()                { return HO_; }
  char * get_TEN()               { return TEN_; }
  char * get_SDT()               { return SDT_; }
  char * get_MALOP()             { return MALOP_; }
  bool get_PHAI()                { return PHAI_; } 
  
  void set_MASV(char * MASV)     { strcpy(MASV_, MASV); }
  void set_HO(char * HO)         { strcpy(HO_, HO); }   
  void set_TEN(char * TEN)       { strcpy(TEN_, TEN); }
  void set_SDT(char * SDT)       { strcpy(SDT_, SDT); }
  void set_MALOP(char * MALOP)   { strcpy(MALOP_, MALOP); }
  void set_PHAI(bool PHAI)       { PHAI_ = PHAI; }

  //** Operator overloading
  bool operator > (SinhVien);
  bool operator < (SinhVien);
  bool operator == (SinhVien);
};

class DanhSachSinhVien: public LinkedList<SinhVien> {
public:
  DanhSachSinhVien();

  void delete_sv(char *);
  SinhVien get_sv(char *);  
  
  Node<SinhVien> * get_node_by_index(int index);
  SinhVien get_by_index(int index);

  void save(const char *);
  void load(const char *);
};

#endif
