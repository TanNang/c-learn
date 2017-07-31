#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>

// 初始化
SeqList *Init_SeqList(){
    SeqList *L = (SeqList *)malloc(sizeof(SeqList));
    if(L == NULL){
        return NULL;    // 申请内存失败
    }else{
        L->len = 0; // 将len长度置为0
        return L;   // 返回SeqList首地址
    }
}

// 判空
int Empty_SeqList(SeqList *L){
    if(L == NULL || L->len == 0){
        return 1;   // true, 当前SeqList为空
    }else{
        return 0;   // false, 不为空
    }
}

// 获取长度
int Length_SeqList(SeqList *L){
    if(L == NULL){
        return -1;  // 传入的参数有误
    }
    return L->len;  // 返回当前顺序表的长度
}

// 打印SeqList
void Print_SeqList(SeqList *L){
    if(L == NULL || L->len == 0){
        return; // 传入的参数有误
    }
    printf("Length:%d  { ", L->len);
    for(int i=0; i<L->len; i++){
        printf("%d, ", L->data[i]);
    }
    printf("\b\b }\n");
}

// 销毁
int Destroy_SeqList(SeqList *L){
    if(L == NULL){
        return 0;   // false, 空指针
    }else{
        free(L);
        return 1;   // true, 操作成功
    }
}

// 取表元
int GetElem_SeqList(SeqList *L, int i){
    if(L == NULL || L->len == 0 || i<0 || i>=L->len){
        return 0;   // 传入的参数有误
    }
    return L->data[i];  // 返回索引为i的元素的值
}

// 按值查找
int Locate_SeqList(SeqList *L, int x){
    if(L == NULL || L->len == 0){
        return -1;  // 传入的参数有误
    }else{
        int index = -1;
        for(int i=0; i<L->len; i++){
            if(L->data[i] == x){
                index = i;
                break;
            }
        }
        return index;   // 若查找成功, 返回第一次出现的索引值index; 否则返回-1
    }
}

// 表尾插入元素
int Append_SeqList(SeqList *L, int x){
    if(L == NULL || L->len == MAXSIZE){
        return -1;  // 传入的参数有误
    }else{
        L->data[L->len] = x;
        L->len++;
        return x;   // 操作成功，返回插入的元素的值
    }
}

// 移除表的最后一项
int Pop_SeqList(SeqList *L){
    if(L == NULL || L->len == 0){
        return -1;  // 传入的参数有误
    }else{
        int val = L->data[L->len-1];
        L->data[L->len-1] = 0;
        L->len--;
        return val; // 操作成功，返回移除的元素的值
    }
}

// 插入元素
int Insert_SeqList(SeqList *L, int index, int x){
    if(L == NULL || index >= MAXSIZE || L->len == MAXSIZE){
        return -1;  // 传入的参数有误
    }else if(L->len == 0 || index > L->len-1){
        L->data[index] = x;
        L->len = index+1;
        return 0;   // 操作成功
    }else{
        for(int i=L->len-1; i>=index; i--){
            L->data[i+1] = L->data[i];
        }
        L->data[index] = x;
        L->len++;
        return 0;   // 操作成功
    }
}

// 删除元素
int Delete_SeqList(SeqList *L, int index){
    if(L == NULL || L->len == 0 || index >= L->len){
        return -1;  // 传入的参数有误
    }else if(index == L->len-1){
        L->data[index] = 0;
        L->len--;
        return 0;   // 操作成功
    }else{
        for(int i=index+1; i<L->len; i++){
            L->data[i-1] = L->data[i];
        }
        L->len--;
        return 0;   // 操作成功
    }
}

// 将顺序表(a1, a2, ..., an)以a1为界重排：a1前面的值均比a1小; a1后面的值均比a1大
int Part_SeqList(SeqList *L){
    if(L == NULL || L->len == 0){
        return -1;  // 传入的参数有误
    }else{
        int base = L->data[0];
        int temp;
        for(int i=1; i<L->len; i++){
            if(L->data[i] < base){
                temp = L->data[i];
                for(int j=i-1; j>=0; j--){
                    L->data[j+1] = L->data[j];
                }
                L->data[0] = temp;
            }
        }
        return 0;   // 操作成功
    }
}

// 合并两个增序列为新的增序列
SeqList *Merge_SeqList(SeqList *L1, SeqList *L2){
    if(L1 == NULL || L2 == NULL || L1->len ==0 || L2->len == 0 || L1->len+L2->len > MAXSIZE){
        return NULL;    // 传入的参数有误
    }else{
        SeqList *L = Init_SeqList();
        if(L == NULL){
            return NULL;    // 申请内存失败
        }
        int i=0, j=0, k=0;
        while(i<L1->len && j<L2->len){
            if(L1->data[i] < L2->data[j]){
                L->data[k++] = L1->data[i++];
                L->len++;
            }else{
                L->data[k++] = L2->data[j++];
                L->len++;
            }
        }
        for(; i<L1->len; i++, k++){
            L->data[k] = L1->data[i];
            L->len++;
        }
        for(; j<L2->len; j++, k++){
            L->data[k] = L2->data[j];
            L->len++;
        }
        return L;   // 返回新增序列的首地址
    }
}

// 比较两个顺序表
int Compare_SeqList(SeqList *L1, SeqList *L2){
    if(L1 == NULL || L2 == NULL || L1->len == 0 || L2->len == 0){
        return 0;   // 传参有误
    }else{
        int mark=0;
        while(L1->data[mark] == L2->data[mark] && (mark < L1->len || mark < L2->len)){
            mark++;
        }
        if(mark == L1->len && mark == L2->len){
            return 0;   // L1 == L2
        }else if((mark == L1->len && mark < L2->len) || (mark < L1->len && mark < L2->len && L1->data[mark] < L2->data[mark])){
            return -1;  // L1 < L2
        }else{
            return 1;   // L1 > L2
        }
    }
}

// 查找最大值
int Max_SeqList(SeqList *L){
    if(L == NULL || L->len == 0){
        return 0;   // 传入的参数有误
    }else{
        int maxVal = L->data[0];
        for(int i=1; i<L->len; i++){
            if(L->data[i] > maxVal){
                maxVal = L->data[i];
            }
        }
        return maxVal;  // 返回最大值
    }
}

// 查找最小值
int Min_SeqList(SeqList *L){
    if(L == NULL || L->len == 0){
        return 0;   // 传入的参数有误
    }else{
        int minVal = L->data[0];
        for(int i=1; i<L->len; i++){
            if(L->data[i] < minVal){
                minVal = L->data[i];
            }
        }
        return minVal;  // 返回最小值
    }
}

// 排序，rev参数如果为1表示倒序排列，为0则表示正序排列
int Sort_SeqList(SeqList *L, int rev){
    if(L == NULL || L->len == 0){
        return -1;  // 传入的参数有误
    }else{
        for(int i=0; i<L->len-1; i++){
            int sorted = 1;
            for(int j=0; j<L->len-1-i; j++){
                if(!rev){
                    if(L->data[j] > L->data[j+1]){
                        sorted = 0;
                        int temp = L->data[j];
                        L->data[j] = L->data[j+1];
                        L->data[j+1] = temp;
                    }
                }else{
                    if(L->data[j] < L->data[j+1]){
                        sorted = 0;
                        int temp = L->data[j];
                        L->data[j] = L->data[j+1];
                        L->data[j+1] = temp;
                    }
                }
            }
            if(sorted){
                break;
            }
        }
        return 0;   // 操作成功
    }
}

// 逆置元素
void Reverse_SeqList(SeqList *L){
    for(int i=0; i<L->len/2; i++){
        int tmp = L->data[i];
        L->data[i] = L->data[L->len-1-i];
        L->data[L->len-1-i] = tmp;
    }
}
