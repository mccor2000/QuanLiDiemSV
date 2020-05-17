#include "ui.h"

void print_in_middle(WINDOW *win, int starty, int startx, int width, char * string, chtype color) {
  int length, x, y;
  float temp;

  if (win == NULL) win = stdscr;
  
  getyx(win, y, x);
  if (startx != 0) x = startx;
  if (starty != 0) y = starty;
  if (width == 0) width = 80;
  
  length = strlen(string);
  temp = (width - length)/2;

  x = startx + (int)temp;
  mvwprintw(win, y, x, "%s", string);
  refresh();
}
