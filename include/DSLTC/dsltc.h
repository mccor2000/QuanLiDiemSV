#ifndef _DSLTC_H
#define _DSLTC_H

#include <iostream>
#include <string.h>
#include <fstream>
#include"../../include/DangKy/DangKy.h"
#include"../../include/templates/LinkedList.h"

using namespace std;

const int LOP_MAX = 10000;

struct Lop {
	int malop;
	char maMH[10];
	short nienkhoa;
	short hocki;
	short nhom;
	bool huylop;
	int sv_max;
	int sv_min;
	LinkedList<Register> dsdk; 
  Lop(int, char *, short, short, short, int, int);
  Lop() {;}
};

class LOPTC {
	private:
		int n;
		int stt;
	public:
		Lop *node[LOP_MAX];
	//--
	public:
		Lop* getLop();
		void setLop(Lop* &lop_tmp);
		int getN();
		void setN(int n_tmp);
		void khoiTaoDS();
		bool isFull();
		bool isEmpty();
		void insertLast(Lop &lop);
		void insertOrder(Lop &lop, int pos);
		int search(int malop_tmp);
		void xuatDS();
		void nhapLop(Lop &lop);
		void themLop(Lop &lop, int pos);
		void xoaLop(int malop_del);
		void xoaDS();
		void thongBao(char* s);
    void save_to_file(char *);
    void get_from_file(char *);
};
#endif
