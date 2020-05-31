#include "./helpers.h"

bool valid_Name(char *const s){
        for(int i=0;i<strlen(s);i++){
                if(s[i]>=33 && s[i]<=64){
                        return 0;
                }
                if(s[i]>=91 && s[i]<=96){
                        return 0;
                }
                if(s[i]>122){
                        return 0;
                }
        }
        return 1;
}