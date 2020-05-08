#include "library.h"
using namespace std;


void Show_Student(LinkedList<Student> dssv){
    dssv.sort();
    Node<Student>* node = dssv.head();
    while(node->get_next()!=NULL){
        node->get_data().info();
        cout << '\n';
        node=node->get_next();
    }
}
int main(){
    cout << "Module D\n";
}