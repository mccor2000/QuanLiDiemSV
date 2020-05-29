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
LinkedList<char* []> xuatDSDK(LopTC* loptc, DanhSachLopCQ &dslcq) {
        LinkedList<char* []> result;
    if (loptc==NULL) {
        return result;
    }
    else {
        for (Node<SinhVienDK>* p = loptc->dsdk->p_head_; p!=NULL; p = p->get_next()) {
            SinhVien * sv = dslcq.search_sv(p->get_data().get_MASV());
            char* res[5];
            strcpy(res[0],sv->get_MALOP());
            strcpy(res[1],sv->get_MASV());
            strcpy(res[2],sv->get_HO());
            strcpy(res[3],sv->get_TEN());
            result.push_back(res);
            }
    return result;
    }
}

void NhapDiemSV(SinhVienDK& sv, float DIEM){
    sv.set_DIEM(DIEM);
}
