#include "core.h"

//loc cac lop theo nien khoa va hoc ki
void filter_dsltc(char ** data) {
  DanhSachLopTC temp_dsltc = database.dsltc;
  for (int i = 0; i < temp_dsltc.getN(); i++) {
    LopTC curr_loptc = *temp_dsltc.get_by_id(i);
    if (strcmp(curr_loptc.nienkhoa, data[0]) == 0 && curr_loptc.hocki == string_to_short(data[1])) {
      database.filtered_dsltc.themLop(curr_loptc, database.filtered_dsltc.getN());
    }
  }
}

//dang ky lop cho SV
bool dang_ky(char * data) {
  Node<SinhVienDK> * curr_node = database.get_current_dsdk()->p_head_;
  while (curr_node != NULL) {
    if (strcmp(curr_node->get_data().get_MASV(), data) == 0) return false;
    curr_node = curr_node->get_next();
  }

  database.get_current_dsdk()->push_back(SinhVienDK(data));
  database.get_current_sv()->get_data().DS_LOPTC->push_back(database.get_current_loptc()->malop);
  return true;
}
