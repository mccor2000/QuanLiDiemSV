#pragma once

// Core library
#include <iostream>
#include <fstream>
#include <cstring>
#include <ncurses.h>
#include <string>
#include <stdio.h>

// Helpers
#include "../helpers/helpers.h"

// Database 
#include "./database.h"

extern DanhSachLopTC dsltc;
extern DanhSachLopCQ dslcq;
extern DanhSachMonHoc dsmh;

// Modules
// bonus 
LinkedList<char*> DanhSachLopChinhQuy();

//-- A
void add_loptc(char ** data);
void delete_loptc(int maloptc);
void update_loptc(char ** data);
void print_dsltc(WINDOW *, int, int);

//-- B
LinkedList<char*> in_danh_sach_dang_ki(char* nienkhoa, short hocki, short nhom, char * maMH);

//-- C
void them_sv(char * ma_lop, SinhVien &sv);
int vitri_sv(DanhSachSinhVien* DSSV,char* MASV);
void xoa_sv(char * ma_lop, char* MASV);
void hieu_chinh_sv(char * ma_lopCQ, char* MASV, char** data);

//-- D
LinkedList<char*> in_danh_sach_sv(char * ma_lop);

//-- E
void add_mh(char **);
void delete_mh(char *);
void update_mh(char **);

//-- F
// std::string[4] * get_dsmh_table(DanhSachMonHoc dsmh);

//-- G
Node<SinhVien>* timSV(char* maSV_tmp);
void xuatSV(Node<SinhVien>* SV);
LinkedList<char*> locDSLTC(char* nienkhoa_tmp, short hocki_tmp);
int dangKyLop(LopTC &loptc, SinhVienDK SV);

//-- H
LinkedList<char*> DSLopTC_HUY();
bool HuyLopTC(int ma_lop);

//-- I
LopTC* timLop(char* nienkhoa_tmp, short hocki_tmp, short nhom_tmp, char* maMH_tmp);
LinkedList<char*> xuatDSDK(LopTC* loptc);
void NhapDiemSV(SinhVienDK& sv, float DIEM );

//-- J
LinkedList<char*> Show_Score(char* nienkhoa, short hocki, short nhom, char tenMH[]);

//-- K 
LinkedList<char*> in_bang_diem_trung_binh(char* MALOP);

// -- L
LinkedList<char*> in_bang_diem_tong_ket(char* MALOP);

char* converting(int x);
