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
  //******* handle delete LTC classes which have same code *******.
  MonHoc process_mh = database.get_current_mh();
  for(int i=0;i<database.dsltc.getN();i++){
    LopTC* process_LTC = database.dsltc.node[i];
    if(! strcmp(process_LTC->maMH,process_mh.MAMH)){
      database.set_current_loptc(process_LTC);
      delete_loptc();
    }
  }
  /// End handle
  database.dsmh.remove(database.get_current_mh());
}

void update_mh(char ** data) {
  delete_mh();
  add_mh(data);
}

