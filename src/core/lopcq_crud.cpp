#include "core.h"

bool add_lopcq(char ** data) {
    LopCQ new_lopcq(data[0]);
    database.dslcq.push_back(new_lopcq);
}

// void find_lopcq(char ** data) {
  // database.set_current_lopcq(upper_case_letters(data[0]));
// }

bool add_sv(char ** data) {
  // Tao sinh vien
  SinhVien sv(
      upper_case_letters(data[0]),
      upper_case_letters(data[1]),
      upper_case_letters(data[2]),
      strcmp(upper_case_letters(data[3]), "NAM") == 0 ? 1 : 0, 
      data[4],
      database.get_current_lopcq()->get_data().MALOP
  );
  if (!database.get_current_dssv()->is_exist(sv)) {
    database.get_current_dssv()->push_back(sv);
    return true;
  }
  return false;
}

bool update_sv(char ** data) {
  // Update SV
  SinhVien old_sv_data = database.get_current_sv()->get_data();
  SinhVien new_sv_data(
      upper_case_letters(data[0]),
      upper_case_letters(data[1]),
      upper_case_letters(data[2]),
      strcmp(upper_case_letters(data[3]), "NAM") == 0 ? 1 : 0, 
      data[4],
      database.get_current_lopcq()->get_data().MALOP
  );

  if (database.get_current_dssv()->is_exist(new_sv_data)) {
    return false;
  }

  new_sv_data.DS_LOPTC = old_sv_data.DS_LOPTC;
  database.get_current_sv()->set_data(new_sv_data);
  
  // Update DSLTC
  Node<int> * current_ma_loptc= old_sv_data.DS_LOPTC->head();
  while (current_ma_loptc != NULL) {
    Node<SinhVienDK> * current_svdk = database
                                        .dsltc
                                        .get_by_id(database.dsltc.search(current_ma_loptc->get_data()))
                                        ->dsdk
                                        ->head();
    // Loop through DSDK
    while(current_svdk != NULL){
      if (strcmp(current_svdk->get_data().get_MASV(), old_sv_data.get_MASV()) == 0) {
        SinhVienDK new_svdk_data(
            upper_case_letters(data[0]), 
            current_svdk->get_data().get_DIEM()
        );
        current_svdk->set_data(new_svdk_data);
      }
      current_svdk = current_svdk->get_next();
    }
    current_ma_loptc = current_ma_loptc->get_next();
  }
  return true; 
}

bool search_sv(char ** data) {
  Node<LopCQ> * curr_lopcq = database.dslcq.head();

  while (curr_lopcq != NULL) {
    Node<SinhVien> * temp_sv = curr_lopcq->get_data().DSSV->head();
    while(temp_sv != NULL) {
      if (strcmp(upper_case_letters(temp_sv->get_data().get_MASV()), upper_case_letters(data[0])) == 0) {
        database.set_current_sv(temp_sv);
        return true;
      }
      temp_sv = temp_sv->get_next();
    } 
    curr_lopcq = curr_lopcq->get_next();
  }
  return false;
}

void delete_sv(int index) {
  database.set_current_sv(index);
  SinhVien current_sv_data = database.get_current_sv()->get_data();

  // Delete all appearances of SV in DSLTC
  Node<int> * current_ma_loptc = database.get_current_sv()->get_data().DS_LOPTC->head();
  while (current_ma_loptc != NULL) {
    database.set_current_loptc(database.dsltc.search(current_ma_loptc->get_data()));
    // Get index in DSDK
    Node<SinhVienDK> * current_svdk = database.get_current_dsdk()->head();
    int svdk_index = 0;
    while (current_svdk != NULL) {
      if (strcmp(current_svdk->get_data().get_MASV(), current_sv_data.get_MASV()) == 0) break;

      svdk_index++;
      current_svdk = current_svdk->get_next();
    }

    // Perform delete
    database.get_current_dsdk()->remove(svdk_index);

    current_ma_loptc = current_ma_loptc->get_next();
  }
  database.get_current_dssv()->remove(index);
}
