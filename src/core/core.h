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
void delete_svdk(int index);

//-- LOPCQ__CRUD
void add_lopcq(char **);
void find_lopcq(char **);

//-- SinhVien__CRUD
void add_sv(char **);
void update_sv(char **);
void search_sv(char **);
void delete_sv(int index);

//-- MONHOC__CRUD 
void add_mh(char **);
void update_mh(char **);
void delete_mh();

//-- DANG_KI
void filter_dsltc(char **);
bool dang_ky(char *);

//-- NHAP_DIEM 
void find_loptc(char **);
void set_score(char **);
#endif
