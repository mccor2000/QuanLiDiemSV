#include "library.h"

void add_loptc(char ** data) {
    LopTC loptc(
        data[0],
        data[1],
        string_to_short(data[2]),
        string_to_short(data[3]),
        string_to_int(data[4]),
        string_to_int(data[5])
    );
    dsltc.themLop(loptc, dsltc.getN());
}

void update_loptc(char ** data) {
  int ma_lop_tc = string_to_int(trim_whitespaces(data[0]));
  database.get_dsltc().xoaLop(ma_lop_tc);
  add_loptc(data);
}

void delete_loptc(int ma_lop_tc) {
  database.get_dsltc().xoaLop(ma_lop_tc);
}

