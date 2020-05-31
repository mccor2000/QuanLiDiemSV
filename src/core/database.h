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
public:
  DanhSachLopTC dsltc;
  DanhSachLopCQ dslcq;
  DanhSachMonHoc dsmh;

  // Constructor
  Database() {;}

  void load() {
    dsltc.load();
    dslcq.load();
    dsmh.load();
  }
  // Getters
  DanhSachLopTC get_dsltc()       { return dsltc; }
  DanhSachLopCQ get_dslcq()       { return dslcq; }
  DanhSachMonHoc get_dsmh()       { return dsmh; }
};
#endif
