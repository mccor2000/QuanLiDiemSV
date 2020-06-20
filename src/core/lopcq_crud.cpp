#include "core.h"

void add_lopcq(char ** data) {
    LopCQ new_lopcq(data[0]);
    database.dslcq.push_back(new_lopcq);
}

void find_lopcq(char ** data) {
  database.set_current_lopcq(upper_case_letters(data[0]));
}

void add_sv(char ** data) {
  // Tao sinh vien
  SinhVien sv(
      upper_case_letters(data[0]),
      upper_case_letters(data[1]),
      upper_case_letters(data[2]),
      strcmp(upper_case_letters(data[3]), "NAM") == 0 ? 1 : 0, 
      data[4],
      database.get_current_lopcq()->get_data().MALOP
  );
  database.get_current_dssv()->push_back(sv);
}

void update_sv(char ** data) {
  SinhVien process_sv = database.get_current_sv()->get_data();
  SinhVien sv(
      upper_case_letters(data[0]),
      upper_case_letters(data[1]),
      upper_case_letters(data[2]),
      strcmp(upper_case_letters(data[3]), "NAM") == 0 ? 1 : 0, 
      data[4],
      database.get_current_lopcq()->get_data().MALOP
  );
  sv.DS_LOPTC = process_sv.DS_LOPTC;
  database.get_current_sv()->set_data(sv);
  //****** Handle update data sv in LTC classes *******/
  LinkedList<int> *process_dsmh = process_sv.DS_LOPTC;
  Node<int> *mh_in_list = process_dsmh->head();
  while(mh_in_list != NULL){
    LopTC * process_LTC = database.
                            dsltc.get_by_id(
                                    database.
                                      dsltc.
                                        search(mh_in_list->get_data())
                                    );
    DanhSachSinhVienDK * process_dsdk = process_LTC->dsdk;
    Node<SinhVienDK> * tmp_svdk = process_dsdk->head();
    while(tmp_svdk != NULL){
      if(! strcmp(tmp_svdk->get_data().get_MASV(), process_sv.get_MASV())){
        tmp_svdk->set_data(upper_case_letters(data[0]));
      }
      tmp_svdk = tmp_svdk->get_next();
    }
    mh_in_list = mh_in_list->get_next();
  }
  
}

void search_sv(char ** data) {
  Node<LopCQ> * curr_lopcq = database.dslcq.head();

  while (curr_lopcq != NULL) {
    Node<SinhVien> * temp_sv = curr_lopcq->get_data().DSSV->head();
    while(temp_sv != NULL) {
      if (strcmp(upper_case_letters(temp_sv->get_data().get_MASV()), upper_case_letters(data[0])) == 0) {
        database.set_current_sv(temp_sv);
        return;
      }
      temp_sv = temp_sv->get_next();
    } 
    curr_lopcq = curr_lopcq->get_next();
  }
}

void delete_sv(int index) {
  //****** Handle delete data sv in LTC classes *******/
  SinhVien process_sv = database.get_current_sv()->get_data();
  LinkedList<int> *process_dsmh = process_sv.DS_LOPTC;
  Node<int> *mh_in_list = process_dsmh->head();
  while(mh_in_list != NULL){
    LopTC * process_LTC = database.
                            dsltc.get_by_id(
                                    database.
                                      dsltc.
                                        search(mh_in_list->get_data())
                                    );
    DanhSachSinhVienDK * process_dsdk = process_LTC->dsdk;
    database.set_current_dsdk(process_dsdk);
    mh_in_list = mh_in_list->get_next();
  }
  database.get_current_dsdk()->remove(index);
  database.get_current_dssv()->remove(index);
}
