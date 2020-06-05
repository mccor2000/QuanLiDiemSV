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

  LopTC curr_loptc;
  LopCQ curr_lopcq;
  MonHoc curr_mh;

  SinhVien curr_sv;
  SinhVienDK curr_svdk;
  DanhSachSinhVien curr_dssv;
  DanhSachSinhVienDK curr_dsdk;
public:
  // Constructor
  Database() {
    dsltc.load();
    dslcq.load();
    dsmh.load();
  }

  // Getters
  DanhSachLopTC get_dsltc()                   { return dsltc; }
  DanhSachLopCQ get_dslcq()                   { return dslcq; }
  DanhSachMonHoc get_dsmh()                   { return dsmh; }
  
  LopTC get_curr_loptc()                      { return curr_loptc; }
  LopCQ get_curr_lopcq()                      { return curr_lopcq; }
  MonHoc get_curr_mh()                         { return curr_mh; }
    
  SinhVien get_curr_sv()                      { return curr_sv; }      
  SinhVienDK get_curr_svdk()                  { return curr_svdk; }      
  DanhSachSinhVien get_curr_dssv()            { return curr_dssv; }      
  DanhSachSinhVienDK get_curr_dsdk()          { return curr_dsdk; } 

  // Setters
  void set_curr_loptc(LopTC x)                { curr_loptc = x; }
  void set_curr_lopcq(LopCQ x)                { curr_lopcq = x; }
  void set_curr_mh(MonHoc x)                  { curr_mh = x; }
  
  void set_curr_sv(SinhVien x)                { curr_sv = x; }
  void set_curr_svdk(SinhVienDK x)            { curr_svdk = x; }
  void set_curr_dssv(DanhSachSinhVien x)      { curr_dssv = x; }
  void set_curr_dsdk(DanhSachSinhVienDK x)    { curr_dsdk = x; }
};

#endif
