#include <iostream>
#include <string.h>

using namespace std;

const int LOP_MAX = 10000;
	
class LOPTC {
	public:
		struct Lop {
			int malop;
			char maMH[10];
			int nienkhoa;
			int hocki;
			int	nhom;
			bool huylop;
			int sv_max;
			int sv_min;
		};
		//--
		struct List {
			int n;
			int stt;
			Lop *node [LOP_MAX];
		};
	//--
	private:
		List list;
	//--
	public:
		List getList();
		void setList(List &tmp);
		void khoiTaoDS();
		bool isFull();
		bool isEmpty();
		void insertLast(Lop &lop);
		void insertOrder(Lop &lop, int pos);
		int search(int malop_tmp);
		void nhapDS();
		void xuatDS();
		void nhapLop(Lop &lop);
		void themLop(Lop &lop, int pos);
		void xoaLop(int malop_del);
		void xoaDS();
		void thongBao(char* s);
};
