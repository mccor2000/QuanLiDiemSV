#include "library.h"

void add_sv(char ** data) {
  // Tao sinh vien
  SinhVien sv(
      upper_case_letters(data[0]),
      upper_case_letters(data[1]),
      upper_case_letters(data[2]),
      strcmp(upper_case_letters(data[3]), "NAM") == 0 ? 1 : 0, 
      data[4],
      current_lopcq.MALOP
  );
  current_dssv->push_back(sv);
}

void update_sv(char ** data) {
  current_sv->get_data().set_MASV(upper_case_letters(data[0]));
  current_sv->get_data().set_HO(upper_case_letters(data[1]));
  current_sv->get_data().set_TEN(upper_case_letters(data[2]));
  current_sv->get_data().set_PHAI(strcmp(upper_case_letters(data[3]), "NAM") == 0 ? 1 : 0);
  current_sv->get_data().set_SDT(upper_case_letters(data[4]));
}

void search_sv(char ** data) {
  Node<LopCQ> * curr_lopcq = dslcq.head();

  while (curr_lopcq != NULL) {
    Node<SinhVien> * temp_sv = curr_lopcq->get_data().DSSV->head();
    while(temp_sv != NULL) {
      if (strcmp(upper_case_letters(temp_sv->get_data().get_MASV()), upper_case_letters(data[0])) == 0) {
        current_sv->set_data(temp_sv->get_data());
        return;
      }
      temp_sv = temp_sv->get_next();
    } 
    curr_lopcq = curr_lopcq->get_next();
  }
}
