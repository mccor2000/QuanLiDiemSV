#include "dsmh.h"

/************** MONHOC ***************/
MonHoc::MonHoc(char * mamh, char * tenmh, int stclt, int stcth) {
  strcpy(MAMH, mamh);
  strcpy(TENMH, tenmh);
  STCLT = stclt;
  STCTH = stcth;
}

bool MonHoc::operator > (MonHoc x) {
  return (strcmp(MAMH, x.MAMH) > 0);
}

bool MonHoc::operator < (MonHoc x) {
  return (strcmp(MAMH, x.MAMH) < 0);
}

bool MonHoc::operator == (MonHoc x) {
  return (strcmp(MAMH, x.MAMH) == 0);
}
/************* AVL NODE *****************/
node::node(MonHoc k) {
  key = k;
  height = 1;
  left = NULL;
  left = NULL;
}
/************* AVL TREE *****************/

DanhSachMonHoc::DanhSachMonHoc() {
  length = 0;
  root = NULL;
}

//** Utils
int DanhSachMonHoc::height(node * n) {
  if (n == NULL) {
    return 0;
  }
  return n->height;
}

//** Private methods

node * DanhSachMonHoc::left_rotate(node * n) {
  // Exchange nodes
  node * new_n = n->right;
  n->right = new_n->left;
  new_n->left = n;
  // Update height
  n->height = 1 + std::max(height(n->left), height(n->right));
  new_n->height = 1 + std::max(height(new_n->left), height(new_n->right));
  return new_n;
}

node * DanhSachMonHoc::right_rotate(node * n) {
  // Exchange nodes
  node * new_n = n->left;
  n->left = new_n->right;
  new_n->right = n;
  // Update height
  n->height = 1 + std::max(height(n->left), height(n->right));
  new_n->height = 1 + std::max(height(new_n->left), height(new_n->right));
  
  return new_n;
}

node * DanhSachMonHoc::insert_node(node * n, MonHoc x) {
  if (n == NULL) {
    length += 1;
    node * tmp = new node(x);
    return tmp;
  } 

  if (x < n->key) {
    n->left= insert_node(n->left, x);
  } else if (x > n->key) {
    n->right= insert_node(n->right, x);
  } else {
    length += 1;
    node * tmp = new node(x);
    return tmp;
  }

  n->height = 1 + std::max(height(n->left), height(n->right));

  int bal = height(n->left) - height(n->right);

  if (bal > 1) {
    if (x < n->left->key) {
      return right_rotate(n);
    } else {
      n->left = left_rotate(n->left);
      return right_rotate(n);
    }
  } else if (bal < -1) {
    if (x > n->right->key) {
      return left_rotate(n);
    } else {
      n->right = right_rotate(n->right);
      return left_rotate(n);
    }
  }
  return n; 
}

node * DanhSachMonHoc::remove_node(node * n, MonHoc x) {
  if (n == NULL) 
    return NULL;
  if (x < n->key) {
    n->left = remove_node(n->left, x);
  } else if (x > n->key) {
    n->right = remove_node(n->right, x);
  } else {
    node * r = n->right;
    if (n->right == NULL) {
      node * l = n->left;
      delete(n);
      length--;
      n = l;

    } else if (n->left == NULL) {
      delete(n);
      length--;
      n = r;
    } else {
      while (r->left != NULL) 
        r = r->left;
      
      n->key = r->key;
      n->right = remove_node(n->right, r->key);
    }
  }

  if (n == NULL) 
    return NULL;
  
  n->height = 1 + std::max(height(n->left), height(n->right));
  int bal = height(n->left) - height(n->right);
  
  if (bal > 1) {
    if (x < n->left->key) {
      return right_rotate(n);
    } else {
      n->left = left_rotate(n->left);
      return right_rotate(n);
    } 
  } else if (bal < -1) {
    if (x > n->right->key) {
      return left_rotate(n); 
    } else {
      n->right = right_rotate(n->right);
      return left_rotate(n);
    }
  }

  return n;
}

node * DanhSachMonHoc::update_node(node * n, MonHoc x, MonHoc new_x) {
  if (n == NULL) return NULL;
   
  if (x < n->key) {
    n->left= update_node(n->left, x, new_x);
  } else if (x > n->key) {
    n->right= update_node(n->right, x, new_x);
  } else {
    n->key = new_x;
    return n;
  }

  n->height = 1 + std::max(height(n->left), height(n->right));

  int bal = height(n->left) - height(n->right);

  if (bal > 1) {
    if (new_x < n->left->key) {
      return right_rotate(n);
    } else {
      n->left = left_rotate(n->left);
      return right_rotate(n);
    }
  } else if (bal < -1) {
    if (new_x > n->right->key) {
      return left_rotate(n);
    } else {
      n->right = right_rotate(n->right);
      return left_rotate(n);
    }
  }
  return n; 
}

MonHoc * DanhSachMonHoc::search_name_node(node * n, char * s) {
  if (n == NULL) 
    return NULL;
  
  if (strcmp(s, n->key.TENMH) > 0) 
    return search_name_node(n->right, s);
  else if (strcmp(s, n->key.TENMH) < 0) 
    return search_name_node(n->left, s);
  else 
    return &n->key;
}

MonHoc * DanhSachMonHoc::search_code_node(node * n, char * s) {
  if (n == NULL) 
    return NULL;
    
  if (strcmp(s, n->key.MAMH) > 0) 
    return search_code_node(n->right, s);
  else if (strcmp(s, n->key.MAMH) < 0) 
    return search_code_node(n->left, s);
  else 
    return &n->key;    
}

void DanhSachMonHoc::in_order(node * n, LinkedList<MonHoc>& list_mh) {
  if (n != NULL) {
    in_order(n->left, list_mh);
    list_mh.push_back(n->key);
    in_order(n->right, list_mh);
  }
}

void DanhSachMonHoc::save_node(node * n, std::ofstream &f) {
  if (n != NULL) {
    save_node(n->left, f);
    f.write((char *)&(n->key), sizeof(MonHoc)); 
    save_node(n->right, f);
  }  
}

bool DanhSachMonHoc::check_exist(node * n, MonHoc x) {
  if (n == NULL) return false;

  if (x > n->key) {
    return check_exist(n->right, x);  
  } else if ( x < n->key) {
    return check_exist(n->left, x);
  } else {
    return true;
  }
}

//---- Public methods
void DanhSachMonHoc::insert(MonHoc x) {
  root = insert_node(root, x);
}

void DanhSachMonHoc::remove(MonHoc x) {
  root = remove_node(root, x);    
}

void DanhSachMonHoc::update(MonHoc x, MonHoc new_x) {
  root = update_node(root, x, new_x);
}

bool DanhSachMonHoc::is_exist(MonHoc x) {
  return check_exist(root, x);
}

MonHoc * DanhSachMonHoc::search_name(char * s) {
  return search_name_node(root, s);
}

MonHoc * DanhSachMonHoc::search_code(char * s) {
  return search_code_node(root, s);
}

LinkedList<MonHoc> DanhSachMonHoc::enumerate() {
  LinkedList<MonHoc> list_name;
  in_order(root, list_name);

  return list_name;
}

void DanhSachMonHoc::save() {
  std::ofstream f;
  f.open(db, std::ios::binary);
  save_node(root, f);
  f.close();
}

void DanhSachMonHoc::load() {
  std::ifstream f;
  f.open(db, std::ios::binary);

  MonHoc temp;
  while(f.read((char *)&temp, sizeof(temp))) {
    insert(temp);
  }  
}
