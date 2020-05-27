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
void themLop(DanhSachLopTC &dsltc, LopTC &loptc);
void xoaLop(DanhSachLopTC &dsltc,int maloptc);
void hieuChinhLop(DanhSachLopTC &dsltc, int index);

//-- B
void in_danh_sach_dang_ki(DanhSachLopTC &dsltc, char* nienkhoa, short hocki, short nhom, char * maMH);

//-- C
void them_sv(DanhSachLopCQ &DSLCQ, char * ma_lop, SinhVien &sv);
int vitri_sv(DanhSachSinhVien* DSSV,char* MASV);
void xoa_sv(DanhSachLopCQ &DSLCQ, char * ma_lop, char* MASV);
void hieu_chinh_sv(DanhSachLopCQ &DSLCQ, char * ma_lop, char* MASV);

//-- D
void in_danh_sach_sv(DanhSachLopCQ DSLCQ, char * ma_lop);

//-- E
void them_mh(DanhSachMonHoc& dsmh, MonHoc new_mh);
void hieu_chinh_mh(DanhSachMonHoc& dsmh, MonHoc old_mh, MonHoc new_mh);
void xoa_mh(DanhSachMonHoc& dsmh, MonHoc mh);

//-- F
void in_dsmh(DanhSachMonHoc& dsmh);

//-- G
Node<SinhVien>* timSV(char* maSV_tmp, DanhSachLopCQ &dslcq);
void xuatSV(Node<SinhVien>* SV);
void locDSLTC(DanhSachLopTC &dsltc, DanhSachMonHoc &dsmh , char* nienkhoa_tmp, short hocki_tmp);
int dangKyLop(LopTC &loptc, SinhVienDK SV);

//-- H
void DSLopTC_HUY(DanhSachLopTC& dsltc);
bool HuyLopTC(DanhSachLopTC& dsltc,int ma_lop);



//-- I
LopTC* timLop(DanhSachLopTC &dsltc, char* nienkhoa_tmp, short hocki_tmp, short nhom_tmp, char* maMH_tmp);
void xuatDSDK(LopTC* loptc, DanhSachLopCQ &dslcq);

//-- J
void Show_Score(DanhSachMonHoc& dsmh, DanhSachLopCQ &dslcq, DanhSachLopTC& dsltc,char* nienkhoa, short hocki, short nhom, char tenMH[]);

//-- K 
void in_bang_diem_trung_binh(DanhSachLopCQ& dslcq, DanhSachMonHoc& dsmh, DanhSachLopTC& dsltc, char* MALOP);

// -- L
void in_bang_diem_tong_ket(DanhSachLopCQ& dslcq, DanhSachMonHoc& dsmh, DanhSachLopTC& dsltc, char* MALOP);
