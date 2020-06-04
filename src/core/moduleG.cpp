#include "library.h"

//loc cac lop theo nien khoa va hoc ki 

LinkedList<LopTC>  locDSLTC(char ** form_dangky ) {
    LinkedList<LopTC> result;
    for (int i=0; i<dsltc.getN(); i++) {
        LopTC loptc = *dsltc.getLop(i);
        if (strcmp(loptc.nienkhoa,form_dangky[0])==0 && loptc.hocki==string_to_short(form_dangky[1])) {
            result.push_back(lopTC);
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
