#include "./helpers.h"

char* converting(int x){
    char* result = "";
    while(x){
        result+= char((x%10)+48);
        x/=10;
    }
    return result;
}
