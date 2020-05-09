#include "library.h"

//tim lop theo nienkhoa, hocki, nhom, monhoc
Lop* timLop(LOPTC &dsltc, short nienkhoa_tmp, short hocki_tmp, short nhom_tmp, char* maMH_tmp) {
    for (int i=0; i<dsltc.getN(); i++) {
        Lop* tmp = dsltc.node[i];
        if (tmp->nienkhoa==nienkhoa_tmp && tmp->hocki==hocki_tmp && tmp->nhom==nhom_tmp && strcmp(tmp->maMH,maMH_tmp)==0) {
            return tmp;
        }
    }
    return NULL;
}

//tim SV theo maSV
Node<Student>* timSV(LinkedList<Student> &dssv, char* maSV_tmp) {
    for (Node<Student>* p = dssv.p_head_; p!=NULL; p=p->get_next()) {
        if (p->get_data().get_MASV()==maSV_tmp) {
            return p;
        }
    }
    return NULL;
}

//xuat dsdk lop vua tim duoc
void xuatDSDK(Lop* lop, LinkedList<Student> &dssv) {
    if (lop==NULL) {
        cout<<"Khong co lop thoa yeu cau";
    }
    else {
        for (Node<Register>* p = lop->dsdk.p_head_; p!=NULL; p = p->get_next()) {
            Node<Student>* sv = timSV(dssv,p->get_data().get_MASV());
            cout<<sv->get_data().get_MALOP()<<"\t"<<sv->get_data().get_MASV()<<"\t"<<sv->get_data().get_HO()<<"\t"<<
                sv->get_data().get_TEN()<<"\t";
            //nhap diem cho SV
            float diem_tmp;
            cin>>diem_tmp;
            Register svdk(sv->get_data().get_MASV(),diem_tmp);
            p->set_data(svdk);
        }

    }
}