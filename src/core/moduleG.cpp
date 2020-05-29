#include "library.h"

//loc cac lop theo nien khoa va hoc ki 

LinkedList<char*> locDSLTC(DanhSachLopTC &dsltc, DanhSachMonHoc &dsmh , char* nienkhoa_tmp, short hocki_tmp) {
    LinkedList<char* > result;
    for (int i=0; i<dsltc.getN(); i++) {
        char* res[6];
        LopTC tmp = *dsltc.node[i];
        MonHoc * mh = dsmh.search_code(tmp.maMH);
        if (strcmp(tmp.nienkhoa,nienkhoa_tmp)==0 && tmp.hocki==hocki_tmp) {
            strcpy(tmp.maMH,res[0]);
            strcpy(mh->TENMH,res[1]);
            strcpy(converting(tmp.nhom),res[2]);
            strcpy(converting(tmp.dsdk->count()),res[3]);
            strcpy(converting(tmp.sv_max-tmp.dsdk->count()),res[4]);
            char* ans="";
            strcat(ans,res[0]);
            for(int i=1;i<5;i++){
                strcat(ans,"   ");
                strcat(ans,res[i]);
            }
            result.push_back(ans);
        }
    }
    return result;
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
