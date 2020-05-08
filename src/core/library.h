// Core library
#include <iostream>
#include <fstream>
// Templates
#include"../../include/templates/LinkedList.h"

// Base classes
#include"../../include/SinhVien/SinhVien.h"
#include"../../include/DangKy/DangKy.h"
#include"../../include/DSMH/dsmh.h"
#include"../../include/DSLTC/dsltc.h"
#include"../../include/LopCQ/lopCQ.h"

char DSLTC_PATH__[] = "../../database/dsmh.d";
char DSMH_PATH__[] = "../../database/dsmh.d";

// Modules

//-- A
void themLop(LOPTC &loptc);
void xoaLop(LOPTC &loptc,int maloptc);
void hieuChinhLop(LOPTC &loptc, int index);
//-- B

//-- C
void POST(char* tenLop, LinkedList<Student> dssv);
void GET_ALL();
void GET_NAME(char* name);
void PUT(char* name, lopCQ tmp);
LinkedList<Student> SelectClass();
void Add();

//-- D

//-- E
void create_mh();
void update_mh();
void delete_mh();
