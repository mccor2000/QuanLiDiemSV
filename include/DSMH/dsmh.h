#pragma once
#include <fstream>
#include <iostream>
/****************** MON HOC *******************/ 
class MonHoc {
public:
  //** Props
  char MAMH[10];   
  char TENMH[50];
  int STCLT;
  int STCTH;
  
  //** Constructor 
  MonHoc(char* , char*, int, int);
  MonHoc() {;} 
  //** Operator overloading
  bool operator>(MonHoc);
  bool operator<(MonHoc);
  bool operator==(MonHoc);
};

/*************** AVL TREE NODE ****************/
class node {
public:
  //** Props
  MonHoc key;
  int height;
  node *left;
  node *right;

  //** Constructor
  node(MonHoc);
};

/***************** AVL TREE *******************/
class DanhSachMonHoc {
public:
  //** Props
  int length;
  node * root;

  //** Constructor
  DanhSachMonHoc();
 
  //** Public methods
  void insert(MonHoc);
  void remove(MonHoc);
  node * search(char *);
  void enumerate();
  void get_from_file(char *);
  void save_to_file(char *);

private:
  //** Utils
  int height(node *);
  //** AVL methods
  node * left_rotate(node *);
  node * right_rotate(node *);
  
  node * insert_node(node *, MonHoc);
  node * remove_node(node *, MonHoc);
  node * search_node(node *, char *);
  
  void in_order(node *);
  void save_node(node *, std::ofstream &);
};
