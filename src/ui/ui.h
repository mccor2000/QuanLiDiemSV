#include <iostream>
#include <cstring>
#include <ncurses.h>
#include <menu.h>
#include <panel.h>

void print_in_middle(WINDOW * win, int starty, int startx, int width, char * string, chtype color);

MENU * main_menu();
MENU * crud_menu();
