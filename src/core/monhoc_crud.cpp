#include "core.h"

bool add_mh(char ** data) {
  MonHoc new_mh(
      upper_case_letters(data[0]), 
      upper_case_letters(data[1]), 
      string_to_int(data[2]), 
      string_to_int(data[3])
  );
  
  if(database.dsmh.search_code(new_mh);
  if (check) return false;
  
  database.dsmh.insert(new_mh);
  return true;
}

void delete_mh() {
  //******* handle delete LTC classes which have same code *******.
  // MonHoc process_mh = database.get_current_mh();
  // for(int i=0;i<database.dsltc.getN();i++){
    // LopTC* process_LTC = database.dsltc.node[i];
    // if(! strcmp(process_LTC->maMH,process_mh.MAMH)){
      // database.set_current_loptc(process_LTC);
      // delete_loptc();
    // }
  // }
  // End handle
  database.dsmh.remove(database.get_current_mh());
}

bool update_mh(char ** data) {
  MonHoc new_mh(
      upper_case_letters(data[0]), 
      upper_case_letters(data[1]), 
      string_to_int(data[2]), 
      string_to_int(data[3])
  );
  bool check = database.dsmh.is_exist(new_mh);
  if (check) return false;

  delete_mh();
  database.dsmh.insert(new_mh);
  return true;
}

