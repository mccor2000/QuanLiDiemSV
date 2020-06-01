#include "./helpers.h"

short string_to_short(char * str) {
    short s = 0;
    for (int i = 0; i < strlen(str); i++) {
        s = s*10 + (int(str[i]) - 48);
    }
    return s;
}
