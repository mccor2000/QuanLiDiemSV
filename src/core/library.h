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
void in_danh_sach_dk(LOPTC, short, short, short, char *);

//-- C
void them_sv(DanhSachSinhVien&, char *);

//-- D
void in_danh_sach_sv(char *);

//-- E
void create_mh(DanhSachMonHoc&);
void update_mh(DanhSachMonHoc&);
void delete_mh(DanhSachMonHoc&);

//-- F
void print_dsmh(DanhSachMonHoc&);

//-- G
SinhVien * timSV(char *, DanhSachSinhVien dssv);
void xuatSV(SinhVien * SV);
void locDSLTC(LOPTC &loptc, DanhSachMonHoc &dsmh , short nienkhoa_tmp, short hocki_tmp);
int dangKyLop(DanhSachSinhVienDK& , SinhVienDK);

//-- H
void huyLopTC(LOPTC& BASE_DSLTC);

