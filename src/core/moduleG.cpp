#include "library.h"

//loc cac lop theo nien khoa va hoc ki 
LinkedList<LopTC>  locDSLTC(char ** form_dangky ) {
    LinkedList<LopTC> result;
    for (int i=0; i<dsltc.getN(); i++) {
        LopTC loptc = *dsltc.getLop(i);
        if (strcmp(loptc.nienkhoa,form_dangky[0])==0 && loptc.hocki==string_to_short(form_dangky[1])) {
            result.push_back(loptc);
        }
    }
    return result;
}

//dang ky lop cho SV
int dangKyLop(char* data) {
    int malop = string_to_int(data);
    LopTC loptc = *dsltc.node[dsltc.search(malop)];
    for (Node<SinhVienDK>* p = loptc.dsdk->p_head_; p!=NULL; p = p->get_next()) {
        if (strcmp(p->get_data().get_MASV(),current_sv.get_MASV())==0) {
            return 0;
        }
    }
    SinhVienDK svdk(current_sv.get_MASV(),0);
    loptc.dsdk->push_back(svdk);
    if (loptc.dsdk->count()>=loptc.sv_min) {
        loptc.huylop = false;
    }
    return 1;
}
