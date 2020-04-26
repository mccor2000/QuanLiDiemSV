#include<iostream>
#include "../../include/templates/LinkedList.h"
#include "../../include/SinhVien/SinhVien.h"
using namespace std;
int main(){
    cout << "Programing.....\n";
    char ma1[]="N18DCCN011";
    char ma2[]="DUONG";
    char ma3[]="Bao";
    char ma4[]="0973286174";
    char ma5[]="D18DCCN02-N";


    Student sv(ma1, ma2, ma3,0,ma4,ma5);

    LinkedList<Student> list;
    list.push_back(sv);

}