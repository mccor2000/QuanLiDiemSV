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

void  moduleI_1(char** data){
    LopTC* curr_class = timLop(data[0],string_to_short(data[1]),string_to_short(data[2]),data[3]);
    current_dsdk = *curr_class->dsdk;
}

void moduleI_2(char ** data){
    Node<SinhVienDK>* node = current_dsdk.head();
    int counter = 0 ;
    int base = current_dsdk.count();
    while(counter!=base && node!=NULL){
        float score = atof(data[counter]);
        node->get_data().set_DIEM(score);
        counter++;
        node=node->get_next();
    }
}