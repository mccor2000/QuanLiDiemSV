#pragma once
#include "ncurses.h"

#include "../database/database.h"
extern Database database;

void print_dsltc(WINDOW *, DanhSachLopTC);
void print_dslcq(WINDOW *, DanhSachLopCQ);
void print_dsmh(WINDOW *, DanhSachMonHoc);
void print_dssv(WINDOW *, DanhSachSinhVien);
void print_dsdk(WINDOW *, DanhSachSinhVienDK);

void print_sv_info(WINDOW *, int, int, SinhVien);

void print_bang_diem_TBKH(WINDOW *);
void print_bang_diem_TK(WINDOW *);
