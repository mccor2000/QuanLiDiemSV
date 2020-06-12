#include "core.h"

void add_mh(char ** data) {
  MonHoc new_mh(
      data[0], 
      data[1], 
      string_to_int(data[2]), 
      string_to_int(data[3])
  );
  
  bool check = database.dsmh.is_exist(new_mh);
  if (check) return;
  else database.dsmh.insert(new_mh);
}

void delete_mh() {
  database.dsmh.remove(database.get_current_mh());
}

void update_mh(char ** data) {
  delete_mh();
  add_mh(data);
}

