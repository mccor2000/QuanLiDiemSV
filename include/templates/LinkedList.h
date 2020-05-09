#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

template <typename T>
class LinkedList{
public:
    class Node{
    private:
        T data_;
        Node * next_;

    public:
        Node() : next_(NULL){;}
        void set_data(T val){data_= val;};
        T get_data() {return data_;}
        void set_next(Node * next){next_=next;};
        Node * get_next() {return next_;};

    };

    Node * p_head_;
    Node * p_tail_;

        
    LinkedList() {
        p_head_ = NULL ;
        p_tail_ = NULL ;
    }
    ~LinkedList() {;};
        
    Node * head() {return p_head_;}
    Node * tail() {return p_tail_;}
        
    void push_back(T val){
        Node * tmp = new Node();
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
        Node * temp = new Node();
        temp -> set_data(val);
        temp->set_next(p_head_);
        p_head_ = temp;
    }
    void insert(T val, int pos){
      if(pos == 0 || p_head_ == NULL){
          push_front(val);
      } else {
          int k=1;
          Node * p = p_head_;
          while(p!=NULL && k!=pos){
              p = p->get_next();
              ++k;
          }
  
          if(k!=pos){push_back(val);}
          else{
            Node * temp = new Node();
            temp->set_data(val);
            temp->set_next(p->get_next());
            p->set_next(temp);
          }

      }
    }
     
    void remove(int pos){
        if(pos==0){
          if(p_head_ == NULL){
              std::cout << "Danh sach dang trong\n";
          } else {
              p_head_ = p_head_ -> get_next();
          }
        } else {
            int k=1;
            Node * p = p_head_;
            while(p->get_next()->get_next()!= NULL && k != pos){
                p=p->get_next();
                ++k;
            }
                
            if(k!=pos){
                std::cout <<"Vi tri nhap vao vuot qua vi tri cuoi cung cua danh sach\n";
            } else {
                p->set_next(p->get_next()->get_next());
            }
        }

    }

    int count(){
        int result=0;
        
        if(p_head_==NULL){
            return result;
        } else {
            Node * p = p_head_;
            while(p->get_next()!=NULL){
                result++;
            }
            return result;
        }
    }
        
    void swap(Node * a, Node * b){
        Node * tmp = new Node();
        tmp->set_data(a->get_data());
        a->set_data(b->get_data());
        b->set_data(tmp->get_data());
    }
        void sort(){
            Node * head = p_head_;
            Node * node = NULL;
            for(Node * index = head; index->get_next() != NULL ; index=index->get_next()){
                for(Node * selection = index->get_next(); selection != NULL; selection = selection->get_next()){
                    if(index->get_data() > selection->get_data()){
                        swap(index, selection);
                    }
                }
            }
        }

};
#endif
