#include "library.h"

LinkedList<char* > in_bang_diem_trung_binh(DanhSachLopCQ& dslcq, DanhSachMonHoc& dsmh, DanhSachLopTC& dsltc, char* MALOP){
  // Get dssv   
  LinkedList<char* > result;
  DanhSachSinhVien * dssv = dslcq.get_dssv(MALOP);
  if(dssv == NULL){
    return result;
  }
  
  // Get list MonHoc
  LinkedList<MonHoc> list_mh;
  dsmh.enumerate([list_mh](MonHoc x) mutable { 
      list_mh.push_back(x); 
  });
  
  Node<SinhVien>* sv = dssv->head();
  Node<MonHoc> * mh= list_mh.head();
  
  while (sv->get_next() != NULL) {
    float total = 0;
    short cnt = 0;

    SinhVien tmp = sv->get_data();
    sv=sv->get_next();
    char* res[5];
    strcpy(res[0],tmp.get_MASV());
    strcpy(res[1],tmp.get_HO());
    strcpy(res[2],tmp.get_TEN());

    
    while(mh != NULL) {
      for(int i=0; i < dsltc.getN(); i++) {
        LopTC* loptc = dsltc.node[i];
        if (mh->get_data().MAMH != loptc->maMH) continue;
        
        DanhSachSinhVienDK* dsdk = loptc->dsdk;
        Node<SinhVienDK>* svdk = dsdk->head();
        while(svdk != NULL) {
          if(svdk->get_data().get_MASV() == tmp.get_MASV()) {
            total+= svdk->get_data().get_DIEM();
            cnt++;
          }
        }
      }
        
      mh = mh->get_next();
    }
    char buffer[5];
    float score = total/cnt;
    strcpy(res[4],gcvt(score,3,buffer));
    char* ans = "";
    strcat(ans,res[0]);
    for(int i=1;i<5;i++){
      strcat(ans,"   ");
      strcat(ans,res[i]);
    }
    result.push_back(ans);
  }
  return result;
}
