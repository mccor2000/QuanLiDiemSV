#pragma once
#include "ncurses.h"
#include "../GUI/table.h"

#include "../database/database.h"
extern Database database;

void print_bang_diem_TK(WINDOW *, Table &);
void print_sv_info(WINDOW *, int, int, SinhVien);
