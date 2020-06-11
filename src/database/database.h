#ifndef _DATABASE_H_
#define _DATABASE_H_

// Templates
#include "../../include/templates/LinkedList.h"

// Base classes
#include "../../include/DSSV/dssv.h"
#include "../../include/DSDK/dsdk.h"
#include "../../include/DSMH/dsmh.h"
#include "../../include/DSLTC/dsltc.h"
#include "../../include/DSLCQ/dslcq.h"

class Database {
private:
  DanhSachLopTC dsltc;
  DanhSachLopCQ dslcq;
  DanhSachMonHoc dsmh;

  DanhSachLopTC filtered_dsltc;

  LopTC * current_loptc;
  Node<LopCQ> * current_lopcq;
  MonHoc * current_mh;

  Node<SinhVien> * current_sv;
  Node<SinhVienDK> * current_svdk;
  DanhSachSinhVien * current_dssv;
  DanhSachSinhVienDK * current_dsdk;
public:
  // Constructor
  Database() {
    dsltc.load();
    dslcq.load();
    dsmh.load();
  }

  // Getters
  DanhSachLopTC get_dsltc()                          { return dsltc; }
  DanhSachLopCQ get_dslcq()                          { return dslcq; }
  DanhSachMonHoc get_dsmh()                          { return dsmh; }
  
  DanhSachLopTC get_filtered_dsltc()                 { return filtered_dsltc; }

  LopTC * get_current_loptc()                        { return current_loptc; }
  Node<LopCQ> * get_current_lopcq()                  { return current_lopcq; }
  MonHoc * get_current_mh()                          { return current_mh; }
    
  Node<SinhVien> * get_current_sv()                  { return current_sv; }      
  Node<SinhVienDK> * get_current_svdk()              { return current_svdk; }      
  DanhSachSinhVien * get_current_dssv()              { return current_dssv; }      
  DanhSachSinhVienDK * get_current_dsdk()            { return current_dsdk; } 

  // Setters
  void set_current_loptc(LopTC * x)                  { current_loptc = x; }
  void set_current_lopcq(Node<LopCQ> * x)            { current_lopcq = x; }
  void set_current_mh(MonHoc * x)                    { current_mh = x; }
  
  void set_current_sv(Node<SinhVien> * x)            { current_sv = x; }
  void set_current_svdk(Node<SinhVienDK> * x)        { current_svdk = x; }
  void set_current_dssv(DanhSachSinhVien * x)        { current_dssv = x; }
  void set_current_dsdk(DanhSachSinhVienDK * x)      { current_dsdk = x; }
};

#endif
