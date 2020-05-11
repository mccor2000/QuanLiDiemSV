#include "library.h"

void them_sv(DanhSachLopCQ DSLCQ, char * ma_lop) {
  DanhSachSinhVien * dssv = DSLCQ.get_dssv(ma_lop);
  
  if (dssv == NULL) {
    std::cout << "Lop khong ton tai\n";
    return;
  }
  // Nhap sv
  // ...
  char var[35] = "TEST";
  SinhVien sv(var,var,var,true,var,var);
  dssv->push_back(sv);
}
int vitri_sv(DanhSachSinhVien* DSSV,char* MASV){
  Node<SinhVien>* SV  = DSSV->head();
  int counter = 0;
  bool flag=false;
  while(SV->get_next()!=NULL){
    if(SV->get_data().get_MASV() == MASV)
      flag=true;
    counter++;
    SV = SV->get_next();
  }
  return flag?counter:-1;
}
void xoa_sv(DanhSachLopCQ DSLCQ, char * ma_lop) {
  DanhSachSinhVien * dssv = DSLCQ.get_dssv(ma_lop);

  if (dssv == NULL) {
    std::cout << "Lop khong ton tai\n";
    return;
  }
  // Xoa sv
  // ...
  char MASV[15] = "TEST";
  dssv->remove(vitri_sv(dssv,MASV));
}
void hieu_chinh_sv(DanhSachLopCQ DSLCQ, char * ma_lop) {
  DanhSachSinhVien * dssv = DSLCQ.get_dssv(ma_lop);

  if (dssv == NULL) {
    std::cout << "Lop khong ton tai\n";
    return;
  }
  // Hieu chinh sv
  // ...
  std::cout << "Nhap vao MASV ban muon chinh sua\n";
  char MASV[15];
  fgets(MASV,15,stdin);
  Node<SinhVien>* SV = dssv->head();
  bool flag=false;

  while(SV->get_next() != NULL){
    if(SV->get_data().get_MASV() == MASV){
      flag=true;
      break;
    }
    SV=SV->get_next();
  }
  if(flag){
    int choice;
    char run='n';
    bool sex;
    char str[35];
    do{
      std::cout <<  "Chon thuoc tinh ban muon chinh sua\n";
      std::cin >> choice;
      switch (choice)
        {
          // Sua MASV
        case 1:
          fgets(str,35,stdin);
          SV->get_data().set_MASV(str);
          break;
          // Sua Ho
        case 2:
          fgets(str,35,stdin);
          SV->get_data().set_HO(str);
          
          break;
          // Sua Ten
        case 3:
          fgets(str,35,stdin);
          SV->get_data().set_TEN(str);
          
          break;
          //Sua SDT
        case 4:
          fgets(str,35,stdin);
          SV->get_data().set_SDT(str);
          
          break;
          // Sua MALOP
        case 5:
          fgets(str,35,stdin);
          SV->get_data().set_MALOP(str);

          break;
          // Sua Gioi tinh
        case 6:
          std::cin >> sex;
          SV->get_data().set_PHAI(sex);
          break;
        default:
          std::cout << "Lua chon khong hop le, Ban co muon thoat khoi hieu chinh ? \n Nhan phim Y/N";
          std::cin >> run; 
        }
      }
    while(run == 'n' || run =='N');
  }
  else{
    std::cout << "khong tim thay sinh vien co MASV = " << MASV<<"\n";
  }
}

int main(){
  std::cout << "Hello world\n";
}