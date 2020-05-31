#include "library.h"

void add_loptc(char ** data) {
    LopTC loptc(
        data[0],data[1],
        string_to_short(data[2]),
        string_to_short(data[3]),
        string_to_int(data[4]),
        string_to_int(data[5])
    );
    dsltc.themLop(loptc, dsltc.getN());
}

void delete_loptc(int ma_lop_tc) {
  dsltc.xoaLop(ma_lop_tc);
}

void update_loptc(char ** data) {
  delete_loptc(string_to_int(data[0]));
  add_loptc(data);
}

