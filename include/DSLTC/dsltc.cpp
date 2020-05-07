#include "dsltc.h"

Lop::Lop(char * ma_mh, short nien_khoa, short hoc_ki, short n, int max, int min) {
  strcpy(maMH, ma_mh);
  nienkhoa = nien_khoa;
  hocki = hoc_ki;
  nhom = n;
  huylop = false;
  sv_max = max;
  sv_min = min;
}

Lop::Lop(int ma_lop, char * ma_mh, short nien_khoa, short hoc_ki, short n, int max, int min) {
  malop = ma_lop;
  strcpy(maMH, ma_mh);
  nienkhoa= nien_khoa;
  hocki = hoc_ki;
  nhom = n;
  huylop = false;
  sv_max = max;
  sv_min = min;
}

Lop* LOPTC::getLop() {
	return *node ;
}

void LOPTC::setLop(Lop* &lop_tmp) {
	*node = lop_tmp;
}

int LOPTC::getN() {
	return n;
}

void LOPTC::setN(int n_tmp) {
	n = n_tmp;
}

void LOPTC::khoiTaoDS() {
	n=0;
	stt=0;
}

bool LOPTC::isFull() {
	return n == LOP_MAX;
}

bool LOPTC::isEmpty() {
	return n == 0;
}

void LOPTC::insertOrder(Lop &lop, int pos) {
	n++;
	for (int i=n-1; i>pos; i--) {
		node[i] = node[i-1];
	}
	node[pos] = new Lop();
	*node[pos] = lop;
}

void LOPTC::insertLast(Lop &lop) {
	n++;
	node[n-1] = new Lop();
	*node[n-1] = lop;
}

int LOPTC::search(int malop_tmp) {
	for (int i=0; i<n; i++) {
		if (node[i]->malop==malop_tmp) {
			return i;
		}
	}
	return -1;
}

void LOPTC::thongBao(char* s) {
	cout<<s;
}

void LOPTC::nhapLop(Lop &lop) {
	stt++;
	lop.malop=stt;
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
	cout<<"Nhap so luong sv toi thieu: ";
	cin>>lop.sv_min;
	cout<<"Nhap so luong sv toi da: "; 
	cin>>lop.sv_max;
}

void LOPTC::xuatDS() {
	system("cls");
	cout<<"MALOP\tMAMH\tNIENKHOA\tHOCKI\tNHOM\n";
	for (int i=0; i<n; i++) {
		cout<<node[i]->malop<<"\t"<<node[i]->maMH<<"\t"<<node[i]->nienkhoa<<"\t\t"<<node[i]->hocki<<"\t"<<node[i]->nhom<<"\n";
	}
}

void LOPTC::themLop(Lop &lop, int pos) {
	if (isFull()) {
		thongBao("Danh sach day");
		return;
	}
	if (pos<0) {
		insertOrder(lop,0);
	}
	else if (pos>n) {
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
	delete node[pos];
	for (int i=pos; i<n-1; i++) {
		node[i] = node[i+1];
	}
	n--;
}

void LOPTC::xoaDS() {
	if (isEmpty()) {
		thongBao("Danh sach rong");
		return;
	}
	while (n>0) {
		delete node[n-1];
		n--;
	}
}

void LOPTC::save_to_file(char * file_path) {
  ofstream f;
  f.open(file_path, std::ios::binary);
  for (int i = 0; i < n; i++) {
    f.write((char *)node[i], sizeof(Lop));  
  }
  f.close();
}

void LOPTC::get_from_file(char * file_path) {
  ifstream f;
  f.open(file_path, std::ios::binary);
  Lop* temp = new Lop(); 
  
  while (f.read((char *)temp, sizeof(Lop))) {
    insertLast(*temp);
  }
  f.close();
}
