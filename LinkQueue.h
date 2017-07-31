#ifndef __LINKQUEUE_H
#define __LINKQUEUE_H
#include <stdbool.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
} LNode;
typedef struct LinkQueue{
    LNode *front;
    LNode *rear;
} LinkQueue;

// 初始化
extern LinkQueue *init_queue(void);

// 判空
extern bool isEmpty_queue(LinkQueue *q);

// 入队
extern void in_queue(LinkQueue *q, ElemType val);

// 出队
extern bool out_queue(LinkQueue *q, ElemType *val);

#endif
