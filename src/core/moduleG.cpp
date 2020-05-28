#include "library.h"

//loc cac lop theo nien khoa va hoc ki 
void locDSLTC(DanhSachLopTC &dsltc, DanhSachMonHoc &dsmh , char* nienkhoa_tmp, short hocki_tmp) {
	cout<<"MAMH\tTENMH\tNHOM\tSV_DA_DK\tVI_TRI_TRONG\n";
    for (int i=0; i<dsltc.getN(); i++) {
        LopTC tmp = *dsltc.node[i];
        MonHoc * mh = dsmh.search_code(tmp.maMH);
        if (strcmp(tmp.nienkhoa,nienkhoa_tmp)==0 && tmp.hocki==hocki_tmp) {
		    cout<<tmp.maMH<<"\t"<<mh->TENMH<<"\t"<<tmp.nhom<<"\t"<<tmp.dsdk->count()<<"\t"<<tmp.sv_max-tmp.dsdk->count()<<"\n";
        }
    }
}
//dang ky lop cho SV
int dangKyLop(LopTC &loptc, SinhVienDK SV) {
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
