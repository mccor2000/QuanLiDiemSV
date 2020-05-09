#include "library.h"

//tim SV trong DSSV
Node<Student>* timSV(char* maSV_tmp, LinkedList<Student> &dssv) {
    for (Node<Student> *p = dssv.p_head_; p!=NULL; p=p->get_next() ) {
        Student tmp = p->get_data();
        if (strcmp(tmp.get_MASV(),maSV_tmp)==0) {
            return p;
        }
    }
    return NULL;
}
//xuat thong tin SV
void xuatSV(Node<Student>* SV) {
    if (SV==NULL) {
        cout<<"Ma SV khong ton tai\n";
    }
    else {
        SV->get_data().info();
        cout<<"\n";
    }
}
//loc cac lop theo nien khoa va hoc ki 
void locDSLTC(LOPTC &loptc, DanhSachMonHoc &dsmh , short nienkhoa_tmp, short hocki_tmp) {
	cout<<"MAMH\tTENMH\tNHOM\tSV_DA_DK\tVI_TRI_TRONG\n";
    for (int i=0; i<loptc.getN(); i++) {
        Lop tmp = *loptc.node[i];
        MonHoc * mh = dsmh.search_code(tmp.maMH);
        if (tmp.nienkhoa==nienkhoa_tmp && tmp.hocki==hocki_tmp) {
		    cout<<tmp.maMH<<"\t"<<mh->TENMH<<"\t"<<tmp.nhom<<"\t"<<tmp.dsdk.count()<<"\t"<<tmp.sv_max-tmp.dsdk.count()<<"\n";
        }
    }
}
//dang ky lop cho SV
int dangKyLop(LinkedList<Register> &dsdk, Register SV) {
    for (Node<Register>* p = dsdk.p_head_; p!=NULL; p = p->get_next()) {
        if (strcmp(p->get_data().get_MASV(),SV.get_MASV())==0) {
            return 0;
        }
    }
    dsdk.push_back(SV);
    return 1;
}