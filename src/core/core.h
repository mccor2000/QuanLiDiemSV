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
bool add_loptc(char ** data);
bool update_loptc(char ** data);
void delete_loptc();
void delete_svdk(int index);

//-- LOPCQ__CRUD
bool add_lopcq(char **);
// void find_lopcq(char **);

//-- SinhVien__CRUD
bool add_sv(char **);
bool update_sv(char **);
bool search_sv(char **);
void delete_sv(int index);

//-- MONHOC__CRUD 
bool add_mh(char **);
bool update_mh(char **);
void delete_mh();

//-- DANG_KI
bool filter_dsltc(char **);
bool dang_ky(char *);

//-- NHAP_DIEM 
bool find_loptc(char **);
bool set_score(char **);
#endif
