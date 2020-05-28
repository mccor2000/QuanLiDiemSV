#include "./gui/table.h"
#include "./gui/menu.h"
#include "./gui/form.h"

#include "./core/library.h"

// Chooses's code
const short CHOOSE_QLLTC = 1;
const short CHOOSE_QLLCQ = 2;
const short CHOOSE_QLMH = 3;
const short CHOOSE_NHAP_DIEM = 4;
const short CHOOSE_DANG_KY = 5;
const short CHOOSE_THOAT = 6;

const short CHOOSE_THEM = 7;
const short CHOOSE_CHINH_SUA = 8;
const short CHOOSE_XOA = 9;
const short CHOOSE_QUAY_LAI = 10;

// App's state
const short DSLTC = 1;
const short DSLCQ = 2;
const short DSMH = 3;
const short DSSV = 4;
const short DSDK = 5;

class App {
private:
  bool is_running;
  short state;

  // UI
  WINDOW * wins[2];
  Menu current_menu;
  Table current_table;

  // Data
  DanhSachLopTC dsltc;
  DanhSachLopCQ dslcq;
  DanhSachMonHoc dsmh;
  // DanhSachSinhVien curr_dssv;
  // DanhSachSinhVienDK curr_dsdk;
 
  short process_menu();
  void process_table(short);
  void process_form(FORM *);
  void render_dsltc();
  void render_dslcq();
  void render_dsmh();

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
  // noecho();
  keypad(stdscr, TRUE);
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  int row, column;
  getmaxyx(stdscr, row, column);
  //-- Menu window
  wins[0] = newwin(row, (int)column/4, 0, 0);
  keypad(wins[0], TRUE);
  box(wins[0], 0, 0);
  //-- Display window
  wins[1] = newwin(row, (int)(3*column)/4, 0, (int)column/4 + 1);
  keypad(wins[1], TRUE);
  box(wins[1], 0, 0);

  wrefresh(wins[0]);
  wrefresh(wins[1]);
  refresh();

  current_menu = Menu(wins[0], 1);
}

short App::process_menu() {
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
        if (current_menu.type == 1) 
          return item_index(current_item(current_menu.menu)) + 1;
        else
          return item_index(current_item(current_menu.menu)) + 7;
    }
  }
}

void App::process_table(short choice) {
  switch (choice) {
    case CHOOSE_QLLTC:
      unpost_menu(current_menu.menu);
      wclear(wins[1]);
      state = DSLTC;

      current_table = Table(wins[1], 1);
      current_table.display();
      current_menu = Menu(wins[0], 2);
      current_menu.display();
      break;

    case CHOOSE_QLLCQ:
      unpost_menu(current_menu.menu);
      wclear(wins[1]);
      state = DSLCQ;

      current_table = Table(wins[1], 2);
      current_table.display();
      current_menu = Menu(wins[0], 2);
      current_menu.display();
      break;

    case CHOOSE_QLMH:
      unpost_menu(current_menu.menu);
      wclear(wins[1]);
      state = DSMH;

      current_table = Table(wins[1], 3);
      current_table.display();
      current_menu = Menu(wins[0], 2);
      current_menu.display();
      break;
    
    case CHOOSE_NHAP_DIEM: {
      Form nhap_diem_form(wins[1]);
      nhap_diem_form.set_type(4);
      nhap_diem_form.set_len(4);
      nhap_diem_form.set_submit(NULL);

      nhap_diem_form.display();
      nhap_diem_form.process_input();
      break;
    }

    case CHOOSE_DANG_KY: {
      char ma_sv[15];
      SinhVien * sv = NULL;
     
      do {
        mvwprintw(wins[1], 1, 1, "Nhap ma SV: ");
        mvwscanw(wins[1], 1, 12, "%s", ma_sv);
        sv = dslcq.search_sv(ma_sv);
        if (!sv) mvwprintw(wins[1], 2, 1, "Sinh vien khong ton tai!");
        else sv->print_info(wins[1]);
      } while (!sv);

      Form dang_ky_form(wins[1]);
      dang_ky_form.set_type(5);
      dang_ky_form.set_len(2);
      dang_ky_form.set_submit(NULL);

      dang_ky_form.display();
      dang_ky_form.process_input();
      break;
    }

    case CHOOSE_THOAT:
      is_running = false;
      break;

    case CHOOSE_THEM: {
      Form add_form(wins[1]);
      switch (state) {
        case DSLTC: 
          add_form.set_type(1);
          add_form.set_len(7);
          add_form.set_submit(NULL);
          break;
        case DSLCQ:
          add_form.set_type(2);
          add_form.set_len(1);
          add_form.set_submit(NULL);
          break;
        case DSMH: 
          add_form.set_type(3);
          add_form.set_len(4);
          add_form.set_submit(NULL);
          break;
      }

      add_form.display();
      add_form.process_input();
      break;
    }

    case CHOOSE_CHINH_SUA:
      break;
    
    case CHOOSE_XOA:
      break;

    case CHOOSE_QUAY_LAI:
      unpost_menu(current_menu.menu);
      current_menu = Menu(wins[0], 1);
      current_menu.display();
      break;
  }  
}
                        
void App::run() {
  current_menu.display();
  wrefresh(wins[0]);
  wrefresh(wins[1]);
  refresh();
  
  while (is_running) {
    short choice = process_menu();
    process_table(choice);
  }
  exit();
}

void App::exit() {
  dsltc.save();
  dslcq.save();
  dsmh.save();

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
