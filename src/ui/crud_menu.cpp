#include "ui.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

MENU * crud_menu() {
  char * choices[] = {
    "Them",
    "Hieu chinh",
    "Xoa",
    "Quay lai",
    (char *)NULL,
  };

  ITEM **my_items;
	MENU *my_menu;
  int n_choices, c;
	
  initscr();
	
	n_choices = ARRAY_SIZE(choices);
	my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));

	for(int i = 0; i < n_choices; ++i) {
    my_items[i] = new_item(choices[i], "");
  }

  endwin();
  return new_menu((ITEM **)my_items);
}
