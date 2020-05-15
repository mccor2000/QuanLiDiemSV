#include "library.h"

void in_diem_trung_binh(DanhSachLopCQ& dslcq, DanhSachMonHoc& dsmh, LOPTC& dsltc, char* MALOP){
    
  DanhSachSinhVien * dssv = dslcq.get_dssv(MALOP);
  if(dssv == NULL){
    std::cout << "Lop khong ton tai\n";
    return;
  }
    
  Node<SinhVien>* sv = dssv->head();
  dsmh.enumerate(get_mh);

  Node<MonHoc> * mh= list_mh.head();
  while (sv->get_next() != NULL) {
    float total = 0;
    short cnt = 0;

    SinhVien tmp = sv->get_data();
    sv=sv->get_next();

    std::cout << tmp.get_MASV() << " " << tmp.get_HO() << " "<<tmp.get_TEN() << " ";
    
    while(mh->get_next() != NULL) {
      for(int i=0; i < dsltc.getN(); i++) {
        Lop* loptc = dsltc.node[i];
        if (mh->get_data().MAMH != loptc->maMH) continue;
        
        DanhSachSinhVienDK* dsdk = loptc->dsdk;
        Node<SinhVienDK>* svdk = dsdk->head();
        while(svdk->get_next()!=NULL){
          if(svdk->get_data().get_MASV() == tmp.get_MASV()) {
            total+= svdk->get_data().get_DIEM();
            cnt++;
          }
        }
      }
        
      mh = mh->get_next();
    }
        
    float score = total/cnt;
    std::cout<< score <<'\n';
  }
}
