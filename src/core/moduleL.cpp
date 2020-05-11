#include "library.h"



void core(DanhSachLopCQ& dslcq, DanhSachMonHoc& dsmh, LOPTC& dsltc, char* MALOP){
    DanhSachSinhVien * dssv = dslcq.get_dssv(MALOP);
  
    if (dssv == NULL) {
        std::cout << "Lop khong ton tai\n";
        return;
    }
    Node<SinhVien>* sv = dssv->head();
    LinkedList<char*> list_mh = dsmh.list_mh(dsmh.root);
    Node<char*>* mh = list_mh.head();
    while(sv->get_next()!=NULL){
        SinhVien tmp = sv->get_data();
        sv=sv->get_next();
        std::cout << tmp.get_MASV() << " " << tmp.get_HO() << " "<<tmp.get_TEN() << " ";
        while(mh->get_next()!=NULL){
            std::cout << mh << " ";
            for(int i=0;i<dsltc.getN();i++){
                Lop* loptc = dsltc.node[i];
                DanhSachSinhVienDK* dsdk = loptc->dsdk;
                Node<SinhVienDK>* svdk = dsdk->head();
                while(svdk->get_next()!=NULL){
                    if(mh->get_data()==loptc->maMH && svdk->get_data().get_MASV()== tmp.get_MASV())
                        std::cout<<svdk->get_data().get_DIEM() << " ";
                }

            }
            mh=mh->get_next();
        }
        std::cout << '\n';
    }
}

int main(){
    std::cout << "hello world\n";
}