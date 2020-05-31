#include "./GUI/table.h"
#include "./GUI/menu.h"
#include "./GUI/form.h"

#include "./core/library.h"

DanhSachLopTC dsltc;
DanhSachLopCQ dslcq;
DanhSachMonHoc dsmh;

// Chooses's code
const short CHOOSE_QLLTC = 1;
const short CHOOSE_QLLCQ = 2;
const short CHOOSE_QLMH = 3;
const short CHOOSE_NHAP_DIEM = 4;
const short CHOOSE_DANG_KY = 5;
const short CHOOSE_XEM_DIEM = 6;
const short CHOOSE_THOAT = 7;

const short CHOOSE_THEM = 8;
const short CHOOSE_CHINH_SUA = 9;
const short CHOOSE_XOA = 10;
const short CHOOSE_QUAY_LAI = 11;

const short CHOOSE_BANG_DIEM_MON_HOC = 12;
const short CHOOSE_BANG_DIEM_KHOA_HOC = 13;
const short CHOOSE_BANG_DIEM_TONG_KET = 14;
// App's state
const short DSLTC = 1;
const short DSLCQ = 2;
const short DSMH = 3;
const short DSSV = 4;
const short DSDK = 5;
const short NHAP_DIEM = 6;
const short DANG_KI = 7;
const short XEM_DIEM = 8;

class App {
private:
  bool is_running;
  short choice, state;
  // Database
  DanhSachLopTC dsltc;
  DanhSachLopCQ dslcq;
  DanhSachMonHoc dsmh;

  // UI
  WINDOW * wins[2];

  Menu current_menu;
  Table current_table;
  Form current_form;
  
  Form get_form();
  Table get_table();
    
  void render_menu(Menu);
  void render_table();
  void render_form();

  void process_input();
  void process_menu();
  void process_form(FORM *);
  
public:
  App();
  void run();
  void exit();
};

App::App() {
  is_running = true;
  dsltc.load();
  dslcq.load();
  dsmh.load();
  //-- Main screen
  initscr();
  clear();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  int row, column;
  getmaxyx(stdscr, row, column);
  //-- Menu window
  wins[0] = newwin(row, (int)column/4, 0, 0);
  keypad(wins[0], TRUE);
  box(wins[0], 0, 0);
  wrefresh(wins[0]);
  //-- Display window
  wins[1] = newwin(row, (int)(3*column)/4, 0, (int)column/4 + 1);
  keypad(wins[1], TRUE);
  box(wins[1], 0, 0);
  wrefresh(wins[1]);
  
  refresh();
  current_menu = Menu(wins[0], 1);
}

Form App::get_form() {
  Form form(wins[1]);
  switch (state) {
    case DSLTC: 
      form.set_type(1);
      form.set_len(6);
      if (choice == CHOOSE_THEM) form.set_submit(add_loptc);
      if (choice == CHOOSE_CHINH_SUA) form.set_submit(update_loptc);
      break;
    case DSLCQ:
      form.set_type(2);
      form.set_len(1);
      form.set_submit(NULL);
      break;
    case DSMH: 
      form.set_type(3);
      form.set_len(4);
      form.set_submit(add_mh);
      break;
    case DSSV:
      form.set_type(4);
      form.set_len(4);
      form.set_submit(NULL);
      break;
    case NHAP_DIEM:
      form.set_type(5);
      form.set_len(4);
      form.set_submit(NULL);
      break;
    case DANG_KI:
      form.set_type(6);
      form.set_len(2);
      form.set_submit(NULL);
      break;
  }
  return form;
}

Table App::get_table() {
  wclear(wins[1]);
  Table table(wins[1]);
  switch (choice) {
    case CHOOSE_QLLTC:
      table.set_type(1);
      table.set_title("DANH SACH LOP TIN CHI");
      break;
    case CHOOSE_QLLCQ:
      table.set_type(2);
      table.set_title("DANH SACH LOP CHINH QUY");
      break;
    case CHOOSE_QLMH:
      table.set_type(3);
      table.set_title("DANH SACH MON HOC");
      break;
  }
  return table;
}

void App::render_menu(Menu new_menu) {
  unpost_menu(current_menu.menu);
  current_menu = new_menu;
  current_menu.display();
}

void App::render_table() {
  wclear(wins[1]);
  current_table = get_table();
  current_table.display();
}

void App::render_form() {
  wclear(wins[1]);
  current_form = get_form();
  current_form.display();
}

void App::process_menu() {
  switch (choice) {
    case CHOOSE_QLLTC:
      state = DSLTC;
      render_menu(Menu(wins[0], 2));
      render_table();
      current_table.render_dsltc();
      break;

    case CHOOSE_QLLCQ:
      state = DSLCQ;
      render_menu(Menu(wins[0], 2));
      render_table();
      current_table.render_dslcq(DanhSachLopChinhQuy(dslcq));
      break;

    case CHOOSE_QLMH:
      state = DSMH;
      render_menu(Menu(wins[0], 2));
      render_table();
      current_table.render_dsmh(dsmh);
      break;
    
    case CHOOSE_NHAP_DIEM: {
      state = NHAP_DIEM;
      render_form(); 
      break;
    }

    case CHOOSE_DANG_KY: {
      char ma_sv[15];
      SinhVien * sv = NULL;
      wclear(wins[1]); 
      do {
        mvwprintw(wins[1], 1, 1, "Nhap ma SV: ");
        mvwscanw(wins[1], 1, 12, "%s", ma_sv);
        sv = dslcq.search_sv(ma_sv);
        if (!sv) mvwprintw(wins[1], 2, 1, "Sinh vien khong ton tai!");
        else sv->print_info(wins[1]);
      } while (!sv);
      state = DANG_KI;
      render_form();
      current_form.process_input();
      break;
    }

    case CHOOSE_XEM_DIEM: 
      state = XEM_DIEM;
      render_menu(Menu(wins[0], 3));
      break;

    case CHOOSE_THOAT:
      is_running = false;
      break;

    case CHOOSE_THEM: {
      render_form();
      bool done = current_form.process_input();
      current_table.display();
      wrefresh(wins[1]);
      break;
    }

    case CHOOSE_CHINH_SUA: {
      render_form();
      current_form.process_input();
      break;
    }

    case CHOOSE_XOA:
      break;

    case CHOOSE_QUAY_LAI:
      unpost_menu(current_menu.menu);
      current_menu = Menu(wins[0], 1);
      current_menu.display();
      break;
  }  
}

void App::process_input() {
  int input;
  while(input = wgetch(wins[0])) {
    switch (input) {
      case KEY_UP:
        menu_driver(current_menu.menu, REQ_UP_ITEM);
        break;  
      case KEY_DOWN:
        menu_driver(current_menu.menu, REQ_DOWN_ITEM);
        break;
      case 10:
        switch (current_menu.type) {
          case 1:
            choice = item_index(current_item(current_menu.menu)) + 1;
            return;
          case 2:
            choice = item_index(current_item(current_menu.menu)) + 8;
            return;
          case 3:
            choice = item_index(current_item(current_menu.menu)) + 12;
            break;
        }
        return;
    }
  }
}

void App::run() {
  MonHoc new_mh("TOAN", "TOAN", 12, 12);
  dsmh.insert(new_mh);
  MonHoc new_mh2("VAN", "VAN", 12, 12);
  dsmh.insert(new_mh2);
  MonHoc new_mh3("ANH", "ANH", 12, 12);
  dsmh.insert(new_mh3);
  
  LopCQ new_lcq("d18cn2");
  dslcq.push_back(new_lcq);

  LopCQ new_lcq2("d19cn2");
  dslcq.push_back(new_lcq2);

  current_menu.display();
  wrefresh(wins[0]);
  wrefresh(wins[1]);
  refresh();
  while (is_running) {
    process_input();
    process_menu();
  }
  exit();
}

void App::exit() {
  wclear(wins[0]);
  wclear(wins[1]);
  clear();
  free_menu(current_menu.menu);
  endwin();
}

int main() {
  App our_app;
  our_app.run(); 
}
