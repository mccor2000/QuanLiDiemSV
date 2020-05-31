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

// UI
void print_dsltc(WINDOW * current_window, int average_width, int width) {
  int length = dsltc.getN();  
  
  int current_yCoord = 5;
  for (int i = 0; i < length; i++) {
    LopTC * curr_loptc = dsltc.node[i];
    mvwprintw(current_window, current_yCoord, 1 + average_width * 0, curr_loptc->maMH);
    mvwprintw(current_window, current_yCoord, 1 + average_width * 1, curr_loptc->nienkhoa);
    mvwprintw(current_window, current_yCoord, 1 + average_width * 2, std::to_string(curr_loptc->hocki).c_str());
    mvwprintw(current_window, current_yCoord, 1 + average_width * 3, std::to_string(curr_loptc->nhom).c_str());
    mvwprintw(current_window, current_yCoord, 1 + average_width * 4, std::to_string(curr_loptc->sv_min).c_str());
    mvwprintw(current_window, current_yCoord, 1 + average_width * 5, std::to_string(curr_loptc->sv_max).c_str());

    mvwhline(current_window, current_yCoord + 1, 1, 0, width - 2);
    current_yCoord += 2;
  }
  wrefresh(current_window);
}
