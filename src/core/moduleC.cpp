#include "library.h"
using namespace std;

#define MAX 50

lopCQ DSLopCQ[MAX];
short counter=0;
void POST(char* tenLop, DanhSachSinhVien dssv){
    lopCQ(tenLop, dssv);
    counter++;
}
void GET_ALL(){
    for(int i=0;i<counter;i++){
        cout << DSLopCQ[i].get_TenLop() << '\n';
    }
}
void GET_NAME(char* name){
    bool find=false;
    for(int i=0;i<counter && !find ;i++){
        if(name == DSLopCQ[i].get_TenLop()){
            cout << DSLopCQ[i].get_TenLop() << "\n";
            find=true;
        }
    }
    cout << (find==false)?"Khong tim thay lop\n" : "\n";
}
void PUT(char* name, lopCQ tmp){
    bool find=false;
    for(int i=0;i<counter && !find ;i++){
        if(name == DSLopCQ[i].get_TenLop()){
            DSLopCQ[i]= tmp;
            find=true;
        }
    }
    cout << (find==false)?"Khong tim thay lop\n" : "\n";
}

DanhSachSinhVien SelectClass(){
    char* name;
    cout << "Nhap vao Lop ban muon them sinh vien : \n";
    cin >> name;
    bool find=false;
    for(int i=0;i<counter && !find ;i++){
        if(name == DSLopCQ[i].get_TenLop()){
            return DSLopCQ[i].get_DSSV();
        }
    }
    cout << "Khong tim thay lop nay\n";
}


void Add(){
    DanhSachSinhVien SelectedClass = SelectClass(); 
    cout << "Nhap thong tin sinh vien\n";
    char* MASV="TEST"; 
    char* HO="TEST";
    char* TEN="TEST";
    char* SDT="TEST";
    char* MALOP="TEST";
    bool PHAI=1;
    
    SinhVien sv(MASV, HO, TEN, PHAI, SDT, MALOP);
    SelectedClass.push_back(sv);
}
