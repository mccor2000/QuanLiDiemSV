#pragma once

/*************** AVL TREE NODE ****************/
class MonHoc {

public:
  //** Info properties
  char MAMH[10];   
  char TENMH[50]; // Key
  int STCLT;
  int STCTH;

  //** AVL tree properties
  int height;
  MonHoc *left;
  MonHoc *right;
  
  //** AVL methods
  int get_balance();
  void left_rotate();
  void right_rotate();
};

/***************** AVL TREE *******************/
class DanhSachMonHoc {

public:
  //** Properties
  int n;
  MonHoc* root;

  //** Constructor
  DanhSachMonHoc(MonHoc *);
  
  //** Methods
  
  // Modify contents
  void insert(MonHoc *);
  void remove(MonHoc *);
  
  // Informational, search
  MonHoc* search_name(char *);
  MonHoc* search_code(char *);
  
  // Enumeration
  void pre_oder_traversal();
  void post_order_traversal();
  void in_order_traversal();
};
