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
                char tmp[10];
                cin.ignore();
                cin.getline(tmp,10);
                strcpy(loptc.node[index]->nienkhoa,tmp);
                break;
            }
            //Sua hocki
            case 2: {
                short tmp;
                cin>>tmp;
                loptc.node[index]->hocki = tmp;
                break;
            }
            //Sua nhom
            case 3: {
                short tmp;
                cin>>tmp;
                loptc.node[index]->nhom = tmp;
                break;
            }
            //Sua sv_max
            case 4: {
                int tmp;
                cin>>tmp;
                loptc.node[index]->sv_max = tmp;
                break;
            }
            //Sua sv_min
            case 5: {
                int tmp;
                cin>>tmp;
                loptc.node[index]->sv_min = tmp;
                break;
            }
            default: {
                cout<<"Lua chon khong hop le, moi ban nhap lai\n";
            }
        }
    } while (!stop);
} 

