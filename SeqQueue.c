#include "SeqQueue.h"
#include <stdlib.h>

SeqQueue *init_queue(void){
    SeqQueue *q = (SeqQueue *)malloc(sizeof(SeqQueue));
    q->front = q->rear = -1;
    q->size = 0;
    return q;
}

bool in_queue(SeqQueue *q, ElemType val){
    if(q == NULL || q->size == MAXSIZE){
        return false;
    }else{
        q->rear = (q->rear+1) % MAXSIZE;
        q->data[q->rear] = val;
        q->size++;
        return true;
    }
}

bool out_queue(SeqQueue *q, ElemType *val){
    if(q == NULL || q->size == 0){
        return false;
    }else{
        q->front = (q->front+1) % MAXSIZE;
        *val = q->data[q->front];
        q->size--;
        return true;
    }
}

bool isEmpty_queue(SeqQueue *q){
    if(q == NULL || q->size == 0){
        return true;
    }else{
        return false;
    }
}
