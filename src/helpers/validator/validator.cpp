#include "validator.h"


bool validate_ltc(char** data){
    return is_string(data[0]) && is_string(data[1]) && is_number(data[2]) && is_number(data[3]) && is_number(data[4]) && is_number(data[5]);
}

bool validata_lcq(char** data){
    return is_string(data[0]);
}
bool validate_mh(char** data){
    return is_string(data[0]) && is_string(data[1]) && is_number(data[2]) && is_number(data[3]);
}

bool validate_sv(char** data){
    return is_string(data[0]) && is_string(data[1]) && is_string(data[2]) && is_string(data[3]) && is_number(data[4]);
}
bool validate_nhap_diem_1(char** data){
    return is_string(data[0]) && is_number(data[1]) && is_number(data[2]) && is_number(data[3]);
}
bool validate_nhap_diem_2(char** data){
    return is_string(data[0]) && is_float(data[1]);
}
bool validate_dang_ki_1(char** data){
    return is_string(data[0]);
}
bool validate_dang_ki_2(char** data){
    return is_string(data[0]) && is_number(data[1]);
}