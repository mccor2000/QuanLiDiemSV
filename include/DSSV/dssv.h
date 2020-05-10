#ifndef _SINHVIEN_H
#define _SINHVIEN_H

#include <iostream>
#include <fstream>
#include <cstring>

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
  SinhVien(){;};
  SinhVien(char *, char *, char *, bool, char *, char *);
  
  //** Getters, setters
  char* get_MASV();
  char* get_HO();
  char* get_TEN();
  char* get_SDT();
  char* get_MALOP();
  bool get_PHAI();
  
  void set_MASV(char *);
  void set_HO(char *);
  void set_TEN(char *);
  void set_SDT(char *);
  void set_MALOP(char *);
  void set_PHAI(bool);

  void info();

  //** Operator overloading
  bool operator > (SinhVien);
  bool operator < (SinhVien);
  bool operator == (SinhVien);
};

class DanhSachSinhVien: public LinkedList<SinhVien> {
  public:
    void save_to_file(char *);
    void get_from_file(char *);
};

#endif
