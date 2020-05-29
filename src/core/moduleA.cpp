#include "library.h"

using namespace std;

short StringToShort(char* st) {
    short s=0;
    for (int i=0; i<sizeof(st); i++) {
        s=s*10+(int(st[i])-48);
    }
    return s;
}


//code Bao
char* converting(int x){
    char* result = "";
    while(x){
        char res=char(x%10)+48;
        char* ans = &res;
        strcat(result,ans);
        x/=10;
    }
    return result;
}
//


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

void xoaLop(DanhSachLopTC &dsltc,char* maloptc) {
    dsltc.xoaLop(StringToInt(maloptc));  
}

void hieuChinhLop(DanhSachLopTC &dsltc, char** data, char* malop) {
    LopTC loptc(data[0],data[1],StringToShort(data[2]),StringToShort(data[3]),StringToInt(data[4]),StringToInt(data[5]));
    dsltc.setLop(loptc,dsltc.search(StringToInt(malop)));
} 

