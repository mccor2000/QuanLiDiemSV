#include "library.h"



void DiemMH(DanhSachLopCQ& dslcq, DanhSachMonHoc& dsmh, LOPTC& dsltc, char* MALOP){
    DanhSachSinhVien * dssv = dslcq.get_dssv(MALOP);
  
    if (dssv == NULL) {
        std::cout << "Lop khong ton tai\n";
        return;
    }

    Node<SinhVien>* sv = dssv->head();
    LinkedList<MonHoc> list_mh = dsmh.enumerate();

    Node<MonHoc> * mh = list_mh.head();
    while(sv->get_next()!=NULL) {
        
        // Get sv info
        SinhVien tmp = sv->get_data();
        sv=sv->get_next();
        std::cout << tmp.get_MASV() << " " << tmp.get_HO() << " "<<tmp.get_TEN() << " ";
        
        // Loop through list mh to get diem 
        while(mh != NULL){
            for(int i = 0; i < dsltc.getN(); i++) {
                if (dsltc.node[i]->maMH != mh->get_data().MAMH) continue;
                // Loop through DanhSachSinhVienDK
                Node<SinhVienDK> * temp_sv = dsltc.node[i]->dsdk->head();
                while(temp_sv != NULL) {
                    if (temp_sv->get_data().get_MASV() == sv->get_data().get_MASV()) {
                        std::cout << temp_sv->get_data().get_DIEM() << " ";
                    }
                }
            }
            mh=mh->get_next();
        }
        std::cout << '\n';
    }
}
