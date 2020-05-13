#ifndef _DSLTC_H
#define _DSLTC_H

#include <iostream>
#include <string.h>
#include <fstream>

#include"../../include/DSDK/dsdk.h"


using namespace std;

const int LOP_MAX = 10000;

struct Lop {
	int malop;
	char maMH[10];
	char nienkhoa[10];
	short hocki;
	short nhom;
	bool huylop;
	int sv_max;
	int sv_min;
	DanhSachSinhVienDK * dsdk; 

	Lop(char* maMH, char* nienkhoa, short hocki, short nhom, int sv_max, int sv_min);
	Lop() {;}

  void save();
};

class LOPTC {
private:
	int n = 0;
	int stt = 0;
	char db[32] = "../../database/dsltc.d";
	
public:
	Lop *node[LOP_MAX];
		
    	Lop* getLop();
	int get_STT();
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
	void save();
	void load();
};
#endif
