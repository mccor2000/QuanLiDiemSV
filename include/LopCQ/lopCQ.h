#ifndef _LOPCQ_H
#define _LOPCQ_H
#include "../templates/LinkedList.h"
#include "../SinhVien/SinhVien.h"

class lopCQ{
        private:
            char* MALOP_;
            LinkedList<Student> DSSV_;
        public:
            lopCQ(){;};
            lopCQ(char* MALOP_, LinkedList<Student> dssv);
            char* get_MALOP();
            LinkedList<Student> get_DSSV();
};

#endif