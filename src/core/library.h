// Core library
#include <iostream>

// Templates
#include"../../include/templates/LinkedList.h"

// Base classes
#include"../../include/SinhVien/SinhVien.h"
#include"../../include/DangKy/DangKy.h"
#include"../../include/DSMH/dsmh.h"
#include"../../include/DSLTC/dsltc.h"

// Database controllers
DanhSachMonHoc get_dsmh();
void set_dsmh(DanhSachMonHoc);

LOPTC get_dsltc();
void set_dsltc();

LinkedList<Student> get_dssv();
void set_dssv(LinkedList<Student>);

LinkedList<Register> get_dsdk(char *);
void set_dsdk(LinkedList<Register>, char *);
