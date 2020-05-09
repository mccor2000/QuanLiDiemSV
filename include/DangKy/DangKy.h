#ifndef _DANGKY_H
#define _DANGKY_H

class Register{
    private:
        char* MASV_;
        float DIEM_;
    public:
        Register(){;};
        Register(char* MASV, float DIEM);
        ~Register(){;};

        char* get_MASV();
        float get_DIEM();
        void info();
};

#endif