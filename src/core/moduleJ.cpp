#include "library.h"

void Show_Score(DanhSachMonHoc& ds, LinkedList<Student>& dssv, LOPTC& dsltc,short nienkhoa, short hocki, short nhom, char tenMH[]){
    MonHoc* mh = new MonHoc();
    mh = ds.search_name(tenMH);
    Lop* LTC;
    bool flag=0;
    for(int i=0;i<dsltc.getN();i++){
        if(dsltc.node[i]->maMH == mh->MAMH){
            LTC = dsltc.node[i];
            flag=1;
            break;
        }
    }
    if(flag){
    LinkedList<Register> DSDK = LTC->dsdk;
    Node<Register>* node_DK = DSDK.head();
    Node<Student>* node_SV = dssv.head();
    while(node_SV->get_next()!= NULL ){
        while(node_DK->get_next() != NULL){
            if(node_DK->get_data().get_MASV() == node_SV->get_data().get_MASV()){
                std::cout << node_SV->get_data().get_MASV() << " " << node_SV->get_data().get_MALOP() << " "<<node_SV->get_data().get_HO() << " " << node_SV->get_data().get_TEN() << " " << node_DK->get_data().get_DIEM() << "\n";
            }
            node_DK = node_DK->get_next();
        }
        node_SV = node_SV->get_next();
    }
    }
    else{
        std::cout << "Mon hoc khong ton tai\n";
    }
}
