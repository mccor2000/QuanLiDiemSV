#ifndef _HELPER_H
#define _HELPER_H
#include<cstring>
#include <iostream>

using namespace std;
char *ltrim(char *const s){
        size_t len;
        char *cur;
        if(s && *s) {
                len = strlen(s);
                cur = s;
                while(*cur && isspace(*cur))
                        ++cur, --len;
                if(s != cur)
                        memmove(s, cur, len + 1);
        }
        return s;
}
char *rtrim(char *const s){
        size_t len;
        char *cur;
        if(s && *s) {
                len = strlen(s);
                cur = s + len - 1;
                while(cur != s && isspace(*cur))
                        --cur, --len;
                cur[isspace(*cur) ? 0 : 1] = '\0';
        }
        return s;
}
char *trim(char *const s){
        rtrim(s);  
        ltrim(s);
        return s;
}
void xoa(char s[90],int vitrixoa){
	int n=strlen(s);
    for(int i=vitrixoa;i<n;i++)
     s[i]=s[i+1];
	s[n-1]='\0';
}
char* xoakt(char *const s)
{
    for(int i=0;i<strlen(s);i++)
		if(s[i]==' '&& s[i+1]==' ')
		{
			xoa(s,i);
			i--;
		}
    return s;
}
char* up_low(char *const s){
    if(s[0]>=97 && s[0]<=122)
       s[0] -= ' ';
    
    for(int i=1;i<strlen(s);i++){
        if(s[i]==32){
            if(s[i+1]>=97 && s[i+1]<=122){
                s[i+1]-=' ';
                i++;
                continue;
        }
        }
        if (s[i-1] != 32 && s[i]>=65 && s[i]<=90){
            s[i]+=' ';
            continue;
        }
    }
    return s;
}
// DONE Trim
char* Trim(char *const s){
    return up_low(xoakt(trim(s)));
}

#endif