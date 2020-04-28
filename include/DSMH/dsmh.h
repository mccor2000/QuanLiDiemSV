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
  
  //** Constructor 
  MonHoc(char* , char*, int, int);
 
  //** Operator overloading
  bool operator>(MonHoc);
  bool operator<(MonHoc);
  bool operator==(MonHoc);

  //** Utils
  int get_balance();
  void update_height();

  //** AVL methods
  MonHoc * left_rotate(MonHoc *);
  MonHoc * right_rotate(MonHoc *);
  
  MonHoc * insert_node(MonHoc *);
  MonHoc * remove_node(MonHoc *);
  MonHoc * search_node(char *);

  void in_order_traversal();
};

/***************** AVL TREE *******************/
class DanhSachMonHoc {

public:
  //** Properties
  int length;
  MonHoc* root;

  //** Constructor
  DanhSachMonHoc();
 
  //** Methods
  
  // Modify contents
  void insert(MonHoc *);
  void remove(MonHoc *);
  
  // Informational, search
  MonHoc* search(char *);
  
  // Enumeration
  void enumerate();
};
