#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <iostream>

template <typename T>
class Node {
private:
    Node<T>* next_;
    T data_;

public:
    Node<T>() : next_(NULL){;}
    void set_data(T val){data_= val;};
    T get_data() {return data_;}
    void set_next(Node<T> * next){next_=next;};
    Node<T> * get_next() {return next_;};

};

template <typename T>
class LinkedList{
public:
    Node<T> * p_head_;
    Node<T> * p_tail_;

        
    LinkedList() {
        p_head_ = NULL ;
        p_tail_ = NULL ;
    }
    ~LinkedList() {;};
        
    Node<T> * head() {return p_head_;}
    Node<T> * tail() {return p_tail_;}
        
    void push_back(T val){
        Node<T> * tmp = new Node<T>();
        tmp->set_data(val);
        tmp->set_next(NULL);
    
        if (p_head_ == NULL) {
            p_head_ = tmp;
            p_tail_ = tmp;
        } else {
            p_tail_ -> set_next(tmp);
            p_tail_ = p_tail_ -> get_next();
        }
    }

    void push_front(T val){
        Node<T> * temp = new Node<T>();
        temp -> set_data(val);
        temp->set_next(p_head_);
        p_head_ = temp;
    }
    void insert(T val, int pos){
      if(pos == 0 || p_head_ == NULL){
          push_front(val);
      } else {
          int k=1;
          Node<T> * p = p_head_;
          while(p!=NULL && k!=pos){
              p = p->get_next();
              ++k;
          }
  
          if(k!=pos){push_back(val);}
          else{
            Node<T> * temp = new Node<T>();
            temp->set_data(val);
            temp->set_next(p->get_next());
            p->set_next(temp);
          }

      }
    }
    void remove_head(){
        Node<T>* tmp = new Node<T>();
        tmp = p_head_;
        p_head_ = p_head_ -> get_next();
        delete tmp;
    }
    void remove_tail(){
        Node<T>* node = new Node<T>();
        node = p_head_;
        while(node->get_next()->get_next()!=NULL){
            node = node->get_next();
        }
        Node<T>* tmp = new Node<T>();
        tmp=node;
        node->set_next(NULL);
        delete tmp;
    }
    void remove(int pos){
        if(pos >= count()){
            std::cout << "\nVuot qua danh sach\n";
            return;
        }
        if(p_head_ == NULL){
              std::cout << "\nDanh sach dang trong\n";
              return;
          }
        if(pos==0){
            remove_head();
            return;
        }

        if(pos==count()-1){
            remove_tail();
            return;
        }
        int pos_tmp=0;
        Node<T>* node = new Node<T>();
        Node<T>* tmp = new Node<T>();
        node = head();
        while(pos_tmp!=pos){
            if(pos_tmp==pos-1)
                break;
            node = node->get_next();
            pos_tmp++;
        }
        tmp=node->get_next();
        node->set_next(node->get_next()->get_next());
        delete tmp;
        return;
    }

    int count(){
        int result = 0;
        
        Node<T> * p = p_head_;
        while(p != NULL){
          result++;
          p = p->get_next();
        }
        return result;
    }
        
    void swap(Node<T> * a, Node<T> * b){
        Node<T> * tmp = new Node<T>();
        tmp->set_data(a->get_data());
        a->set_data(b->get_data());
        b->set_data(tmp->get_data());
    }

    void sort(){
        Node<T> * head = p_head_;
        Node<T> * node = NULL;

        for(Node<T> * index = head; index->get_next() != NULL ; index=index->get_next()){
            for(Node<T> * selection = index->get_next(); selection != NULL; selection = selection->get_next()){
                if(index->get_data() > selection->get_data()){
                  swap(index, selection);
                }
            }
        }
    }
};
#endif
