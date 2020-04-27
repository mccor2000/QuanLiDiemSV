#include <iostream>
#include <cstring>
#include "dsmh.h"


/************** AVL node methods ***************/
MonHoc::MonHoc(char * mamh, char * tenmh, int stclt, int stcth) {
  strcpy(MAMH, mamh);
  strcpy(TENMH, tenmh);
  STCLT = stclt;
  STCTH = stcth;

  height = 0;
  left = NULL;
  right = NULL;
}

// Utils
int MonHoc::compare_to(MonHoc * x) {
  int max = (strlen(TENMH) > strlen(x->TENMH)) ? strlen(TENMH) : strlen(x->TENMH);

  for (int i = 0; i <= max; i++) {
    if (TENMH[i] > x->TENMH[i]) {
      return 1;
    } else if (TENMH[i] < x->TENMH[i]) {
      return -1;
    }
  }
  return 0;
}

int MonHoc::get_balance() {
  return left->height - right->height; 
}

void MonHoc::update_height() {
  if (this == NULL)
    height = -1;
  else 
    height = 1 + (left->height > right->height ? left->height : right->height);
}

// AVL tree methods 
void MonHoc::left_rotate() {
  // Exchange nodes
  MonHoc *tmp = right;
  right = tmp->left;
  tmp->left = this;
  
  // Update height
  update_height();
  tmp->update_height();
}

void MonHoc::right_rotate() {
  // Exchange nodes
  MonHoc *tmp = left;
  left = tmp->right;
  tmp->right = this;
  
  // Update height
  update_height();
  tmp->update_height();
}

bool MonHoc::insert_to(MonHoc * node) {
  if (node == NULL) {
    node = this;
    return true;
  } 

  if (compare_to(node) == 1) {
    return insert_to(node->right);
  } else if (compare_to(node) == -1) {
    return insert_to(node->left);
  } 
   
  return false; 
}

/************* AVL tree methods ****************/
DanhSachMonHoc::DanhSachMonHoc() {
  length = 0;
  root = NULL;
}

void DanhSachMonHoc::insert(MonHoc * x) {
  // BST insert 
  x->insert_to(root);

  // 
}

void DanhSachMonHoc::remove(MonHoc *) {
    
}

MonHoc* DanhSachMonHoc::search_name(char *) {

}

MonHoc* DanhSachMonHoc::search_code(char *) {

}

void DanhSachMonHoc::pre_oder_traversal() {

}

void DanhSachMonHoc::post_order_traversal() {

}

void DanhSachMonHoc::in_order_traversal() {

}

