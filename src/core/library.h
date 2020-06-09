#ifndef _LIBRARY_H
#define _LIBRARY_H
// Core library
#include <iostream>
#include <fstream>
#include <cstring>
#include <ncurses.h>
#include <string>
#include <stdio.h>

// Templates
#include "../../include/templates/LinkedList.h"

// Base classes
#include "../../include/DSSV/dssv.h"
#include "../../include/DSDK/dsdk.h"
#include "../../include/DSMH/dsmh.h"
#include "../../include/DSLTC/dsltc.h"
#include "../../include/DSLCQ/dslcq.h"

// Helpers
#include "../helpers/helpers.h"

// Database
#include "../database/database.h"
extern Database database;

extern DanhSachLopTC dsltc;
extern DanhSachLopCQ dslcq;
extern DanhSachMonHoc dsmh;

extern DanhSachLopTC filtered_dsltc;

extern LopTC * current_loptc;
extern LopCQ current_lopcq;

extern Node<SinhVien> * current_sv;
extern SinhVienDK current_svdk;
extern DanhSachSinhVien * current_dssv;
extern DanhSachSinhVienDK * current_dsdk;
// Modules
// bonus 
void add_lopcq(char **);
//-- A
void add_loptc(char ** data);
void delete_loptc(int maloptc);
void update_loptc(char ** data);

//-- B
LinkedList<char*> in_danh_sach_dang_ki(char* nienkhoa, short hocki, short nhom, char * maMH);

//-- C
void add_sv(char **);
void update_sv(char **);
void search_sv(char **);
void delete_sv(char **);

//-- E
void add_mh(char **);
void delete_mh(char *);
void update_mh(char **);

//-- G
void filter_dsltc(char **);
void dang_ky(char *);

//-- H
LinkedList<char*> DSLopTC_HUY();
bool HuyLopTC(int ma_lop);

//-- I
LopTC* timLop(char* nienkhoa_tmp, short hocki_tmp, short nhom_tmp, char* maMH_tmp);
LinkedList<char*> xuatDSDK(LopTC* loptc);
void NhapDiemSV(SinhVienDK& sv, float DIEM );
void find_loptc(char **);
void set_score(char **);
//-- J
LinkedList<char*> Show_Score(char* nienkhoa, short hocki, short nhom, char tenMH[]);

//-- K 
LinkedList<char*> in_bang_diem_trung_binh(char* MALOP);

// -- L
LinkedList<char*> in_bang_diem_tong_ket(char* MALOP);

char* converting(int x);
#endif
