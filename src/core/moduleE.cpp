#include "library.h"

void add_mh(char ** data) {
  MonHoc new_mh;
  new_mh.init_from_string(data);

  bool check = dsmh.is_exist(new_mh);
  if (check) return;
  dsmh.insert(new_mh);
}

<<<<<<< HEAD
// void update_mh(char ** data) {
  // MonHoc old_mh = dsmh.search_code(data[0]);
  // dsmh.remove(old_mh);

  // add_mh(data);
// }

// void delete_mh(char * ma_mh) {
  // MonHoc chosen_one = dsmh.search_code(chosen_one);
  // dsmh.remove(chosen_one);
// }
=======
void update_mh(char ** data) {
  MonHoc old_mh = *dsmh.search_code(data[0]);
  dsmh.remove(old_mh);
  add_mh(data);
}

void delete_mh(char * ma_mh) {
  MonHoc chosen_one = *dsmh.search_code(ma_mh);
  dsmh.remove(chosen_one);
}
>>>>>>> 526f463e8ee00cf72572fa86f0ff9a117a775db5
