#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
template <typename T>
class Node{
private:
    T data_;
    Node<T>* next_;

public:
    Node() : next_(NULL){;}
    void set_data(T val){data_= val;};
    T get_data() {return data_;}
    void set_next(Node<T>* next){next_=next;};
    Node<T>* get_next() {return next_;};

};
template <typename T>
class LinkedList{
    public:
        Node<T>* p_head_;
        Node<T>* p_tail_;

        
        LinkedList() {
            p_head_ = NULL ;
            p_tail_ = NULL ;
        }
        ~LinkedList() {;};
        Node<T>* head() {return p_head_;}
        Node<T>* tail() {return p_tail_;}
        void push_back(T val){
            Node<T>* tmp = new Node<T>();
            tmp->set_data(val);
            tmp->set_next(NULL);
            if(p_head_ == NULL){
                p_head_ = tmp;
                p_tail_ = tmp;
            }
            else{
                p_tail_ -> set_next(tmp);
                p_tail_ = p_tail_ -> get_next();
            }
        }
        void push_front(T val){
            Node<T>* temp = new Node<T>();
            temp -> set_data(val);
            temp->set_next(p_head_);
            p_head_ = temp;
        }
        void insert(T val, int pos){
            if(pos == 0 || p_head_ == NULL){
                push_front(val);
            }
            else{
                int k=1;
                Node<T>* p = p_head_;
                while(p!=NULL && k!=pos){
                    p = p->get_next();
                    ++k;
                }
                if(k!=pos){push_back(val);}
                else{
                    Node<T>* temp = new Node<T>();
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
                }
                else{
                    p_head_ = p_head_ -> get_next();
                }
            }
            else{
                int k=1;
                Node<T>* p = p_head_;
                while(p->get_next()->get_next()!= NULL && k != pos){
                    p=p->get_next();
                    ++k;
                }
                if(k!=pos){
                    std::cout <<"Vi tri nhap vao vuot qua vi tri cuoi cung cua danh sach\n";
                }
                else{
                    p->set_next(p->get_next()->get_next());
                }
            }

        }
  
        void save_to_file(char * file_path) {
            std::ofstream f;
            f.open(file_path, std::ios::binary);
            
            Node<T>* temp = p_head_;

            do {
                f.write((char *)&temp->get_data(), sizeof(T));
                temp = temp->get_next();
            } while (temp->get_next() != NULL);

            f.close(); 
        }
        
        void get_from_file(char * file_path) {
            std::ifstream f;
            f.open(file_path, std::ios::binary);

            T temp;


            while (f.read((char *)&temp, sizeof(T))) {
                push_back(temp);
            }

            f.close();
        }

        int count(){
            int result=0;
            if(p_head_==NULL){
                return result;
            }
            else{
                Node<T>* p = p_head_;
                while(p->get_next()!=NULL){
                    result++;
                }
                return result;
            }
        }
       void swap(Node<T>* a, Node<T>* b){
           Node<Student>* tmp = new Node<T>();
           tmp->set_data(a->get_data());
            a->set_data(b->get_data());
            b->set_data(tmp->get_data());
       }
        void sort(){
            Node<T>* head = p_head_;
            Node<T>* node = NULL;
            for(Node<T>* index = head; index->get_next() != NULL ; index=index->get_next()){
                for(Node<T>* selection = index->get_next(); selection != NULL; selection = selection->get_next()){
                    if(index->get_data() > selection->get_data()){
                        swap(index, selection);
                    }
                }
            }
        }

};
#endif
