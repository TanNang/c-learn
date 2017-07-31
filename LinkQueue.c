#include "LinkQueue.h"
#include <stdlib.h>

LinkQueue *init_queue(void){
    LinkQueue *q = (LinkQueue *)malloc(sizeof(LinkQueue));
    q->front = q->rear = (LNode *)malloc(sizeof(LNode));
    q->front->next = NULL;
    return q;
}

bool isEmpty_queue(LinkQueue *q){
    if(q == NULL || q->front == q->rear){
        return true;
    }else{
        return false;
    }
}

void in_queue(LinkQueue *q, ElemType val){
    LNode *LNew = (LNode *)malloc(sizeof(LNode));
    LNew->data = val;
    LNew->next = NULL;
    q->rear->next = LNew;
    q->rear = LNew;
}

bool out_queue(LinkQueue *q, ElemType *val){
    if(q == NULL || q->front == q->rear){
        return false;
    }else{
        LNode *tmp = q->front->next->next;
        *val = q->front->next->data;
        free(q->front->next);
        q->front->next = tmp;
        if(q->front->next == NULL){
            q->rear = q->front;
        }
        return true;
    }
}
