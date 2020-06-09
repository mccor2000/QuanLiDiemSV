#include "./helpers.h"

char * StringToChar(std::string st) {
  static char tmp[16];
  strcpy(tmp,st.c_str());
  return tmp;
}