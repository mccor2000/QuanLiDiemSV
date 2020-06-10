#include "helpers.h"


bool is_float(char* str){
    for(int i=0;i<strlen(str);i++){
        if((str[i]>=48 && str[i]<=57) || str[i]=='.')
            continue;
        else 
            return false;
    }
    return true;
}