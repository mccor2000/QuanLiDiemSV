#include "core.h"

void add_loptc(char ** data) {
    LopTC loptc(
        upper_case_letters(data[0]),
        upper_case_letters(data[1]),
        string_to_short(data[2]),
        string_to_short(data[3]),
        string_to_int(data[4]),
        string_to_int(data[5])
    );
    database.dsltc.themLop(loptc, database.dsltc.getN());
}

void update_loptc(char ** data) {
  strcpy(database.get_current_loptc()->maMH, upper_case_letters(data[0]));
  strcpy(database.get_current_loptc()->nienkhoa, data[1]);
  database.get_current_loptc()->hocki = string_to_short(data[2]);
  database.get_current_loptc()->nhom= string_to_short(data[3]);
  database.get_current_loptc()->sv_min = string_to_int(data[4]);
  database.get_current_loptc()->sv_max = string_to_int(data[5]);
}

void delete_loptc() {
  database.dsltc.xoaLop(database.get_current_loptc()->malop);
}

void delete_svdk(int index) {
  DanhSachSinhVienDK *process_dsdk = database.get_current_loptc()->dsdk;
  int counter=0; // counter === min index on Your Table
  Node<SinhVienDK> *process_svdk = process_dsdk->head();
  // get SVDK on the table by index
  while(process_svdk != NULL && counter<index){
    counter++;
    process_svdk = process_svdk->get_next();
  }
  SinhVien process_sv;
  // From Code SVDK, Search this fuking student
  Node<LopCQ> *process_lcq = database.dslcq.head();
  while(process_lcq != NULL){
    Node<SinhVien> *tmp_sv= process_lcq->get_data().DSSV->head();
    while(tmp_sv!= NULL ){
      if(! strcmp(tmp_sv->get_data().get_MASV(),process_svdk->get_data().get_MASV())){
        tmp_sv= tmp_sv->get_next();
        break;
      }
      tmp_sv= tmp_sv->get_next();
    }
    process_sv= tmp_sv->get_data();
    process_lcq = process_lcq->get_next();
  }
  

  // Remove this LTC in DSLTC's student 
  LinkedList<int> *process_DSLTC = process_sv.DS_LOPTC;
  Node<int> *process_code = process_DSLTC->head();
  int pos=0;
  while(process_code!=NULL && process_code->get_data() == database.get_current_loptc()->malop ){
    pos++;
    process_code = process_code->get_next();
  }
  process_DSLTC->remove(pos);
  database.get_current_loptc()->dsdk->remove(index);
}
