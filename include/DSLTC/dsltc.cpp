#include "dsltc.h"

Lop::Lop(char * ma_mh, char * nien_khoa, short hoc_ki, short n, int max, int min) {
  strcpy(maMH, ma_mh);
  strcpy(nienkhoa, nien_khoa);
  hocki = hoc_ki;
  nhom = n;
  sv_max = max;
  sv_min = min;
  dsdk = new DanhSachSinhVienDK();
  huylop = false;
}

Lop* LOPTC::getLop() {
	return *node ;
}

int LOPTC::get_STT() {
  return stt;
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
  stt++;
}

void LOPTC::insertLast(Lop &lop) {
	n++;
	node[n-1] = new Lop();
	*node[n-1] = lop;
  lop.malop = stt;
  stt++;
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
void LOPTC::xuatDS() {
	cout<<"MALOP\tMAMH\tNIENKHOA\tHOCKI\tNHOM\n";
	for (int i=0; i<n; i++) {
		cout<<node[i]->malop<<"\t"<<node[i]->maMH<<"\t"<<node[i]->nienkhoa<<"\t\t"<<node[i]->hocki<<"\t"<<node[i]->nhom<<"\n";
	}
}

void LOPTC::themLop(Lop &lop, int pos) {
	if (isFull()) {
		thongBao((char *)"Danh sach day");
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
		thongBao((char *)"Danh sach rong");
		return;
	}
	int pos=search(malop_del);
	if (pos==-1) {
		thongBao((char *)"Ma lop khong ton tai");
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
		thongBao((char *)"Danh sach rong");
		return;
	}
	while (n>0) {
		delete node[n-1];
		n--;
	}
}

void LOPTC::save() {
  // Open file
  ofstream f;
  f.open(db, std::ios::binary);
  
  // Save
  for (int i = 0; i < n; i++) {
    // Save LopTC
    f.write((char *)node[i], sizeof(Lop));  
    // Save dsdk
    const char * temp = std::to_string(node[i]->malop).c_str(); 
    node[i]->dsdk->save(temp);
  }

  // Close file
  f.close();
}

void LOPTC::load() {
  // Open file
  ifstream f;
  f.open(db, std::ios::binary);
  
  // Load
  Lop* temp = new Lop(); 
  while (f.read((char *)temp, sizeof(Lop))) {
    const char * temp_malop = std::to_string(temp->malop).c_str(); 
    temp->dsdk->load((char *)temp_malop);
    insertLast(*temp);
  }

  // Close file 
  f.close();
}
