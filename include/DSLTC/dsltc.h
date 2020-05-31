#ifndef _DSLTC_H
#define _DSLTC_H

#include <iostream>
#include <string.h>
#include <fstream>

#include"../../include/DSDK/dsdk.h"


using namespace std;

const int LOP_MAX = 10000;

struct LopTC {
	int malop;
	char maMH[10];
	char nienkhoa[10];
	short hocki;
	short nhom;
	bool huylop;
	int sv_max;
	int sv_min;
	DanhSachSinhVienDK * dsdk; 

	LopTC(char* maMH, char* nienkhoa, short hocki, short nhom, int sv_max, int sv_min);
	LopTC() {;}

  void save();
};

class DanhSachLopTC {
private:
	int n = 0;
	int stt = 0;
	char db[32] = "../database/dsltc.d";
	
public:
	LopTC *node[LOP_MAX];
		
    	LopTC* getLop();
	int get_STT();
    	void setLop(LopTC* &lop_tmp);
	int getN();
	void setN(int n_tmp);
	void khoiTaoDS();
	bool isFull();
	bool isEmpty();
	void insertLast(LopTC &lop);
	void insertOrder(LopTC &lop, int pos);
	int search(int malop_tmp);
	void xuatDS();
	void themLop(LopTC &lop, int pos);
	void xoaLop(int malop_del);
	void xoaDS();
	void thongBao(char* s);
	void save();
	void load();
};
#endif
