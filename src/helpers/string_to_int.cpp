#include "./helpers.h"

int string_to_int(char * str) {
    int n = 0;
    for (int i = 0; i < sizeof(str); i++) {
        n = n*10 + (int(str[i]) - 48);
    }
    return n;
}
