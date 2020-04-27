class Register{
    private:
        char* MASV_;
        short DIEM_;
    public:
        Register(){;};
        Register(char* MASV, short DIEM);
        ~Register(){;};

        char* get_MASV();
        short get_DIEM();
};