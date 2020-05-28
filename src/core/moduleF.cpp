#include "library.h"



void in_dsmh(DanhSachMonHoc& dsmh) {
  dsmh.enumerate([](MonHoc x) {
    LinkedList<char* []> result;
    char* res[5];
    strcpy(res[0],x.MAMH);
    strcpy(res[1],x.TENMH);
    strcpy(res[2],converting(x.STCLT));
    strcpy(res[3],converting(x.STCTH));
    result.push_back(res);
    return result;
  });
}

