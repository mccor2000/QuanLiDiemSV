#include "library.h"

void in_bang_diem_trung_binh(DanhSachLopCQ& dslcq, DanhSachMonHoc& dsmh, LOPTC& dsltc, char* MALOP){
  // Get dssv   
  DanhSachSinhVien * dssv = dslcq.get_dssv(MALOP);
  if(dssv == NULL){
    std::cout << "Lop khong ton tai\n";
    return;
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

    std::cout << tmp.get_MASV() << " " << tmp.get_HO() << " "<<tmp.get_TEN() << " ";
    
    while(mh != NULL) {
      for(int i=0; i < dsltc.getN(); i++) {
        Lop* loptc = dsltc.node[i];
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
        
    float score = total/cnt;
    std::cout<< score << "\n";
  }
}
