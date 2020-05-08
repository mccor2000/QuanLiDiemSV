#ifndef _SINHVIEN_H
#define _SINHVIEN_H

class Student{
    private:
        char* MASV_;
        char* HO_;
        char* TEN_;
        bool PHAI_;
        char* SDT_;
        char* MALOP_;
    public:
        Student(){;};
        Student(char* MASV,char* HO,char* TEN,bool PHAI, char* SDT,char* MALOP);
        ~Student(){;};

        char* get_MASV();
        char* get_HO();
        char* get_TEN();
        char* get_SDT();
        char* get_MALOP();
        bool get_PHAI();
        void info();
        bool operator>(Student);
};

#endif