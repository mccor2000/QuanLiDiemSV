#include "library.h"

//tim SV trong DSSV
Node<SinhVien>* timSV(char* maSV_tmp, DanhSachLopCQ &dslcq) {
    for (Node<LopCQ>* lopcq = dslcq.p_head_; lopcq!=NULL; lopcq = lopcq->get_next())
        for (Node<SinhVien>* sv = lopcq->get_data().DSSV->p_head_; sv!=NULL; sv = sv->get_next()) {
            if (strcmp(sv->get_data().get_MASV(),maSV_tmp)==0) {
                return sv;
            }
        }
    return NULL;
}

//xuat thong tin SV
void xuatSV(Node<SinhVien>* SV) {
    if (SV==NULL) {
        cout<<"Ma SV khong ton tai\n";
    }
    else {
        SV->get_data().info();
        cout<<"\n";
    }
}
//loc cac lop theo nien khoa va hoc ki 
void locDSLTC(LOPTC &loptc, DanhSachMonHoc &dsmh , char* nienkhoa_tmp, short hocki_tmp) {
	cout<<"MAMH\tTENMH\tNHOM\tSV_DA_DK\tVI_TRI_TRONG\n";
    for (int i=0; i<loptc.getN(); i++) {
        Lop tmp = *loptc.node[i];
        MonHoc * mh = dsmh.search_code(tmp.maMH);
        if (strcmp(tmp.nienkhoa,nienkhoa_tmp)==0 && tmp.hocki==hocki_tmp) {
		    cout<<tmp.maMH<<"\t"<<mh->TENMH<<"\t"<<tmp.nhom<<"\t"<<tmp.dsdk->count()<<"\t"<<tmp.sv_max-tmp.dsdk->count()<<"\n";
        }
    }
}
//dang ky lop cho SV
int dangKyLop(Lop &loptc, SinhVienDK SV) {
    for (Node<SinhVienDK>* p = loptc.dsdk->p_head_; p!=NULL; p = p->get_next()) {
        if (strcmp(p->get_data().get_MASV(),SV.get_MASV())==0) {
            return 0;
        }
    }
    loptc.dsdk->push_back(SV);
    if (loptc.dsdk->count()>=loptc.sv_min) {
        loptc.huylop = false;
    }
    return 1;
}
