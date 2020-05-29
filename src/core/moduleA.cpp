#include "library.h"

using namespace std;

short StringToShort(char* st) {
    short s=0;
    for (int i=0; i<sizeof(st); i++) {
        s=s*10+(int(st[i])-48);
    }
    return s;
}

int StringToInt(char* st) {
    int n=0;
    for (int i=0; i<sizeof(st); i++) {
        n=n*10+(int(st[i])-48);
    }
    return n;
}

void themLop(DanhSachLopTC &dsltc, char** data) {
    //tao lop
    LopTC loptc(data[0],data[1],StringToShort(data[2]),StringToShort(data[3]),StringToInt(data[4]),StringToInt(data[5]));
    dsltc.themLop(loptc,dsltc.getN());
}

void xoaLop(DanhSachLopTC &dsltc,int maloptc) {
    dsltc.xoaLop(maloptc);
}

void hieuChinhLop(DanhSachLopTC &dsltc, int index) {
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
                strcpy(dsltc.node[index]->nienkhoa,tmp);
                break;
            }
            //Sua hocki
            case 2: {
                short tmp;
                cin>>tmp;
                dsltc.node[index]->hocki = tmp;
                break;
            }
            //Sua nhom
            case 3: {
                short tmp;
                cin>>tmp;
                dsltc.node[index]->nhom = tmp;
                break;
            }
            //Sua sv_max
            case 4: {
                int tmp;
                cin>>tmp;
                dsltc.node[index]->sv_max = tmp;
                break;
            }
            //Sua sv_min
            case 5: {
                int tmp;
                cin>>tmp;
                dsltc.node[index]->sv_min = tmp;
                break;
            }
            default: {
                cout<<"Lua chon khong hop le, moi ban nhap lai\n";
            }
        }
    } while (!stop);
} 

