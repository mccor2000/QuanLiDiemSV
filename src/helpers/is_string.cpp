#include "helpers.h"


bool is_string(char* str){
    for(int i=0;i<strlen(str);i++){
        if((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i] <=122) || (str[i]>=48 && str[i]<=57) || str[i]==' ' || str[i] == '-') {
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}