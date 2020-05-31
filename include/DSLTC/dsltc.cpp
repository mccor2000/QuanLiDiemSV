#include "dsltc.h"

LopTC::LopTC(char* ma_mh, char* nien_khoa, short hoc_ki, short n, int max, int min) {
  strcpy(maMH, ma_mh);
  strcpy(nienkhoa,nien_khoa);
  hocki = hoc_ki;
  nhom = n;
  sv_max = max;
  sv_min = min;
  dsdk = new DanhSachSinhVienDK();
  huylop = true;
}

LopTC* DanhSachLopTC::getLop(int i) {
	return node[i] ;
}

int DanhSachLopTC::get_STT() {
  return stt;
}

void DanhSachLopTC::setLop(LopTC lop_tmp, int i) {
	*node[i] = lop_tmp;
}

int DanhSachLopTC::getN() {
	return n;
}

void DanhSachLopTC::setN(int n_tmp) {
	n = n_tmp;
}

void DanhSachLopTC::khoiTaoDS() {
	n=0;
	stt=0;
}

bool DanhSachLopTC::isFull() {
	return n == LOP_MAX;
}

bool DanhSachLopTC::isEmpty() {
	return n == 0;
}

void DanhSachLopTC::insertOrder(LopTC &lop, int pos) {
	n++;
	for (int i=n-1; i>pos; i--) {
		node[i] = node[i-1];
	}
	node[pos] = new LopTC();
	*node[pos] = lop;
  stt++;
}

void DanhSachLopTC::insertLast(LopTC &lop) {
	n++;
	node[n-1] = new LopTC();
	*node[n-1] = lop;
  lop.malop = stt;
  stt++;
}

int DanhSachLopTC::search(int malop_tmp) {
	for (int i=0; i<n; i++) {
		if (node[i]->malop==malop_tmp) {
			return i;
		}
	}
	return -1;
}

void DanhSachLopTC::thongBao(char* s) {
	cout<<s;
}
void DanhSachLopTC::xuatDS() {
	cout<<"MALOP\tMAMH\tNIENKHOA\tHOCKI\tNHOM\n";
	for (int i=0; i<n; i++) {
		cout<<node[i]->malop<<"\t"<<node[i]->maMH<<"\t"<<node[i]->nienkhoa<<"\t\t"<<node[i]->hocki<<"\t"<<node[i]->nhom<<"\n";
	}
}

void DanhSachLopTC::themLop(LopTC &lop, int pos) {
	if (isFull()) {
		thongBao((char *)"Danh sach day");
		return;
	}
	lop.malop = stt;
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

void DanhSachLopTC::xoaLop(int malop_del) {
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

void DanhSachLopTC::xoaDS() {
	if (isEmpty()) {
		thongBao((char *)"Danh sach rong");
		return;
	}
	while (n>0) {
		delete node[n-1];
		n--;
	}
}

void DanhSachLopTC::save() {
  // Open file
  ofstream f;
  f.open(db, std::ios::binary);
  
  // Save
  for (int i = 0; i < n; i++) {
    // Save LopTC
    f.write((char *)node[i], sizeof(LopTC));  
    // Save dsdk
    if (node[i]->dsdk) {
      const char * temp = std::to_string(node[i]->malop).c_str(); 
      node[i]->dsdk->save(temp);
    }
  }

  // Close file
  f.close();
}

void DanhSachLopTC::load() {
  // Open file
  ifstream f;
  f.open(db, std::ios::binary);
  
  // Load
  LopTC* temp = new LopTC(); 
  while (f.read((char *)temp, sizeof(LopTC))) {
    const char * temp_malop = std::to_string(temp->malop).c_str(); 
    temp->dsdk->load((char *)temp_malop);
    insertLast(*temp);
  }

  // Close file 
  f.close();
}
