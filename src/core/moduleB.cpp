#include "library.h"

void in_danh_sach_dang_ki(LOPTC dsltc, char* nienkhoa, short hocki, short nhom, char * maMH) {
  
  DanhSachSinhVienDK dsdk; 
  
  for (int i = 0; i < dsltc.getN(); i++) {
    Lop temp = *dsltc.node[i];
    
    if (strcmp(temp.nienkhoa,nienkhoa)==0 && temp.hocki == hocki && temp.nhom == nhom && strcmp(temp.maMH, maMH) == 0) {
      dsdk = *temp.dsdk;   
      break;
    }
  }
  dsdk.print();
}
