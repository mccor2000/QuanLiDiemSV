#include "core.h"

void add_mh(char ** data) {
  MonHoc new_mh;
  new_mh.init_from_string(data);

  bool check = database.get_dsmh().is_exist(new_mh);
  if (check) return;
  database.get_dsmh().insert(new_mh);
}

void update_mh(char ** data) {
  MonHoc old_mh = *database.get_dsmh().search_code(data[0]);
  database.get_dsmh().remove(old_mh);
  add_mh(data);
}

void delete_mh(char * ma_mh) {
  MonHoc chosen_one = *database.get_dsmh().search_code(ma_mh);
  database.get_dsmh().remove(chosen_one);
}
