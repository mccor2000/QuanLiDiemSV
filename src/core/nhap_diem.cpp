#include "core.h"

void find_loptc(char ** data) {
    DanhSachLopTC temp_dsltc = database.get_dsltc();
    for (int i = 0; i < temp_dsltc.getN(); i++) {
      database.set_current_loptc(temp_dsltc.node[i]);
      LopTC * temp_loptc = database.get_current_loptc();
      if (strcmp(temp_loptc->nienkhoa, data[0]) == 0,
          temp_loptc->hocki == string_to_short(data[1]),
          temp_loptc->nhom == string_to_short(data[2]),
          strcmp(temp_loptc->maMH, data[3]) == 0
          )
      {
          break;
      }
    }
    database.set_current_dsdk(database.get_current_loptc()->dsdk);
}

void set_score(char ** data) {
  // current_svdk.set_DIEM(string_to_float(data[1]));
}

