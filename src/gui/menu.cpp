#include "./menu.h"

char * crud_menu_items[] = {
  "Them",
  "Hieu chinh",
  "Xoa",
  "Quay lai",
};

char * main_menu_items[] = {
  "Quan ly lop tin chi",
  "Quan ly lop chinh quy",
  "Quan ly mon hoc",
  "Nhap diem",
  "Dang ki",
  "Thoat",
};

Menu::Menu(WINDOW * w, int t) {
  current_window = w;
  type = t;
  if (t == 1) len = 6;
  if (t == 2) len = 4;

  char ** items = get_items();
  ITEM **menu_items;
	
	menu_items = (ITEM **)calloc(len, sizeof(ITEM *));
	for(int i = 0; i < len; ++i) {
    menu_items[i] = new_item(items[i], "");
  }
  menu = new_menu((ITEM **)menu_items);
}

char ** Menu::get_items() {
  if (type == 1) return main_menu_items;
  if (type == 2) return crud_menu_items;
  return NULL;
}

void Menu::display() {
  wclear(current_window);
  box(current_window, 0, 0);
  set_menu_win(menu, current_window);
  set_menu_sub(menu, derwin(current_window, 0, 0, 1, 1));
  post_menu(menu);
  wrefresh(current_window);
}

