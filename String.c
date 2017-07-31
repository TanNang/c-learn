#include "String.h"
#include <stdio.h>

int StrLen(const char *str){
    int len = 0;
    while(str[len] != '\0'){
        len++;
    }
    return len;
}

char *StrCpy(char *str1, const char *str2){
    int i = 0;
    for(; str2[i]!='\0'; i++){
        str1[i] = str2[i];
    }
    str1[i] = '\0';
    return str1;
}

char *StrCat1(const char *s1, const char *s2, char *s){
    if(StrLen(s1) + StrLen(s2) + 1 > MAXSIZE){
        return NULL;
    }else{
        int i = 0, j = 0;
        while(s1[i] != '\0'){
            s[j++] = s1[i++];
        }
        i = 0;
        while(s2[i] != '\0'){
            s[j++] = s2[i++];
        }
        s[j] = '\0';
        return s;
    }
}

char *StrCat2(char *s1, const char *s2){
    int len1 = StrLen(s1);
    int len2 = StrLen(s2);
    if(len1 + len2 + 1 > MAXSIZE){
        return NULL;
    }else{
        int i = 0;
        for(; i<len2; i++){
            s1[len1+i] = s2[i];
        }
        s1[len1+i] = '\0';
        return s1;
    }
}

char *StrSub(char *substr, const char *str, int i, int len){
    int strlen = StrLen(str);
    if(i < 0 || i >= strlen || len < 0 || i + len > strlen){
        return NULL;
    }else{
        int j = 0;
        for(; j<len; j++){
            substr[j] = str[i+j];
        }
        substr[j] = '\0';
        return substr;
    }
}

int StrCmp(const char *s1, const char *s2){
    int i = 0;
    while(s1[i] == s2[i] && s1[i] != '\0'){
        i++;
    }
    return s1[i] - s2[i];
}

char *StrIns(char *str, int i, const char *ins){
    int len1 = StrLen(str);
    int len2 = StrLen(ins);
    if(len1 + len2 + 1 > MAXSIZE){
        return NULL;
    }else if(i == len1){
        int j = 0;
        for(; j<len2; j++){
            str[len1+j] = ins[j];
        }
        str[len1+j] = '\0';
        return str;
    }else{
        for(int j=len1; j>=i; j--){
            str[j+len2] = str[j];
        }
        for(int j=0; j<len2; j++){
            str[i+j] = ins[j];
        }
        return str;
    }
}

char *StrDel(char *str, int i, int len){
    int j;
    for(j=i+len; str[j]!='\0'; j++){
        str[j-len] = str[j];
    }
    str[j-len] = '\0';
    return str;
}

int StrIndexBF(const char *str, const char *pattern){
    int len1 = StrLen(str);
    int len2 = StrLen(pattern);
    int i = 0, j = 0;
    while(i < len1 && j < len2){
        if(str[i] == pattern[j]){
            i++;
            j++;
        }else{
            i = i - j + 1;
            j = 0;
        }
    }
    if(j == len2){
        return i - len2;
    }else{
        return -1;
    }
}
