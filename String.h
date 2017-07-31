#ifndef __STRING_H
#define __STRING_H

#define MAXSIZE 256
typedef char String[MAXSIZE];

/**
 * 求字符串长度(不包括'\0'字符)
 * @param str   字符串str
 * @return int  返回长度len
**/
extern int StrLen(const char *str);

/**
 * 字符串赋值，将str2的串值赋值给str1，str1原来的串值被覆盖
 * @param str1      字符串str1
 * @param str2      字符串str2
 * @return char *   返回str1的指针
**/
extern char *StrCpy(char *str1, const char *str2);

/**
 * 字符串拼接，将s1、s2的串值拼接在一起，并保存到s
 * @param s1        字符串s1
 * @param s2        字符串s2
 * @param s         字符串s
 * @return char *   返回s的指针
**/
extern char *StrCat1(const char *s1, const char *s2, char *s);

/**
 * 字符串拼接，将s2的串值拼接在s1之后
 * @param s1        字符串s1
 * @param s2        字符串s2
 * @return char *   返回s1的指针
**/
extern char *StrCat2(char *s1, const char *s2);

/**
 * 提取子串，从str的第i个字符开始，提取len长度，保存到substr
 * @param substr    字符串substr
 * @param str       字符串str
 * @param i         索引值i
 * @param len       提取长度len
 * @return char *   返回substr的指针
**/
extern char *StrSub(char *substr, const char *str, int i, int len);

/**
 * 比较两个字符串，若s1<s2则返回负值，若s1=s2则返回0，若s1>s2则返回正值
 * @param s1    字符串s1
 * @param s2    字符串s2
 * @return int  0: s1=s2; 正整数: s1>s2; 负整数: s1<s2;
**/
extern int StrCmp(const char *s1, const char *s2);

/**
 * 字符串插入，将字符串ins插入到字符串str的第i个位置
 * @param str       字符串str
 * @param i         索引值i
 * @param ins       字符串ins
 * @return char *   返回str的指针
**/
extern char *StrIns(char *str, int i, const char *ins);

/**
 * 字符串删除，从str第i个字符起，删除len个长度的字符
 * @param str       字符串str
 * @param i         索引值i
 * @param len       长度len
 * @return char *   返回str的指针
**/
extern char *StrDel(char *str, int i, int len);

/**
 * 查找子串，BF算法，在字符串str中查找pattern匹配的子串，并返回其位置
 * @param str       字符串str
 * @param pattern   字符串pattern(也称为模式)
 * @return int      若查找成功，返回第一个字符的位置，否则返回-1
**/
extern int StrIndexBF(const char *str, const char *pattern);

#endif
