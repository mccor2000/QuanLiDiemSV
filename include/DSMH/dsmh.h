#pragma once

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
class Node {

public:
  //** Props
  MonHoc key;
  int height;
  Node *left;
  Node *right;

  //** Constructor
  Node(MonHoc);
};

/***************** AVL TREE *******************/
class DanhSachMonHoc {

public:
  //** Props
  int length;
  Node * root;

  //** Constructor
  DanhSachMonHoc();
 
  //** Public methods
  void insert(MonHoc);
  void remove(MonHoc);
  Node * search(char *);
  void enumerate();

private:
  //** Utils
  int height(Node *);
  //** AVL methods
  Node * left_rotate(Node *);
  Node * right_rotate(Node *);
  
  Node * insert_node(Node *, MonHoc);
  Node * remove_node(Node *, MonHoc);
  Node * search_node(Node *, char *);

  void in_order(Node *);
};
