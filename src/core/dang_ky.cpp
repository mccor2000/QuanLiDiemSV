#include "core.h"

//loc cac lop theo nien khoa va hoc ki
bool filter_dsltc(char ** data) {
  database.filtered_dsltc = new DanhSachLopTC;
  for (int i = 0; i < database.dsltc.getN(); i++) {
    if (
        strcmp(database.dsltc.node[i]->nienkhoa, data[0]) == 0 && 
        database.dsltc.node[i]->hocki == string_to_short(data[1]) &&
        !database.get_current_sv()->get_data().DS_LOPTC->is_exist(database.dsltc.node[i]->malop)
    ) {
      database.filtered_dsltc->insertSpecial(database.dsltc.node[i]);
    }
  }
  return true;
}

//dang ky lop cho SV
bool dang_ky(char * data) {
  if (database.get_current_loptc()->dsdk->count()==database.get_current_loptc()->sv_max) {
    return false;
  }
  
  database.set_current_dsdk(database.get_current_loptc()->dsdk);
  database.get_current_dsdk()->push_back(SinhVienDK(data));

  database.set_current_sv(data);
  int ma_lop = database.get_current_loptc()->malop;
  database.get_current_sv()->get_data().DS_LOPTC->push_back(ma_lop);
  
  if (database.get_current_loptc()->dsdk->count()>=database.get_current_loptc()->sv_min) {
    database.get_current_loptc()->huylop = false;
  }
  return true;
}
