#include "helpers.h"


bool is_string(char* str){
    for(int i=0;i<strlen(str);i++){
        if(str[i]>=65 && str[i]<=90)
            continue;
        else if(str[i]>=97 && str[i] <=122)
            continue;
        else if (str[i] == ' ')
            continue;
        else{
            return false;
        }
    }
    return true;
}