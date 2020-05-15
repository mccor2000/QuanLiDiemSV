// Core library
#include <iostream>
#include <fstream>
#include <cstring>

// Templates
#include "../../include/templates/LinkedList.h"

// Base classes
#include "../../include/DSSV/dssv.h"
#include "../../include/DSDK/dsdk.h"
#include "../../include/DSMH/dsmh.h"
#include "../../include/DSLTC/dsltc.h"
#include "../../include/DSLCQ/dslcq.h"

// Modules

//-- A
void themLop(LOPTC &loptc);
void xoaLop(LOPTC &loptc,int maloptc);
void hieuChinhLop(LOPTC &loptc, int index);

//-- B
void in_danh_sach_dk(LOPTC, short, short, short, char *);

//-- C
void them_sv(DanhSachLopCQ, char *);
void xoa_sv(DanhSachLopCQ, char *);
void hieu_chinh_sv(DanhSachLopCQ, char *);

//-- D
void in_danh_sach_sv(DanhSachLopCQ, char *);

//-- E
void create_mh(DanhSachMonHoc&);
void update_mh(DanhSachMonHoc&);
void delete_mh(DanhSachMonHoc&);

//-- F
void print_dsmh(DanhSachMonHoc&);

//-- G
Node<SinhVien>* timSV(char *, DanhSachLopCQ &dslcq);
void xuatSV(SinhVien * SV);
void locDSLTC(LOPTC &loptc, DanhSachMonHoc &dsmh , short nienkhoa_tmp, short hocki_tmp);
int dangKyLop(DanhSachSinhVienDK& , SinhVienDK);

//-- H
void DSLopTC_HUY(LOPTC& BASE_DSLTC);
bool HuyLopTC(LOPTC& BASE_DSLTC,int ma_lop);



//-- I
Lop* timLop(LOPTC &dsltc, short nienkhoa_tmp, short hocki_tmp, short nhom_tmp, char* maMH_tmp);
void xuatDSDK(Lop* lop, LinkedList<SinhVien> &dssv);

//-- J
void Show_Score(DanhSachMonHoc& ds, DanhSachSinhVien& dssv, LOPTC& dsltc,short nienkhoa, short hocki, short nhom, char tenMH[]);
//-- K 
void in_diem_trung_binh(DanhSachLopCQ& dslcq, DanhSachMonHoc& dsmh, LOPTC& dsltc, char* MALOP);

// -- L
void bang_diem_tong_ket(DanhSachLopCQ& dslcq, DanhSachMonHoc& dsmh, LOPTC& dsltc, char* MALOP);
