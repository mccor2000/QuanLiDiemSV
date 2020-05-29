// Core library
#include <iostream>
#include <fstream>
#include <cstring>
#include <ncurses.h>
#include <string>
#include <stdio.h>
// Templates
#include "../../include/templates/LinkedList.h"

// Base classes
#include "../../include/DSSV/dssv.h"
#include "../../include/DSDK/dsdk.h"
#include "../../include/DSMH/dsmh.h"
#include "../../include/DSLTC/dsltc.h"
#include "../../include/DSLCQ/dslcq.h"

// Modules
// bonus 
LinkedList<char*> DanhSachLopChinhQuy(DanhSachLopCQ& dslcq);
//-- A
short StringToShort(char* st);
int StringToInt(char* st);
void themLop(DanhSachLopTC &dsltc, LopTC &loptc);
void xoaLop(DanhSachLopTC &dsltc,char* maloptc);
void hieuChinhLop(DanhSachLopTC &dsltc, char** data, char* malop);

//-- B
LinkedList<char*> in_danh_sach_dang_ki(DanhSachLopTC &dsltc, char* nienkhoa, short hocki, short nhom, char * maMH);

//-- C
void them_sv(DanhSachLopCQ &DSLCQ, char * ma_lop, SinhVien &sv);
int vitri_sv(DanhSachSinhVien* DSSV,char* MASV);
void xoa_sv(DanhSachLopCQ &DSLCQ, char * ma_lop, char* MASV);
void hieu_chinh_sv(DanhSachLopCQ &DSLCQ, char * ma_lopCQ, char* MASV, char** data);

//-- D
LinkedList<char*> in_danh_sach_sv(DanhSachLopCQ DSLCQ, char * ma_lop);

//-- E
void them_mh(DanhSachMonHoc& dsmh, MonHoc new_mh);
void hieu_chinh_mh(DanhSachMonHoc& dsmh, char ** data_old, char ** data_new);
void xoa_mh(DanhSachMonHoc& dsmh, char ** data);

//-- F
LinkedList<char*> in_dsmh(DanhSachMonHoc& dsmh);

//-- G
Node<SinhVien>* timSV(char* maSV_tmp, DanhSachLopCQ &dslcq);
void xuatSV(Node<SinhVien>* SV);
LinkedList<char*> locDSLTC(DanhSachLopTC &dsltc, DanhSachMonHoc &dsmh , char* nienkhoa_tmp, short hocki_tmp);
int dangKyLop(LopTC &loptc, SinhVienDK SV);

//-- H
LinkedList<char*> DSLopTC_HUY(DanhSachLopTC& dsltc);
bool HuyLopTC(DanhSachLopTC& dsltc,int ma_lop);

//-- I
LopTC* timLop(DanhSachLopTC &dsltc, char* nienkhoa_tmp, short hocki_tmp, short nhom_tmp, char* maMH_tmp);
LinkedList<char*> xuatDSDK(LopTC* loptc, DanhSachLopCQ &dslcq);
void NhapDiemSV(SinhVienDK& sv, float DIEM );

//-- J
LinkedList<char*> Show_Score(DanhSachMonHoc& dsmh, DanhSachLopCQ &dslcq, DanhSachLopTC& dsltc,char* nienkhoa, short hocki, short nhom, char tenMH[]);

//-- K 
LinkedList<char*> in_bang_diem_trung_binh(DanhSachLopCQ& dslcq, DanhSachMonHoc& dsmh, DanhSachLopTC& dsltc, char* MALOP);

// -- L
LinkedList<char*> in_bang_diem_tong_ket(DanhSachLopCQ& dslcq, DanhSachMonHoc& dsmh, DanhSachLopTC& dsltc, char* MALOP);

char* converting(int x){
    char* result = "";
    while(x){
        char res=char(x%10)+48;
        char* ans = &res;
        strcat(result,ans);
        x/=10;
    }
    return result;
}