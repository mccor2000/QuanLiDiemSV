#include "validator.h"


bool is_empty_data(char** data, int size) {
    for (int i=0; i<size; i++) {
        if (strcmp(data[i],"")==0) {
            return true;
        }
    }
    return false;
}

bool validate_ltc(char** data){
    if (is_empty_data(data,6)) return false;
    return is_string(data[0]) && is_string(data[1]) && is_number(data[2]) && is_number(data[3]) && is_number(data[4]) && is_number(data[5]);
}

bool validate_lcq(char** data){
    if (is_empty_data(data,1)) return false;
    return is_string(data[0]);
}
bool validate_mh (char ** data) {
    if (is_empty_data(data,4)) return false;
    return is_string(data[0]) && is_string(data[1]) && is_number(data[2]) && is_number(data[3]);
}

bool validate_sv(char** data){
    if (is_empty_data(data,5)) return false;
    return is_string(data[0]) && is_string(data[1]) && is_string(data[2]) && is_string(data[3]) && is_number(data[4]);
}

bool validate_nhap_diem_1(char** data){
    if (is_empty_data(data,4)) return false;
    return is_string(data[0]) && is_number(data[1]) && is_number(data[2]) && is_string(data[3]);
}

bool validate_nhap_diem_2(char** data){
    if (is_empty_data(data,1)) return false;
    return is_float(data[0]);
}

bool validate_dang_ki_1(char** data){
    if (is_empty_data(data,1)) return false;
    return is_string(data[0]);
}

bool validate_dang_ki_2(char** data){
    if (is_empty_data(data,2)) return false;
    return is_string(data[0]) && is_number(data[1]);
}
