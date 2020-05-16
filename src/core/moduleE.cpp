#include "library.h"

void them_mh(DanhSachMonHoc& dsmh, MonHoc new_mh) {
  bool check = dsmh.is_exist(new_mh);

  if (check) return;
  dsmh.insert(new_mh);
}

void hieu_chinh_mh(DanhSachMonHoc& dsmh, MonHoc old_mh, MonHoc new_mh) {
  bool check = dsmh.is_exist(old_mh);

  if (!check) return;
  dsmh.remove(old_mh);
  dsmh.insert(new_mh);
}

void xoa_mh(DanhSachMonHoc& dsmh, MonHoc mh) {
  bool check = dsmh.is_exist(mh);

  if (!check) return;
  dsmh.remove(mh);
}
