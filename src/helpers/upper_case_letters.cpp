#include "./helpers.h"

char * upper_case_letters (char * const str) {
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] >= 97 && str[i] <= 122) {
      str[i] -= 32;
    }
  }
  return str;
}
