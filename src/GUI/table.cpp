#include "./table.h"

Table::Table(WINDOW * win) {
  current_window = win;
  getmaxyx(win, height, width);

  length = 0;
  start_index = 0;
  end_index = (height - 5) / 2 - 1;
  current_index = 0;
}

// Draw column seperator
void Table::draw_column_seperator(int ycoord) {
  int current_xcoord = 0;
  mvwhline(current_window, ycoord - 1, 1, 0, width - 2);
  mvwhline(current_window, ycoord + 1, 1, 0, width - 2);
  for (int i = 0; i < fields_len; i++) {
    if (i > 0) {
      mvwaddch(current_window, ycoord - 1, current_xcoord, ACS_TTEE);
      mvwaddch(current_window, ycoord, current_xcoord, ACS_VLINE);
      mvwaddch(current_window, ycoord + 1, current_xcoord, ACS_PLUS);
    }
    current_xcoord += average_width + 1;
  }
  wrefresh(current_window);
}

void Table::draw_column(int ycoord, char ** data) {
  int current_xcoord = 0;
  mvwhline(current_window, ycoord - 1, 1, 0, width - 2);
  mvwhline(current_window, ycoord + 1, 1, 0, width - 2);

  for (int i = 0; i < fields_len; i++) {
    if (i > 0) {
      mvwaddch(current_window, ycoord - 1, current_xcoord, ACS_TTEE);
      mvwaddch(current_window, ycoord, current_xcoord, ACS_VLINE);
      mvwaddch(current_window, ycoord + 1, current_xcoord, ACS_PLUS);
    }
    mvwprintw(current_window, ycoord, current_xcoord + 1, data[i]);
    current_xcoord += average_width + 1;
  }
  wrefresh(current_window);
}

// Get input
short Table::get_input() {
  input = getch();
  switch (input) {
    case KEY_UP:
      if (current_index > start_index) {
        current_index--;
      } else if (start_index > 0) {
        start_index --;
        end_index --;
        current_index = start_index;  
      }
      break;
   
    case KEY_DOWN:
      if (current_index >= length - 1) break;
      if (current_index < end_index) { 
        current_index ++;
      } else if (end_index < length) {
        start_index ++;
        end_index ++;
        current_index = end_index;
      }
      break;

    case 10:
      return 1;

    case KEY_LEFT:
      return 2;

    case 27:
      return 3;
  }

  return 0;
}
