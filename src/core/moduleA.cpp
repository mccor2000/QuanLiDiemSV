#include "library.h"

using namespace std;

void themLop(LOPTC &loptc) {
    Lop lop;
    loptc.nhapLop(lop);
    loptc.themLop(lop,loptc.getN());
}

void xoaLop(LOPTC &loptc,int maloptc) {
    loptc.xoaLop(maloptc);
}

void hieuChinhLop(LOPTC &loptc, int index) {
    Lop loptmp;
    loptmp.malop = loptc.node[index]->malop;
    strcpy(loptmp.maMH,loptc.node[index]->maMH);
    loptmp.huylop = loptc.node[index]->huylop;
    loptmp.dsdk = loptc.node[index]->dsdk;
    cin>>loptmp.nienkhoa;
    cin>>loptmp.hocki;
    cin>>loptmp.nhom;
    cin>>loptmp.sv_max;
    cin>>loptmp.sv_min;
    //--
    *loptc.node[index] = loptmp;
} 
