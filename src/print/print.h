#pragma once
#include "ncurses.h"
#include "../GUI/table.h"
#include "../helpers/helpers.h"

#include "../database/database.h"
extern Database database;

void print_dsltc(WINDOW *, Table &);
void print_dslcq(WINDOW *, Table &);
void print_dsmh(WINDOW *, Table &);
void print_dsdk(WINDOW *, Table &);
void print_dssv(WINDOW *, Table &);

void print_bang_diem_TK(WINDOW *, Table &);
void print_sv_info(WINDOW *, int, int, SinhVien);
