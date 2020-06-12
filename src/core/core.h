#ifndef _LIBRARY_H
#define _LIBRARY_H
// Core library
#include <iostream>
#include <fstream>
#include <cstring>
#include <ncurses.h>
#include <string>
#include <stdio.h>

// Database
#include "../database/database.h"
extern Database database;

// Helpers
#include "../helpers/helpers.h"


// LOPTC__CRUD
void add_loptc(char ** data);
void update_loptc(char ** data);
void delete_loptc();
void detele_svdk();

//-- LOPCQ__CRUD
void add_lopcq(char **);


void add_sv(char **);
void update_sv(char **);
void search_sv(char **);
void delete_sv(int index);

//-- MONHOC__CRUD 
void add_mh(char **);
void update_mh(char **);
void delete_mh();

//-- 
void filter_dsltc(char **);
void dang_ky(char *);

//-- H
// LinkedList<char*> DSLopTC_HUY();
// bool HuyLopTC(int ma_lop);

//-- I
// LopTC* timLop(char* nienkhoa_tmp, short hocki_tmp, short nhom_tmp, char* maMH_tmp);
// LinkedList<char*> xuatDSDK(LopTC* loptc);
// void NhapDiemSV(SinhVienDK& sv, float DIEM );
void find_loptc(char **);
void set_score(char **);
//-- J
// LinkedList<char*> Show_Score(char* nienkhoa, short hocki, short nhom, char tenMH[]);

//-- K 
// LinkedList<char*> in_bang_diem_trung_binh(char* MALOP);

// -- L
// LinkedList<char*> in_bang_diem_tong_ket(char* MALOP);

#endif
