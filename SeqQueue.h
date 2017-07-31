#ifndef __SEQQUEUE_H
#define __SEQQUEUE_H
#include <stdbool.h>

#define MAXSIZE 1024
typedef int ElemType;
typedef struct{
    ElemType data[MAXSIZE];
    int front;
    int rear;
    int size;
} SeqQueue;

// 初始化
extern SeqQueue *init_queue(void);

// 入队
extern bool in_queue(SeqQueue *q, ElemType val);

// 出队
extern bool out_queue(SeqQueue *q, ElemType *val);

// 判空
extern bool isEmpty_queue(SeqQueue *q);

#endif
