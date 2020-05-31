#include "library.h"

LinkedList<char*> in_danh_sach_sv(char * ma_lop) {
  DanhSachSinhVien * dssv = dslcq.get_dssv(ma_lop);
  LinkedList<char*> result;
  if (dssv == NULL) {
    char* res;
    strcpy(res,"NULL");
    result.push_back(res);
    return result;
  }
  dssv->sort();
  Node<SinhVien>* sv = dssv->head();
  while(sv!=NULL){
    char* res[6];
    strcpy(res[0],sv->get_data().get_MASV());
    strcpy(res[1],sv->get_data().get_HO());
    strcpy( res[2],sv->get_data().get_TEN());
    if(sv->get_data().get_PHAI()){
      strcpy(res[3],"Nu");
    }    
    else{
      strcpy(res[3],"NAM");
    }
    strcpy(res[4],sv->get_data().get_SDT());
    char* ans = "";
    strcat(ans,res[0]);
    for(int i=1;i<5;i++){
      strcat(ans,"   ");
      strcat(ans,res[i]);
    }
    result.push_back(ans);
    sv=sv->get_next();
  }
  return result;
}
