#include "core.h"

void find_loptc(char ** data) {
  for (int i = 0; i < database.dsltc.getN(); i++) {
    LopTC * temp_loptc = database.dsltc.node[i];
    
    if (
        strcmp(temp_loptc->nienkhoa, data[0]) == 0 && 
        temp_loptc->hocki == string_to_short(data[1]) && 
        temp_loptc->nhom == string_to_short(data[2]) && 
        strcmp(upper_case_letters(temp_loptc->maMH), upper_case_letters(data[3])) == 0 
    ) {
      database.set_current_dsdk(database.dsltc.node[i]->dsdk);
      break;
    }
  }
}

void set_score(char ** data) {
  char * ma_sv = database.get_current_svdk()->get_data().get_MASV();
  database.get_current_svdk()->set_data(SinhVienDK(ma_sv, string_to_float(data[0])));
}

