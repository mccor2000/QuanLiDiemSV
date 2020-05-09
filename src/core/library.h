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
void Show_Student(LinkedList<Student> dssv);

//-- E
void create_mh(DanhSachMonHoc&);
void update_mh(DanhSachMonHoc&);
void delete_mh(DanhSachMonHoc&);

//-- F
void print_dsmh(DanhSachMonHoc&);

//-- G
Node<Student>* timSV(char* maSV_tmp, LinkedList<Student> dssv);
void xuatSV(Node<Student>* SV);
void locDSLTC(LOPTC &loptc, DanhSachMonHoc &dsmh , short nienkhoa_tmp, short hocki_tmp);
int dangKyLop(LinkedList<Register> &dsdk, Register SV);

//-- H
void huyLopTC(LOPTC& BASE_DSLTC);

//-- I
Lop* timLop(LOPTC &dsltc, short nienkhoa_tmp, short hocki_tmp, short nhom_tmp, char* maMH_tmp);
Node<Student>* timSV(LinkedList<Student> &dssv, char* maSV_tmp);
void xuatDSDK(Lop* lop, LinkedList<Student> &dssv);


