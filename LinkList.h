#ifndef __LINKLIST_H
#define __LINKLIST_H

#include <stdbool.h>

/**
 * LNode: 结点类型
 * LinkList: 头指针类型，也就是链表
 * data: 数据域, 这里假设类型为int
 * next: 指针域, 指向下一个结点
**/
typedef struct LNode{
    int data;
    struct LNode *next;
} LNode, *LinkList;

/**
 * 创建一个单链表(尾插法)
 * @param void      不接受参数
 * @return LinkList 返回该链表的头指针
**/
extern LinkList createLinkList(void);

/**
 * 创建一个单链表(头插法)
 * @param void      不接受参数
 * @return LinkList 返回该链表的头指针
**/
extern LinkList createLinkList2(void);

/**
 * 获取链表长度
 * @param L     要操作的单链表L
 * @return int  返回L的长度
**/
extern int lengthLinkList(LinkList L);

/**
 * 清空单链表L的所有元素(除了头结点)
 * @param L     要操作的单链表L
 * @return void 无返回值
**/
extern void clearLinkList(LinkList L);

/**
 * 销毁单链表L
 * @param *pL   二级指针: 指向单链表L的指针
 * @return void 无返回值
**/
extern void destroyLinkList(LinkList *pL);

/**
 * 打印单链表L
 * @param L     要操作的单链表L
 * @return void 无返回值
**/
extern void printLinkList(LinkList L);

/**
 * 判断单链表L是否为空
 * @param L     要操作的单链表L
 * @return bool true: 空; false: 非空
**/
extern bool isEmptyLinkList(LinkList L);

/**
 * 在索引值为index的位置插入一个值为val的新结点
 * @param L     要操作的单链表L
 * @param index 插入的位置
 * @param val   索引值index的数据域
 * @return bool true: 插入成功; false: 参数有误
**/
extern bool insertLinkList(LinkList L, int index, int val);

/**
 * 删除索引值为index的结点
 * @param L     要操作的单链表L
 * @param index 索引值index
 * @return bool true: 删除成功; false: 参数有误
**/
extern bool deleteLinkList(LinkList L, int index);

/**
 * 删除第一个值为val的结点
 * @param L     要操作的单链表L
 * @param val   值val
 * @return bool true: 删除成功; false: 删除失败
**/
extern bool deleteValLinkList(LinkList L, int val);

/**
 * 获取索引值为index的结点的数据域
 * @param L     要操作的单链表L
 * @param index 索引值index
 * @return int  返回数据域的值
**/
extern int getLinkList(LinkList L, int index);

/**
 * 按值查找，返回第一次出现的索引值index
 * @param L     要操作的单链表L
 * @param val   所查找的值
 * @return int  成功: 返回第一次出现的索引值index; 失败: 返回-1
**/
extern int locateLinkList(LinkList L, int val);

/**
 * 修改索引值为index上的值为val
 * @param L     要操作的单链表
 * @param index 索引值index
 * @param val   新值val
 * @return bool true: 修改成功; false: 参数有误
**/
extern bool modifyLinkList(LinkList L, int index, int val);

/**
 * 在链表后添加一个结点，值为val
 * @param L     要操作的单链表L
 * @param val   值val
 * @return int  插入成功则返回所插入的值val
**/
extern int appendLinkList(LinkList L, int val);

/**
 * 移除链表的最后一个结点
 * @param L     要操作的单链表L
 * @return int  被删除的结点的值val
**/
extern int popLinkList(LinkList L);

/**
 * 排序(冒泡排序)
 * @param L     要操作的单链表L
 * @param rev   0:正序排列; 1:倒序排列
 * @return void 无返回值
**/
extern void sortLinkList(LinkList L, int rev);

/**
 * 逆置单链表
 * @param L     要操作的单链表L
 * @return void 无返回值
**/
extern void reverseLinkList(LinkList L);

#endif
