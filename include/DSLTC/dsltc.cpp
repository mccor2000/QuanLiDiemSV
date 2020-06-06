#include "dsltc.h"

LopTC::LopTC(char* ma_mh, char* nien_khoa, short hoc_ki, short n, int max, int min) {
  strcpy(maMH, ma_mh);
  strcpy(nienkhoa,nien_khoa);
  hocki = hoc_ki;
  nhom = n;
  sv_max = max;
  sv_min = min;
  dsdk = NULL;
  huylop = true;
}

LopTC::LopTC(){
  dsdk = new DanhSachSinhVienDK();
}

LopTC* DanhSachLopTC::get_by_id(int i) {
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

void DanhSachLopTC::themLop(LopTC &lop, int pos) {
	if (isFull()) {
		return;
	}
	lop.malop = stt;
	if (pos>n) {
		insertLast(lop);
	}
	else {
		insertOrder(lop,pos);
	}
}

void DanhSachLopTC::xoaLop(int malop_del) {
	if (isEmpty()) {
		return;
	}
	int pos=search(malop_del);
	if (pos==-1) {
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
<<<<<<< HEAD
  f.open(db, std::ios::binary);
  // Save
=======
  f.open(db, std::ios::out);
  
  // Save STT & N
  f<<stt<<"\t"<<n<<"\n";

  // Save dsltc
>>>>>>> 274d1a2201193053cbaa8575136a5941269a95c7
  for (int i = 0; i < n; i++) {
    // Save LopTC
    f<<node[i]->malop<<"\t"
	 <<node[i]->maMH<<"\t"
	 <<node[i]->nienkhoa<<"\t"
	 <<node[i]->hocki<<"\t"
	 <<node[i]->nhom<<"\t"
	 <<node[i]->sv_max<<"\t"
	 <<node[i]->sv_min<<"\t"
	 <<node[i]->huylop<<"\n";  
    // Save dsdk
    if (node[i]->dsdk != NULL) {
      const char * temp = std::to_string(node[i]->malop).c_str();
      node[i]->dsdk->save(temp);
    }
  }
  // Close file
  f.close();
}

void DanhSachLopTC::load() {
  // Open file DSLTC
  ifstream f;
  f.open(db, std::ios::in);

  f>>stt>>n;
  for (int i=0; i<n; i++) {
	  node[i] = new LopTC();
	  f>>node[i]->malop
	   >>node[i]->maMH
	   >>node[i]->nienkhoa
	   >>node[i]->hocki
	   >>node[i]->nhom
	   >>node[i]->sv_max
	   >>node[i]->sv_min
	   >>node[i]->huylop;

	  const char * temp = std::to_string(node[i]->malop).c_str(); 
	  node[i]->dsdk->load(temp);
  }

  // Close file DSLTC
  f.close();
}
