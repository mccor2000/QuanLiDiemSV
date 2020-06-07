#include "helpers.h"


char* float_to_string(float fnum){
    char buffer[10];
    gcvt(fnum,4,buffer);
    return buffer;
}