#ifndef _DSMH_H
#define _DSMH_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <functional>

#include "../../src/helpers/helpers.h"

/********** MON HOC as a KEY of a node *********/ 
class MonHoc {
public:
  // Properties 
  char MAMH[10];   
  char TENMH[50];
  int STCLT;
  int STCTH;
  
  // Constructor 
  MonHoc(char* , char*, int, int);
  MonHoc() {;}

  // Operator overloading 
  bool operator>(MonHoc);
  bool operator<(MonHoc);
  bool operator==(MonHoc);
  
  // Methods
  void init_from_string(char **);
};

/*************** AVL TREE NODE ****************/
class node {
public:
  // Properties 
  MonHoc key;
  int height;
  node *left;
  node *right;

  // Constructor 
  node(MonHoc);
};

/***************** AVL TREE *******************/
class DanhSachMonHoc {
public:
  // Properties
  int length;
  node * root; 
  char db[32] = "../database/dsmh.d";

  // Constructor
  DanhSachMonHoc();
 
  /* * 
   * Public methods contain methods that manipulate the 
   * list directly and hide the logic under the hood.  
   */ 
  void insert(MonHoc);
  void remove(MonHoc);
  void update(MonHoc, MonHoc);

  bool is_exist(MonHoc);

  MonHoc * search_name(char *);
  MonHoc * search_code(char *);
  
  void enumerate(std::function<void(MonHoc)>); 
  
  // File IO
  void load();
  void save();

private:
  /* *
   * Private methods contain methods that interract with
   * the AVL tree and being called by public methods.    
   */
  int height(node *);
  
  node * left_rotate(node *);
  node * right_rotate(node *);
  
  node * insert_node(node *, MonHoc);
  node * remove_node(node *, MonHoc);

  MonHoc * search_name_node(node *, char *);
  MonHoc * search_code_node(node *, char *);
  
  bool check_exist(node *, MonHoc);

  void in_order(node *, std::function<void(MonHoc)>);
  void save_node(node *, std::ofstream &);
};
#endif