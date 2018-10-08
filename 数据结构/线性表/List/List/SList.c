//
//  SList.c
//  List
//
//  Created by liyoucheng on 2018/10/8.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "SList.h"

#include <stdlib.h>

// 如果要修改链表就必须加引用
//建立节点
SListNode* _BuyNode(DataType x)
{
    SListNode *tmp = (SListNode *)malloc(sizeof(SListNode));
    tmp->data = x;
    tmp->next = NULL;
    
    return tmp;
}

//打印单链表
void PrintSlist(SListNode* pHead)
{
    SListNode *cur = pHead;
    while (cur) {
        printf("%d->",cur->data);
        cur = cur->next;
    }
    
    printf("\n");
}

//尾插(这里用了引用，指明是list的别名，调用时传参，不用传地址)(引用在.c文件中不可用)
void PushBack(SListNode** pHead, DataType x)
{
    if (*pHead == NULL) {
        *pHead = _BuyNode(x);
    }
    else {
        SListNode *tail = *pHead;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = _BuyNode(x);
    }
}

//void PushBack(SListNode** pHead, DataType x);   // 这里的第一个参数指向链表第一个节点的指针的地址（调用时传参，传的是地址）
//尾删
void PopBack(SListNode** pHead)
{
    if (*pHead == NULL) {
        return;
    }
    else if ((*pHead)->next == NULL) {
        free(*pHead);
        *pHead = NULL;
    }
    else {
        SListNode *tail = *pHead;
        SListNode *prev = NULL;
        while (tail->next) {
            prev = tail;
            tail = tail->next;
        }
        
        free(tail);
        prev->next = NULL;
    }
}

//头插
void PushFront(SListNode** pHead, DataType x)
{
    if (*pHead == NULL) {
        *pHead = _BuyNode(x);
    }
    else {
        SListNode *tmp = _BuyNode(x);
        tmp->next = *pHead;
        *pHead = tmp;
    }
}

//头删
void PopFront(SListNode** pHead)
{
    if (*pHead == NULL) {
        return;
    }
    else if ((*pHead)->next == NULL) {
        free(*pHead);
        *pHead = NULL;
    }
    else {
        SListNode *tmp = *pHead;
        *pHead = (*pHead)->next;
        
        free(tmp);
    }
}

//清空整个链表
void DestoryList(SListNode** pHead)
{
    SListNode *cur = *pHead;
    while (cur) {
        SListNode *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    *pHead = NULL;
}

//获取链表长度
int GetSize(SListNode* pHead)
{
    SListNode *cur = pHead;
    int count = 0;
    while (cur) {
        count++;
        cur = cur->next;
    }
    return count;
}

//查找数据
SListNode* Find(SListNode* pHead, DataType x)
{
    SListNode *cur = pHead;
    while (cur) {
        if (cur->data == x) {
            return cur;
        }
        cur = cur->next;
    }
    
    return NULL;
}

//在某位置后插入数据
void Insert(SListNode* pos, DataType x)
{
    SListNode *tmp = _BuyNode(x);
    tmp->next = pos->next;
    pos->next = tmp;
}

//删除某位置的数据
void Erase(SListNode** pHead, SListNode* pos)
{
    if (*pHead == pos) {
        *pHead = (*pHead)->next;
        free(pos);
        return;
    }
    
    SListNode *prev = *pHead;
    while (prev) {
        if (prev->next == pos) {
            prev->next = pos->next;
            free(pos);
            break;
        }
        prev = prev->next;
    }
}

//删除一个无头单链表的非尾节点
void DelNonTailNode(SListNode* pos)
{
    SListNode *del = pos->next;
    SListNode *dnext = del->next;
    pos->data = del->data;
    pos->next = dnext;
    free(del);
}

// 在无头单链表的一个非头节点前插入一个节点
void InsertFrontNode(SListNode* pos, DataType x)
{
    SListNode *tmp = _BuyNode(pos->data);
    tmp->next =pos->next;
    pos->next = tmp;
    pos->data = x;
}

//查找中间节点
SListNode* FindMidNode(SListNode* pHead)
{
    SListNode *fast = pHead;
    SListNode *slow = pHead;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//查找倒数第k个节点(要求只能遍历一次)
SListNode* FindKNode(SListNode* pHead, int k)
{
    SListNode *fast = pHead;
    SListNode *slow = pHead;
    
    while (fast && k--) {
        fast = fast->next;
    }
    if (k > 0) {
        return NULL;
    }
    
    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

//倒着打印单链表（递归）
void PrintTailToHead(SListNode* pHead)
{
    if (pHead) {
        PrintTailToHead(pHead->next);
        printf("%d ",pHead->data);
    }
}

//逆置单链表（需要接收返回值），原链表会被改
SListNode* Reverse_(SListNode* pHead)
{
    SListNode *cur = pHead;
    SListNode *newHead = NULL;
    while (cur) {
        SListNode *tmp = cur;
        cur = cur->next;
        tmp->next = newHead;
        newHead = tmp;
    }
    return newHead;
}

// 将原链表逆置
void Reverse(SListNode** pHead)
{
    SListNode *cur = *pHead;
    SListNode *newHead = NULL;
    while (cur) {
        SListNode *tmp = cur;
        cur = cur->next;
        tmp->next = newHead;
        newHead = tmp;
    }
    *pHead = newHead;
}

//合并两个有序链表（合并后依然有序）（递归）
SListNode* Merge(SListNode* pHead1, SListNode* pHead2)
{
    if (pHead1 == NULL) {
        return pHead2;
    }
    else if (pHead2 == NULL) {
        return pHead1;
    }
    
    SListNode *pMergedHead = NULL;
    if (pHead1->data < pHead2->data) {
        pMergedHead = pHead1;
        pMergedHead->next = Merge(pHead1->next, pHead2);
    }
    else {
        pMergedHead = pHead2;
        pMergedHead->next = Merge(pHead1, pHead2->next);
    }
    return pMergedHead;
}

//冒泡排序
void Sort(SListNode* pHead)
{
    int size = GetSize(pHead);
    for (int i = 0; i < size - 1; i++) {
        SListNode *left = pHead;
        SListNode *right = pHead->next;
        for (int j = 0; j < size - i - 1; j++) {
            if (left->data > right->data) {
                int tmp = left->data;
                left->data = right->data;
                right->data = tmp;
            }
            right = right->next;
            left = left->next;
        }
    }
}
