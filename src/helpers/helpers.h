#ifndef _HELPERS_H
#define _HELPERS_H
#include<cstring>
#include <iostream>
#include <math.h>
#include <string>
#include<stdio.h>
#include <stdlib.h>

char *ltrim(char *const s);
char *rtrim(char *const s);
char *trim(char *const s);
void xoa(char s[90],int vitrixoa);
char* xoakt(char *const s);
char* up_low(char *const s);

char* Trim(char *const s);
float Round(float score);
char * trim_whitespaces(char * str);
bool is_valid_string(char *const s);
bool is_valid_number(float score);

char * upper_case_letters(char * const str);

short string_to_short(char * str);
int string_to_int(char * str);

char* int_to_string(int x);
char* float_to_string(float fnum);


double string_to_float(char* str);

#endif
