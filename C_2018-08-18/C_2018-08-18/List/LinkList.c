//
//  LinkList.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "LinkList.h"

#include <stdlib.h>
#include <time.h>

typedef int ElemType;
#define MAXSIZE 20

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;

typedef struct Node *LinkList;

//带头结点

//查找第i个数据元素的值
Status LLGetElem(LinkList L, int i, ElemType *e)
{
    LinkList p = L->next;
    int j = 1;
    while (p && j < i) {//p不为空，j不等于i
        p = p->next;
        ++j;
    }
    
    if (!p || j > i) {
        return ERROR;
    }
    *e = L->data;
    
    return OK;
}

//插入
Status LLListInsert(LinkList *L, int i, ElemType e)
{
    LinkList p = *L;
    int j = 1;
    while (p && j < i) {//寻找第i个节点
        p = p->next;
        ++j;
    }
    
    if (!p || j > i) {
        return ERROR;
    }
    
    LinkList s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    
    //插入
    s->next = p->next;
    p->next = s;
    
    return OK;
}

//删除
Status LLListDelete(LinkList *L, int i, ElemType *e)
{
    int j = 1;
    LinkList p = *L;
    while (p->next && j < i) {
        p = p->next;
        ++j;
    }
    
    if (!(p->next) || j > i) {
        return ERROR;
    }
    
    LinkList q = p->next;
    p->next = q->next;
    
    *e = q->data;
    free(q);
    
    return OK;
}

//头插法
void LLCreateListHead(LinkList *L, int n)
{
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) {
        LinkList p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

//尾插法
void LLCreateListTail(LinkList *L, int n)
{
    *L = (LinkList)malloc(sizeof(Node));
    LinkList r = *L;
    (*L)->next = NULL;
    
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) {
        LinkList p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        
        r->next = p;
        r = p;
    }
    
    r->next = NULL;
}

//清空单链表
Status LLClearList(LinkList *L)
{
    LinkList p = (*L)->next;
    while (p) {
        LinkList q = p->next;
        free(p);
        p = q;
    }
    
    (*L)->next = NULL;
    return OK;
}
