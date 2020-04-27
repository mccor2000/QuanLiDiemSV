#include <iostream>
#include <conio.h>
#include <string.h>
#include "dsltc.h"

using namespace std;

LOPTC::List LOPTC::getList() {
	return list;
}

void LOPTC::setList(List &tmp) {
	list = tmp;
}

void LOPTC::khoiTaoDS() {
	list.n=0;
	list.stt=0;
}

bool LOPTC::isFull() {
	return list.n == LOP_MAX;
}

bool LOPTC::isEmpty() {
	return list.n == 0;
}

void LOPTC::insertOrder(Lop &lop, int pos) {
	list.n++;
	list.node[list.n-1] = new Lop;
	for (int i=list.n-1; i>pos; i--) {
		list.node[i] = list.node[i-1];
	}
	*list.node[pos] = lop;
}

void LOPTC::insertLast(Lop &lop) {
	list.n++;
	list.node[list.n-1] = new Lop;
	*list.node[list.n-1] = lop;
}

int LOPTC::search(int malop_tmp) {
	for (int i=0; i<list.n; i++) {
		if (list.node[i]->malop==malop_tmp) {
			return i;
		}
	}
	return -1;
}

void LOPTC::thongBao(char* s) {
	cout<<s;
}

void LOPTC::nhapLop(Lop &lop) {
	list.stt++;
	lop.malop=list.stt;
	cout<<"Ma lop: "<<lop.malop<<"\n";
	cout<<"Nhap ma mon hoc: "; 
	fflush(stdin);
	do {
		cin.getline(lop.maMH,10);
	} while (strcmp(lop.maMH,"")==0);
	cout<<"Nhap nien khoa: ";
	cin>>lop.nienkhoa;
	cout<<"Nhap hoc ki: ";
	cin>>lop.hocki;
	cout<<"Nhap nhom: ";
	cin>>lop.nhom;
	cout<<"Nhap so luong sv toi da: "; 
	cin>>lop.sv_max;
	cout<<"Nhap so luong sv toi thieu: ";
	cin>>lop.sv_min;
}

void LOPTC::nhapDS() {
	if (!isEmpty()) {
		xoaDS();
	}
	khoiTaoDS();
	char ok='y';
	Lop lop;
	while (ok=='y' || ok=='Y') {
		nhapLop(lop);
		insertLast(lop);
		cout<<"Ban co muon tiep tuc? (Y/N)\n";
		do {
			ok = getch();
		} while (ok!='y' && ok!='Y' && ok!='n' && ok!='N');
	}
}

void LOPTC::xuatDS() {
	system("cls");
	cout<<"MALOP\tMAMH\tNIENKHOA\tHOCKI\tNHOM\n";
	for (int i=0; i<list.n; i++) {
		cout<<list.node[i]->malop<<"\t"<<list.node[i]->maMH<<"\t"<<list.node[i]->nienkhoa<<"\t\t"<<list.node[i]->hocki<<"\t"<<list.node[i]->nhom<<"\n";
	}
	getch();
}

void LOPTC::themLop(Lop &lop, int pos) {
	if (isFull()) {
		thongBao("Danh sach day");
		return;
	}
	if (pos<0) {
		insertOrder(lop,0);
	}
	else if (pos>list.n) {
		insertLast(lop);
	}
	else {
		insertOrder(lop,pos);
	}
}

void LOPTC::xoaLop(int malop_del) {
	if (isEmpty()) {
		thongBao("Danh sach rong");
		return;
	}
	int pos=search(malop_del);
	if (pos==-1) {
		thongBao("Ma lop khong ton tai");
		return;
	}
	delete list.node[pos];
	for (int i=pos; i<list.n-1; i++) {
		list.node[i] = list.node[i+1];
	}
	list.n--;
}

void LOPTC::xoaDS() {
	if (isEmpty()) {
		thongBao("Danh sach rong");
		return;
	}
	while (list.n>0) {
		delete list.node[list.n-1];
		list.n--;
	}
}




