#include "SeqStack.h"
#include <stdlib.h>

SeqStack *init_stack(void){
    SeqStack *s = (SeqStack *)malloc(sizeof(SeqStack));
    s->top = -1;
    return s;
}

bool empty_stack(SeqStack *s){
    if(s == NULL || s->top == -1){
        return true;
    }else{
        return false;
    }
}

bool push_stack(SeqStack *s, ElemType val){
    if(s == NULL || s->top == MAXSIZE-1){
        return false;
    }else{
        s->top++;
        s->data[s->top] = val;
        return true;
    }
}

bool pop_stack(SeqStack *s, ElemType *val){
    if(s == NULL || s->top == -1){
        return false;
    }else{
        *val = s->data[s->top];
        s->top--;
        return true;
    }
}

ElemType top_stack(SeqStack *s){
    if(s == NULL || s->top == -1){
        return 0;
    }else{
        return s->data[s->top];
    }
}
