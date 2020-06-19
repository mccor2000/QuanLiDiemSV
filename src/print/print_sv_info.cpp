#include "./print.h"

void print_sv_info(WINDOW * curr_win, int start_x, int start_y, SinhVien curr_sv) {
  mvwprintw(curr_win, start_y,     start_x, "Thong tin sinh vien: ");

  mvwprintw(curr_win, start_y + 2, start_x,      "MA SV: ");
  mvwprintw(curr_win, start_y + 2, start_x + 11, curr_sv.get_MASV());

  mvwprintw(curr_win, start_y + 3, start_x,      "HO: ");
  mvwprintw(curr_win, start_y + 3, start_x + 11, curr_sv.get_HO());

  mvwprintw(curr_win, start_y + 4, start_x,      "TEN: ");
  mvwprintw(curr_win, start_y + 4, start_x + 11, curr_sv.get_TEN());

  mvwprintw(curr_win, start_y + 5, start_x,      "GIOI TINH: ");
  mvwprintw(curr_win, start_y + 5, start_x + 11, (curr_sv.get_PHAI()) ? "Nam" : "Nu");

  mvwprintw(curr_win, start_y + 6, start_x,      "SDT: ");
  mvwprintw(curr_win, start_y + 6, start_x + 11, curr_sv.get_SDT());

  mvwprintw(curr_win, start_y + 7, start_x,      "MA LOP: ");
  mvwprintw(curr_win, start_y + 7, start_x + 11, curr_sv.get_MALOP());
  wrefresh(curr_win);
}
