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
  database.dsmh.insert(new_mh);
}

void update_mh(char ** data) {
  database.dsmh.remove(
      MonHoc(
        data[0], 
        data[1], 
        string_to_int(data[2]), 
        string_to_int(data[3])
      )
  );
  add_mh(data);
}

void delete_mh() {
  database.dsmh.remove(database.get_current_mh());
}
