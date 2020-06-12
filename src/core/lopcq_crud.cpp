#include "core.h"

void add_lopcq(char ** data){
    LopCQ new_lopcq(data[0]);
    database.dslcq.push_back(new_lopcq);
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
  SinhVien sv(
      upper_case_letters(data[0]),
      upper_case_letters(data[1]),
      upper_case_letters(data[2]),
      strcmp(upper_case_letters(data[3]), "NAM") == 0 ? 1 : 0, 
      data[4],
      database.get_current_lopcq()->get_data().MALOP
  );
  database.get_current_sv()->set_data(sv);
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
  database.get_current_dssv().remove(index);
}
