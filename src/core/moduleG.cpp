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
    current_dsdk->push_back(SinhVienDK(data));
    return;
}
