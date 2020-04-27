#include <iostream>
#include "dsmh.h"


/************** AVL node methods ***************/
MonHoc::MonHoc(char* mamh, char* tenmh, int stclt, int stcth) {
  this->MAMH = mamh;
  this->tenmh = tenmh;
  this->stclt = stclt;
  this->stcth = stcth;

  this->height = 0;
  this->left = NULL;
  this->right = NULL;
}

int MonHoc::get_balance() {
  return left->height - right->height; 
}

void MonHoc::update_height() {
  this->height = 1 + (left->height > right->height ? left->height : right->height);
}

void MonHoc::left_rotate() {
  // Exchange nodes
  MonHoc *tmp = this->right;
  this->right = tmp->left;
  tmp->left = this;
  
  // Update height
  this->update_height();
  tmp->update_height();
}

void MonHoc::right_rotate() {
  // Exchange nodes
  MonHoc *tmp = this->left;
  this->left = tmp->right;
  tmp->right = this;
  
  // Update height
  this->update_height();
  tmp->update_height();
}

/************* AVL tree methods ****************/
DanhSachMonHoc::DanhSachMonHoc() {
  length = 0;
  root = NULL;
}

void DanhSachMonHoc::insert(MonHoc *) {

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

