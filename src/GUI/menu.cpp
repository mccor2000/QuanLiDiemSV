#include "./menu.h"

char * main_menu_items[] = {
  "Quan ly lop tin chi",
  "Quan ly lop chinh quy",
  "Quan ly mon hoc",
  "Nhap diem",
  "Dang ki",
  "Xem diem",
  "Thoat",
  (char *)NULL,
};

char * crud_menu_items[] = {
  "Them",
  "Hieu chinh",
  "Xoa",
  "Quay lai",
  (char *)NULL,
};

char * score_board_menu_items[] = {
  "Bang diem mon hoc",
  "Bang diem khoa hoc",
  "Bang diem tong ket",
  "Quay lai",
  (char *)NULL,
};

Menu::Menu(WINDOW * w, int t) {
  current_window = w;
  type = t;
  switch (type) {
    case 1: 
      len = 8; 
      break;
    case 2: 
    case 3:
      len = 5;
      break;
  }

  char ** items = get_items();
  ITEM **menu_items;
	
  menu_items = new ITEM*[len];
	for(int i = 0; i < len; ++i) {
    menu_items[i] = new_item(items[i], "");
  }
  menu = new_menu((ITEM **)menu_items);
}

char ** Menu::get_items() {
  switch (type) {
    case 1: return main_menu_items; 
    case 2: return crud_menu_items;
    case 3: return score_board_menu_items;
    default: return NULL;
  }
}

void Menu::display() {
  wclear(current_window);
  box(current_window, 0, 0);
  set_menu_win(menu, current_window);
  set_menu_sub(menu, derwin(current_window, 0, 0, 1, 1));
  post_menu(menu);
  wrefresh(current_window);
}

