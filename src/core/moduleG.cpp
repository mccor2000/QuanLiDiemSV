#include "library.h"

//loc cac lop theo nien khoa va hoc ki
void filter_dsltc(char ** data) {
    for (int i = 0; i < dsltc.getN(); i++) {
        LopTC curr_loptc = *dsltc.get_by_id(i);
        if (strcmp(curr_loptc.nienkhoa, data[0]) == 0 && curr_loptc.hocki == string_to_short(data[1])) {
          filtered_dsltc.themLop(curr_loptc, filtered_dsltc.getN());
        }
    }
}

//dang ky lop cho SV
void dang_ky(char * data) {
    // int malop = string_to_int(data);
    // LopTC loptc = *dsltc.node[dsltc.search(malop)];
    // for (Node<SinhVienDK>* p = loptc.dsdk->p_head_; p!=NULL; p = p->get_next()) {
        // if (strcmp(p->get_data().get_MASV(),current_sv.get_MASV())==0) {
            // return 0;
        // }
    // }
    // SinhVienDK svdk(current_sv.get_MASV(),0);
    // loptc.dsdk->push_back(svdk);
    // if (loptc.dsdk->count()>=loptc.sv_min) {
        // loptc.huylop = false;
    // }
    // return 1;
    return;
}
