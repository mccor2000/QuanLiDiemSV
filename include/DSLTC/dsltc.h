#include <iostream>
#include <string.h>
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
};

class LOPTC {
	private:
		int n;
		int stt;
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
};
