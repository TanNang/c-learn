#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>

LinkList createLinkList(void){
    LinkList L = NULL;
    LNode *LHead = (LNode *)malloc(sizeof(LNode));
    LHead->data = 0;
    LHead->next = NULL;
    L = LHead;
    LNode *LTail = LHead;
    int len;
    printf("请输入链表长度: ");
    scanf("%d", &len);
    printf("请输入相应的元素: ");
    for(int i=0; i<len; i++){
        int val;
        scanf("%d", &val);
        LNode *LNew = (LNode *)malloc(sizeof(LNode));
        LNew->data = val;
        LNew->next = NULL;
        LTail->next = LNew;
        LTail = LNew;
    }
    return L;
}

LinkList createLinkList2(void){
    LNode *LHead = (LNode *)malloc(sizeof(LNode));
    LHead->data = 0;
    LHead->next = NULL;
    LinkList L = LHead;
    int len;
    printf("请输入链表长度: ");
    scanf("%d", &len);
    printf("请输入相应的元素: ");
    for(int i=0; i<len; i++){
        int val;
        scanf("%d", &val);
        LNode *LNew = (LNode *)malloc(sizeof(LNode));
        LNew->data = val;
        LNew->next = L->next;
        L->next = LNew;
    }
    return L;
}

int lengthLinkList(LinkList L){
    int len = 0;
    LNode *p = L->next;
    for(; p!=NULL; len++, p=p->next);
    return len;
}

void clearLinkList(LinkList L){
    if(L == NULL || L->next == NULL){
        return;
    }else{
        LNode *p = L;
        while(p->next != NULL){
            LNode *tmp = p->next->next;
            free(p->next);
            p->next = tmp;
        }
        return;
    }
}

void destroyLinkList(LinkList *pL){
    if(*pL == NULL){
        return;
    }else{
        LNode *p = *pL;
        while(p->next != NULL){
            LNode *tmp = p->next->next;
            free(p->next);
            p->next = tmp;
        }
        free(*pL);
        *pL = NULL;
        return;
    }
}

void printLinkList(LinkList L){
    if(L->next == NULL){
        printf("The LinkList is empty!\n");
        return;
    }else{
        printf("length:%d { ", lengthLinkList(L));
        for(LNode *p=L->next; p!=NULL; p=p->next){
            printf("%d, ", p->data);
        }
        printf("\b\b }\n");
        return;
    }
}

bool isEmptyLinkList(LinkList L){
    if(L->next == NULL || L == NULL){
        return true;
    }else{
        return false;
    }
}

bool insertLinkList(LinkList L, int index, int val){
    int len = lengthLinkList(L);
    if(L == NULL || index < 0 || index > len){
        return false;
    }else{
        LNode *LNew = (LNode *)malloc(sizeof(LNode));
        LNew->data = val;
        LNode *p = L;
        for(int i=0; i<index; i++, p=p->next);
        LNode *tmp = p->next;
        p->next = LNew;
        LNew->next = tmp;
        return true;
    }
}

bool deleteLinkList(LinkList L, int index){
    int len = lengthLinkList(L);
    if(L == NULL || index < 0 || index >= len){
        return false;
    }else{
        LNode *p = L;
        for(int i=0; i<index; i++, p=p->next);
        LNode *tmp = p->next->next;
        free(p->next);
        p->next = tmp;
        return true;
    }
}

bool deleteValLinkList(LinkList L, int val){
    if(L->next == NULL){
        return false;
    }else{
        LNode *p = L;
        for(; p->next->data!=val && p->next->next!=NULL; p=p->next);
        if(p->next->data != val){
            return false;
        }else{
            LNode *tmp = p->next->next;
            free(p->next);
            p->next = tmp;
            return true;
        }
    }
}

int getLinkList(LinkList L, int index){
    int len = lengthLinkList(L);
    if(index < 0 || index >= len){
        exit(1);
    }else{
        LNode *p = L->next;
        for(int i=0; i<index; i++, p=p->next);
        return p->data;
    }
}

int locateLinkList(LinkList L, int val){
    LNode *p = L->next;
    for(int i=0; p!=NULL; i++, p=p->next){
        if(p->data == val){
            return i;
        }
    }
    return -1;
}

bool modifyLinkList(LinkList L, int index, int val){
    int len = lengthLinkList(L);
    if(index < 0 || index >= len){
        return false;
    }else{
        LNode *p = L->next;
        for(int i=0; i<index; i++, p=p->next);
        p->data = val;
        return true;
    }
}

int appendLinkList(LinkList L, int val){
    if(L == NULL){
        exit(1);
    }
    LNode *p = L->next;
    for(; p->next!=NULL; p=p->next);
    LNode *LNew = (LNode *)malloc(sizeof(LNode));
    LNew->data = val;
    LNew->next = NULL;
    p->next = LNew;
    return val;
}

int popLinkList(LinkList L){
    if(L == NULL || L->next == NULL){
        exit(EXIT_FAILURE);
    }
    LNode *p = L->next;
    for(; p->next->next!=NULL; p=p->next);
    int val = p->next->data;
    free(p->next);
    p->next=NULL;
    return val;
}

void sortLinkList(LinkList L, int rev){
    if(L == NULL || L->next == NULL){
        return;
    }else{
        int len = lengthLinkList(L);
        for(int i=0; i<len-1; i++){
            bool sorted = true;
            LNode *p = L->next;
            for(int j=0; j<len-1-i; j++, p=p->next){
                if(!rev){
                    if(p->data > p->next->data){
                        sorted = false;
                        int tmp = p->data;
                        p->data = p->next->data;
                        p->next->data = tmp;
                    }
                }else{
                    if(p->data < p->next->data){
                        sorted = false;
                        int tmp = p->data;
                        p->data = p->next->data;
                        p->next->data = tmp;
                    }
                }
            }
            if(sorted){
                break;
            }
        }
        return;
    }
}

void reverseLinkList(LinkList L){
    LNode *p = L->next;
    L->next = NULL;
    while(p != NULL){
        LNode *tmp = p->next;
        p->next = L->next;
        L->next = p;
        p = tmp;
    }
}
