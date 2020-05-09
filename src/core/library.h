// Core library
#include <iostream>
#include <fstream>
#include <cstring>

// Templates
#include"../../include/templates/LinkedList.h"

// Base classes
#include"../../include/DSSV/dssv.h"
#include"../../include/DSDK/dsdk.h"
#include"../../include/DSMH/dsmh.h"
#include"../../include/DSLTC/dsltc.h"

char DSLTC_PATH__[] = "../../database/dsltc.d";
char DSMH_PATH__[] = "../../database/dsmh.d";
char DSSV_PATH__[] = "../../database/dssv.d";
// Modules

//-- A
void themLop(LOPTC &loptc);
void xoaLop(LOPTC &loptc,int maloptc);
void hieuChinhLop(LOPTC &loptc, int index);
//-- B

//-- C
void Add();

//-- D
void Show_Student(DanhSachSinhVien dssv);

//-- E
void create_mh(DanhSachMonHoc&);
void update_mh(DanhSachMonHoc&);
void delete_mh(DanhSachMonHoc&);

//-- F
void print_dsmh(DanhSachMonHoc&);

//-- H
void huyLopTC(LOPTC& BASE_DSLTC);

