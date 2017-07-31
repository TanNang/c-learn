#ifndef __SEQSTACK_H
#define __SEQSTACK_H
#include <stdbool.h>

#define MAXSIZE 1024
typedef int ElemType;
typedef struct{
    ElemType data[MAXSIZE];
    int top;
} SeqStack;

/**
 * 初始化
 * @param void          不接受参数
 * @return SeqStack *   返回指向SeqStack的指针
**/
extern SeqStack *init_stack(void);

/**
 * 判断s是否为空
 * @param s     要操作的顺序栈s
 * @return bool true: 空; false: 非空
**/
extern bool empty_stack(SeqStack *s);

/**
 * 入栈
 * @param s     要操作的顺序栈s
 * @param val   入栈的元素val
 * @return bool true: 入栈成功; false: 传参有误或空间不足
**/
extern bool push_stack(SeqStack *s, ElemType val);

/**
 * 出栈
 * @param s     要操作的顺序栈s
 * @param val   保存弹出元素的指针
 * @return bool true: 出栈成功; false: 传参有误或s为空栈
**/
extern bool pop_stack(SeqStack *s, ElemType *val);

/**
 * 读取栈顶元素
 * @param s         要操作的顺序栈s
 * @return ElemType 返回栈顶元素的值，若s为空栈则返回0
**/
extern ElemType top_stack(SeqStack *s);

#endif
