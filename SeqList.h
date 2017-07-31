#ifndef __SEQLIST_H
#define __SEQLIST_H

#define MAXSIZE 100   // MAXSIZE
typedef struct{
    int data[MAXSIZE];    // data
    int len;        // data的长度，即元素个数
} SeqList;

// 初始化
extern SeqList *Init_SeqList();

// 判空
extern int Empty_SeqList(SeqList *L);

// 获取长度
extern int Length_SeqList(SeqList *L);

// 打印SeqList
extern void Print_SeqList(SeqList *L);

// 销毁
extern int Destroy_SeqList(SeqList *L);

// 取表元
extern int GetElem_SeqList(SeqList *L, int i);

// 按值查找
extern int Locate_SeqList(SeqList *L, int x);

// 表尾插入元素
extern int Append_SeqList(SeqList *L, int x);

// 移除表的最后一项
extern int Pop_SeqList(SeqList *L);

// 插入元素
extern int Insert_SeqList(SeqList *L, int index, int x);

// 删除元素
extern int Delete_SeqList(SeqList *L, int index);

// 将顺序表(a1, a2, ..., an)以a1为界重排：a1前面的值均比a1小; a1后面的值均比a1大
extern int Part_SeqList(SeqList *L);

// 合并两个增序列为新的增序列
extern SeqList *Merge_SeqList(SeqList *L1, SeqList *L2);

// 比较两个顺序表
extern int Compare_SeqList(SeqList *L1, SeqList *L2);

// 查找最大值
extern int Max_SeqList(SeqList *L);

// 查找最小值
extern int Min_SeqList(SeqList *L);

// 排序，rev参数如果为1表示倒序排列，为0则表示正序排列
extern int Sort_SeqList(SeqList *L, int rev);

// 逆置元素
extern void Reverse_SeqList(SeqList *L);

#endif
