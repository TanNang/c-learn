#ifndef __LINKSTACK_H
#define __LINKSTACK_H
#include <stdbool.h>

typedef int ElemType;
typedef struct SNode{
    ElemType data;
    struct SNode *next;
} SNode, *LinkStack;

/**
 * 初始化
 * @param void          不接受参数
 * @return LinkStack    返回栈顶指针top
**/
extern LinkStack init_stack(void);

/**
 * 判断链栈top是否为空
 * @param top   要操作的链栈top
 * @return bool true: 空; false: 非空
**/
extern bool empty_stack(LinkStack top);

/**
 * 入栈
 * @param top   要操作的链栈指针top(二级指针)
 * @param val   入栈的元素
 * @return bool true: 操作成功; false: 操作失败
**/
extern bool push_stack(LinkStack *top, ElemType val);

/**
 * 出栈
 * @param top   要操作的链栈指针top(二级指针)
 * @param val   保存弹出元素的指针
 * @return bool true: 操作成功; false: 操作失败
**/
extern bool pop_stack(LinkStack *top, ElemType *val);

/**
 * 读取栈顶元素
 * @param top       要操作的链栈top
 * @return ElemType 返回元素的值，若栈为空则返回0
**/
extern ElemType top_stack(LinkStack top);

#endif
