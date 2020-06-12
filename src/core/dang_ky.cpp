#include "core.h"

//loc cac lop theo nien khoa va hoc ki
void filter_dsltc(char ** data) {
  DanhSachLopTC temp_dsltc = database.dsltc;
  for (int i = 0; i < temp_dsltc.getN(); i++) {
    LopTC curr_loptc = *temp_dsltc.get_by_id(i);
    if (strcmp(curr_loptc.nienkhoa, data[0]) == 0 && curr_loptc.hocki == string_to_short(data[1])) {
      database.get_filtered_dsltc().themLop(curr_loptc, database.get_filtered_dsltc().getN());
    }
  }
}

//dang ky lop cho SV
void dang_ky(char * data) {
  database.get_current_dsdk()->push_back(SinhVienDK(data));
  return;
}
