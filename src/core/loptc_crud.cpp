#include "core.h"

bool add_loptc(char ** data) {
    LopTC loptc(
        upper_case_letters(data[0]),
        upper_case_letters(data[1]),
        string_to_short(data[2]),
        string_to_short(data[3]),
        string_to_int(data[4]),
        string_to_int(data[5])
    );

    for (int i = 0; i < database.dsltc.getN(); i++) {
      if (strcmp(database.dsltc.node[i]->maMH, loptc.maMH) == 0 &&
          strcmp(database.dsltc.node[i]->nienkhoa, loptc.nienkhoa) == 0 &&
          database.dsltc.node[i]->hocki == loptc.hocki &&
          database.dsltc.node[i]->nhom == loptc.nhom
      ) {
        return false;
      }
    }
    
    if (!database.dsmh.search_code(upper_case_letters(data[0])))
      return false;

    database.dsltc.themLop(loptc, database.dsltc.getN()); 
    return true;
}

bool update_loptc(char ** data) {

  LopTC loptc(
      upper_case_letters(data[0]),
      upper_case_letters(data[1]),
      string_to_short(data[2]),
      string_to_short(data[3]),
      string_to_int(data[4]),
      string_to_int(data[5])
  );
  for (int i = 0; i < database.dsltc.getN(); i++) {
    if (strcmp(database.dsltc.node[i]->maMH, loptc.maMH) == 0 &&
        strcmp(database.dsltc.node[i]->nienkhoa, loptc.nienkhoa) == 0 &&
        database.dsltc.node[i]->hocki == loptc.hocki &&
        database.dsltc.node[i]->nhom == loptc.nhom
    ) {
      if (database.get_current_loptc()->malop == database.dsltc.node[i]->malop) {
        database.get_current_loptc()->sv_min = string_to_int(data[4]);
        database.get_current_loptc()->sv_max = string_to_int(data[5]);
        return true;
      }
      return false;
    }
  }

  strcpy(database.get_current_loptc()->maMH, upper_case_letters(data[0]));
  strcpy(database.get_current_loptc()->nienkhoa, data[1]);
  database.get_current_loptc()->hocki = string_to_short(data[2]);
  database.get_current_loptc()->nhom= string_to_short(data[3]);
  database.get_current_loptc()->sv_min = string_to_int(data[4]);
  database.get_current_loptc()->sv_max = string_to_int(data[5]);

  return true;
}

void delete_loptc() {
  database.dsltc.xoaLop(database.get_current_loptc()->malop);
}

void delete_svdk(int index) {
  int current_ma_loptc = database.get_current_loptc()->malop;
  // Set current SV
  database.set_current_sv(database.get_current_svdk()->get_data().get_MASV());
  
  // Delete LOPTC in DS_LTC
  int ma_loptc_index = 0;
  Node<int> * current_node = database.get_current_sv()->get_data().DS_LOPTC->head();
  while (current_node != NULL) {
    if (current_ma_loptc == current_node->get_data()) break; 

    ma_loptc_index++;
    current_node = current_node->get_next();
  }
  database.get_current_sv()->get_data().DS_LOPTC->remove(ma_loptc_index);
  
  // Delete SVDK 
  database.get_current_loptc()->dsdk->remove(index);
}
