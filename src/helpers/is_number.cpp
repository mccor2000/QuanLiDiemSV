#include "helpers.h"


bool is_number(char* str){
    for(int i=0;i<strlen(str);i++){
        if(str[i]>=48 && str[i]<=57)
            continue;
        else 
            return false;
    }
    return true;
}