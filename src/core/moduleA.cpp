#include "library.h"

using namespace std;

void themLop(LOPTC &loptc, Lop &lop) { 
    loptc.themLop(lop,loptc.getN());
}

void xoaLop(LOPTC &loptc,int maloptc) {
    loptc.xoaLop(maloptc);
}

void hieuChinhLop(LOPTC &loptc, int index) {
    int choice;
    bool stop = false;
    do {
        std::cout<<"Chon thuoc tinh ban muon chinh sua (nhap 0 de dung):";
        std::cin>>choice;
        switch (choice) {
            //dung chinh sua
            case 0: {
                stop = true;
                break;
            }
            //Sua nienkhoa
            case 1: {
                int tmp;
                cin>>tmp;
                loptc.node[index]->nienkhoa = tmp;
                break;
            }
            //Sua nhom
            case 2: {
                int tmp;
                cin>>tmp;
                loptc.node[index]->nhom = tmp;
            }
            //Sua sv_max
            case 3: {
                int tmp;
                cin>>tmp;
                loptc.node[index]->sv_max = tmp;
                break;
            }
            //Sua sv_min
            case 4: {
                int tmp;
                cin>>tmp;
                loptc.node[index]->sv_min = tmp;
                break;
            }
            default: {
                cout<<"Lua chon khong hop le, moi ban nhap lai";
            }
        }
    } while (!stop);
} 
