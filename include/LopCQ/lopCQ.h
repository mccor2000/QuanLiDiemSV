#ifndef _LOPCQ_H
#define _LOPCQ_H
#include "../templates/LinkedList.h"
#include "../SinhVien/SinhVien.h"

class lopCQ{
        private:
            char* TenLop_;
            LinkedList<Student> DSSV_;
        public:
            lopCQ(){;};
            lopCQ(char* TenLop, LinkedList<Student> dssv);
            
            char* get_TenLop();
            LinkedList<Student> get_DSSV();
};

#endif