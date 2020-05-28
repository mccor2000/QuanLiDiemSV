#include "library.h"

//tim lop theo nienkhoa, hocki, nhom, monhoc
LopTC* timLop(DanhSachLopTC &dsltc, char* nienkhoa_tmp, short hocki_tmp, short nhom_tmp, char* maMH_tmp) {
    for (int i=0; i<dsltc.getN(); i++) {
        LopTC* tmp = dsltc.node[i];
        if (strcmp(tmp->nienkhoa,nienkhoa_tmp)==0 && tmp->hocki==hocki_tmp && tmp->nhom==nhom_tmp && strcmp(tmp->maMH,maMH_tmp)==0) {
            return tmp;
        }
    }
    return NULL;
}

//xuat dsdk lop vua tim duoc
void xuatDSDK(LopTC* loptc, DanhSachLopCQ &dslcq) {
    if (loptc==NULL) {
        cout<<"Khong co lop thoa yeu cau";
    }
    else {
        for (Node<SinhVienDK>* p = loptc->dsdk->p_head_; p!=NULL; p = p->get_next()) {
            SinhVien * sv = dslcq.search_sv(p->get_data().get_MASV());
            cout<<sv->get_MALOP()<<"\t"<<sv->get_MASV()<<"\t"<<sv->get_HO()<<"\t"<< sv->get_TEN()<<"\t";
            //nhap diem cho SV
            float diem_tmp;
            cin>>diem_tmp;
            SinhVienDK svdk(sv->get_MASV(),diem_tmp);
            p->set_data(svdk);
        }

    }
}

