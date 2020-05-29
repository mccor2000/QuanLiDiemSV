#include "library.h"

void them_mh(DanhSachMonHoc& dsmh, char** data) {
  //tao mon hoc
  MonHoc mh(data[0],data[1],StringToInt(data[2]),StringToInt(data[3]));
  
  bool check = dsmh.is_exist(mh);
  if (check) return;

  dsmh.insert(mh);
}

void hieu_chinh_mh(DanhSachMonHoc& dsmh, char ** data_old, char ** data_new) {

  MonHoc mh_old(data_old[0],data_old[1],StringToInt(data_old[2]),StringToInt(data_old[3]));
  bool check = dsmh.is_exist(mh_old);

  if (!check) return;
  dsmh.remove(mh_old);

  MonHoc mh_new(data_new[0],data_new[1],StringToInt(data_new[2]),StringToInt(data_new[3]));
  dsmh.insert(mh_new);
}

void xoa_mh(DanhSachMonHoc& dsmh, char ** data) {

  MonHoc mh(data[0],data[1],StringToInt(data[2]),StringToInt(data[3]));
  bool check = dsmh.is_exist(mh);

  if (!check) return;
  dsmh.remove(mh);
}
