#include "library.h"

LinkedList<char*> in_danh_sach_dang_ki(DanhSachLopTC &dsltc, char* nienkhoa, short hocki, short nhom, char * maMH) {
  LinkedList<char*> result;
  DanhSachSinhVienDK dsdk; 
  
  for (int i = 0; i < dsltc.getN(); i++) {
    LopTC temp = *dsltc.node[i];
    
    if (strcmp(temp.nienkhoa,nienkhoa)==0 && temp.hocki == hocki && temp.nhom == nhom && strcmp(temp.maMH, maMH) == 0) {
      dsdk = *temp.dsdk;   
      break;
    }
  }
  Node<SinhVienDK> * temp = dsdk.head();
  while(temp != NULL ){
    char* res[2];
    char buffer[5];
    strcpy(res[0],temp->get_data().get_MASV());
    strcpy(res[1],gcvt(temp->get_data().get_DIEM(),3,buffer));
    char* ans="";
    strcat(ans,res[0]);
    for(int i=1;i<2;i++){
      strcat(ans,"   ");
      strcat(ans,res[i]);
    }
    result.push_back(ans);
    temp=temp->get_next();
  }
  return result; 
}
