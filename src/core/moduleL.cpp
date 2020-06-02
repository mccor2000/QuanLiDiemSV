#include "library.h"

LinkedList<char*> in_bang_diem_tong_ket(char* MALOP) {
  // Get dssv
  LinkedList<char* > result;
  DanhSachSinhVien * dssv = dslcq.get_dssv(MALOP);
  if (dssv == NULL) {
    return result;
  }
  
  // Get list MonHoc
  LinkedList<MonHoc> list_mh;
  dsmh.enumerate([&list_mh](MonHoc x) mutable { 
      list_mh.push_back(x); 
  });
  
  Node<SinhVien>* sv = dssv->head();
  Node<MonHoc> * mh = list_mh.head();
  while(sv != NULL) {
    // Get sv info
    char* res[5];
    SinhVien tmp = sv->get_data();
    strcpy(res[0],tmp.get_MASV());
    strcpy(res[1],tmp.get_HO());
    strcpy(res[2],tmp.get_TEN());
        
    // Loop through list mh to get diem 
    while(mh != NULL) {
      for(int i = 0; i < dsltc.getN(); i++) {
        if (dsltc.node[i]->maMH != mh->get_data().MAMH) continue;
          // Loop through DanhSachSinhVienDK
          Node<SinhVienDK> * temp_sv = dsltc.node[i]->dsdk->head();
          while(temp_sv != NULL) {
            if (temp_sv->get_data().get_MASV() == sv->get_data().get_MASV()) {
              char buffer[5];
              strcpy(res[3],gcvt(temp_sv->get_data().get_DIEM(),3,buffer));
            }
          }
      }
      mh=mh->get_next();
    }
    char* ans = "";
    strcat(ans,res[0]);
    for(int i=1;i<4;i++){
      strcat(ans, "  ");
      strcat(ans,res[i]);
    }
    result.push_back(ans);
    sv = sv->get_next();
  }
  return result;
}
