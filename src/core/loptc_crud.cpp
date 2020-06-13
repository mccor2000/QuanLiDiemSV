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
  database.get_current_loptc()->dsdk->remove(index);
}
