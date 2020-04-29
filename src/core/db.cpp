#include <fstream>
#include "library.h"


fstream f;

//*** DSMH
DanhSachMonHoc get_dsmh() {
  DanhSachMonHoc dsmh;

  f.open("../../database/dsmh.d", ios::binary|ios::in);
  f.read((char *)&dsmh, sizeof(DanhSachMonHoc)); 
  f.close();
  return dsmh;
}

void set_dsmh(DanhSachMonHoc dsmh) {
  f.open("../../database/dsmh.d", ios::binary|ios::out);
  f.write((char *)&dsmh, sizeof(DanhSachMonHoc));
  f.close();
}

//*** DSLTC
LOPTC get_dsltc() {
  LOPTC dsltc;

  f.open("../../database/dsltc.d", ios::binary|ios::in);
  f.read((char *)&dsltc, sizeof(LOPTC));
  f.close();
  return dsltc;
}

void set_dsltc(LOPTC dsltc) {
  f.open("../../database/dsltc.d", ios::binary|ios::out);
  f.write((char *)&dsltc, sizeof(LOPTC));
  f.close();
}

//*** DSSV
LinkedList<Student> get_dssv() {
  LinkedList<Student> dssv;

  f.open("../../database/dssv.d", ios::binary|ios::in);
  f.read((char *)&dssv, sizeof(LinkedList<Student>));
  f.close();
  return dssv;
}

void set_dssv(LinkedList<Student> dssv) {
  f.open("../../database/dssv.d", ios::binary|ios::out);
  f.write((char *)&dssv, sizeof(LinkedList<Student>));
  f.close();
}

//*** DSDK
LinkedList<Register> get_dsdk(char * MALOP) {
  LinkedList<Register> dsdk;
  
  char file_path[] = "../../database/";
  strcat(file_path, (char *)MALOP);
  strcat(file_path, ".d");

  f.open(file_path, ios::binary|ios::in);
  f.read((char *)&dsdk, sizeof(LinkedList<Student>));
  f.close();
  return dsdk;

}

void set_dsdk(LinkedList<Register> dsdk, char * MALOP) {
  char file_path[] = "../../database/";
  strcat(file_path, (char *)MALOP);
  strcat(file_path, ".d");
  
  f.open(file_path, ios::binary|ios::out);
  f.write((char *)&dsdk, sizeof(LinkedList<Student>));
  f.close();
}

