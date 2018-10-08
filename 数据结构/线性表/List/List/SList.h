//
//  SList.h
//  List
//
//  Created by liyoucheng on 2018/10/8.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef SList_h
#define SList_h

#include <stdio.h>

typedef int DataType;

typedef struct SListNode
{
    DataType data;
    struct SListNode *next;
}SListNode;

// 如果要修改链表就必须加引用
//建立节点
SListNode* _BuyNode(DataType x);

//打印单链表
void PrintSlist(SListNode* pHead);

//尾插(这里用了引用，指明是list的别名，调用时传参，不用传地址)(引用在.c文件中不可用)
void PushBack(SListNode** pHead, DataType x);

//void PushBack(SListNode** pHead, DataType x);   // 这里的第一个参数指向链表第一个节点的指针的地址（调用时传参，传的是地址）
//尾删
void PopBack(SListNode** pHead);

//头插
void PushFront(SListNode** pHead, DataType x);

//头删
void PopFront(SListNode** pHead);

//清空整个链表
void DestoryList(SListNode** pHead);

//获取链表长度
int GetSize(SListNode* pHead);

//查找数据
SListNode* Find(SListNode* pHead, DataType x);

//在某位置后插入数据
void Insert(SListNode* pos, DataType x);

//删除某位置的数据
void Erase(SListNode** pHead, SListNode* pos);

//删除一个无头单链表的非尾节点
void DelNonTailNode(SListNode* pos);

// 在无头单链表的一个非头节点前插入一个节点
void InsertFrontNode(SListNode* pos, DataType x);

//查找中间节点
SListNode* FindMidNode(SListNode* pHead);

//查找倒数第k个节点(要求只能遍历一次)
SListNode* FindKNode(SListNode* pHead, int k);

//倒着打印单链表（递归）
void PrintTailToHead(SListNode* pHead);

//逆置单链表（需要接收返回值），原链表会被改
SListNode* Reverse_(SListNode* pHead);

// 将原链表逆置
void Reverse(SListNode** pHead);

//合并两个有序链表（合并后依然有序）（递归）
SListNode* Merge(SListNode* pHead1, SListNode* pHead2);

//冒泡排序
void Sort(SListNode* pHead);

#endif /* SList_h */
