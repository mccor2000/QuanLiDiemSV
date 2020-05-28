#include "library.h"


LinkedList<char* []> in_dsmh(DanhSachMonHoc& dsmh) {
  LinkedList<char* []> result;
  LinkedList<MonHoc> list_mh;
  dsmh.enumerate([list_mh](MonHoc x) mutable { 
    list_mh.push_back(x); 
  });
  Node<MonHoc>* node= list_mh.head();
  while(node != NULL){
    char* res[5];
    strcpy(res[0],node->get_data().MAMH);
    strcpy(res[1],node->get_data().TENMH);
    strcpy(res[2],converting(node->get_data().STCLT));
    strcpy(res[3],converting(node->get_data().STCTH));
    result.push_back(res);
    node  = node->get_next();
  }
  return result;  
}

