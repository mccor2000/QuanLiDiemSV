#include "library.h"

void add_loptc(char ** data) {
    LopTC loptc(
        upper_case_letters(data[0]),
        upper_case_letters(data[1]),
        string_to_short(data[2]),
        string_to_short(data[3]),
        string_to_int(data[4]),
        string_to_int(data[5])
    );
    dsltc.themLop(loptc, dsltc.getN());
}

void update_loptc(char ** data) {
  strcpy(current_loptc->maMH, upper_case_letters(data[1]));
  strcpy(current_loptc->nienkhoa, data[2]);
  current_loptc->hocki = string_to_short(data[3]);
  current_loptc->nhom= string_to_short(data[4]);
  current_loptc->sv_min = string_to_int(data[5]);
  current_loptc->sv_max = string_to_int(data[6]);
}

void delete_loptc(int ma_lop_tc) {
  dsltc.xoaLop(ma_lop_tc);
}

