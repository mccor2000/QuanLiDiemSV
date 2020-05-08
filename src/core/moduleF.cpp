#include "library.h"

void print_dsmh() {
  DanhSachMonHoc dsmh;
  dsmh.get_from_file(DSMH_PATH__);

  dsmh.enumerate();
}

int main() {
  print_dsmh();
}
