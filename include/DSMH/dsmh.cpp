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
//---- Operators
bool MonHoc::operator > (MonHoc x) {
  return (strcmp(MAMH, x.MAMH) > 0);
}

bool MonHoc::operator < (MonHoc x) {
  return (strcmp(MAMH, x.MAMH) < 0);
}

bool MonHoc::operator == (MonHoc x) {
  return (strcmp(MAMH, x.MAMH) == 0);
}

//---- Utils
int MonHoc::get_balance() {
  return left->height - right->height; 
}

void MonHoc::update_height() {
  if (this == NULL)
    height = -1;
  else 
    height = 1 + (left->height > right->height ? left->height : right->height);
}

//---- AVL tree methods 
MonHoc * MonHoc::left_rotate(MonHoc * node) {
  // Exchange nodes
  MonHoc * new_node= node->right;
  node->right = new_node->left;
  new_node->left = node;
  
  // Update height
  node->update_height();
  new_node->update_height();

  return new_node;
}

MonHoc * MonHoc::right_rotate(MonHoc * node) {
  // Exchange nodes
  MonHoc * new_node = node->left;
  node->left = new_node->right;
  new_node->right = node;
  // Update height
  node->update_height();
  new_node->update_height();
  
  return new_node;
}

MonHoc * MonHoc::insert_node(MonHoc * node) {
  if (node == NULL) {
    return node;
  } 

  if (node > this) {
    right = insert_node(node);   
  } else if (node < this) {
    left = insert_node(node);
  }  
  update_height();

  if (get_balance() > 1) {
    if (node < left) {
      return right_rotate(this);
    } else {
      left = left_rotate(left);
      return right_rotate(this);
    } 
  } else if (get_balance() < -1) {
    if (node > right) {
      return left_rotate(this); 
    } else {
      right = right_rotate(right);
      return left_rotate(this);
    }
  }
  return this; 
}

MonHoc * MonHoc::remove_node(MonHoc * node) {

}

MonHoc * MonHoc::search_node(char * s) {
  if (this == NULL) 
    return NULL;
  
  if (strcmp(s, TENMH) > 0) 
    return right->search_node(s);
  else if (strcmp(s, TENMH) < 0) 
    return left->search_node(s);
  else 
    return this;
}

void MonHoc::in_order_traversal() {
  if (left != NULL || right != NULL) {
    left->in_order_traversal();
    std::cout << TENMH << std::endl;
    right->in_order_traversal();
  } else {
    std::cout << TENMH << std::endl;
  }
}

/************* AVL tree methods ****************/
DanhSachMonHoc::DanhSachMonHoc() {
  length = 0;
  root = NULL;
}

void DanhSachMonHoc::insert(MonHoc * x) {
  root = root->insert_node(x);
}

void DanhSachMonHoc::remove(MonHoc * x) {
  root = root->remove_node(x);    
}

MonHoc* DanhSachMonHoc::search(char * s) {
  return root->search_node(s);
}

void DanhSachMonHoc::enumerate() {
  root->in_order_traversal();
}
