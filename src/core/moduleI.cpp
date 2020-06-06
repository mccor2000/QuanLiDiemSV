#include "library.h"

//tim lop theo nienkhoa, hocki, nhom, monhoc
LopTC* timLop(char* nienkhoa_tmp, short hocki_tmp, short nhom_tmp, char* maMH_tmp) {
    for (int i=0; i<dsltc.getN(); i++) {
        LopTC* tmp = dsltc.node[i];
        if (strcmp(tmp->nienkhoa,nienkhoa_tmp)==0 && tmp->hocki==hocki_tmp && tmp->nhom==nhom_tmp && strcmp(tmp->maMH,maMH_tmp)==0) {
            return tmp;
        }
    }
    return NULL;
}

void find_loptc(char ** data) {
    for (int i = 0; i < dsltc.getN(); i++) {
      current_loptc = dsltc.node[i];
      if (strcmp(current_loptc->nienkhoa, data[0]) == 0,
          current_loptc->hocki == string_to_short(data[1]),
          current_loptc->nhom == string_to_short(data[2]),
          strcmp(current_loptc->maMH, data[3]) == 0
          )
      {
          break;
      }
    }
    current_dsdk = current_loptc->dsdk;
    // current_dsdk = NULL;
}

void set_score(char ** data) {
  // current_svdk.set_DIEM(string_to_float(data[1]));
}

void moduleI_2(char ** data){
    Node<SinhVienDK>* node = current_dsdk->head();
    int counter = 0 ;
    int base = current_dsdk->count();
    while(counter!=base && node!=NULL){
        float score = atof(data[counter++]);
        node->get_data().set_DIEM(score);
        node=node->get_next();
    }
}
