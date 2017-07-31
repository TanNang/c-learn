#include "LinkStack.h"
#include <stdlib.h>

LinkStack init_stack(void){
    return NULL;
}

bool empty_stack(LinkStack top){
    if(top == NULL){
        return true;
    }else{
        return false;
    }
}

bool push_stack(LinkStack *top, ElemType val){
    if(top == NULL){
        return false;
    }else{
        SNode *node = (SNode *)malloc(sizeof(SNode));
        node->data = val;
        node->next = *top;
        *top = node;
        return true;
    }
}

bool pop_stack(LinkStack *top, ElemType *val){
    if(top == NULL || *top == NULL){
        return false;
    }else{
        *val = (*top)->data;
        LinkStack newtop = (*top)->next;
        free(*top);
        *top = newtop;
        return true;
    }
}

ElemType top_stack(LinkStack top){
    if(top == NULL){
        return 0;
    }else{
        return top->data;
    }
}
