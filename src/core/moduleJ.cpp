#include "library.h"

void Show_Score(DanhSachMonHoc& dsmh, DanhSachLopCQ &dslcq, DanhSachLopTC& dsltc,char* nienkhoa, short hocki, short nhom, char tenMH[]){
    MonHoc* mh = new MonHoc();
    mh = dsmh.search_name(tenMH);
    LopTC* loptc;
    bool flag=0;
    for(int i=0;i<dsltc.getN();i++){
        if(strcmp(dsltc.node[i]->maMH,mh->MAMH)==0){
            loptc = dsltc.node[i];
            flag=1;
            break;
        }
    }
    if(flag){
        DanhSachSinhVienDK * DSDK = loptc->dsdk;
        Node<SinhVienDK>* node_DK = DSDK->head();
        while (node_DK!=NULL) {
            SinhVien sv = *dslcq.search_sv(node_DK->get_data().get_MASV());
            cout<<sv.get_MALOP()<<"\t"<<sv.get_MASV()<<"\t"<<sv.get_HO()<<"\t"<<sv.get_TEN()<<"\t"<<
                node_DK->get_data().get_DIEM()<<"\n";
            node_DK = node_DK->get_next();
        }
    }
    else{
        std::cout << "Mon hoc khong ton tai\n";
    }
}
