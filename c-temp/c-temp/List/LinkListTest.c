//
//  LinkListTest.c
//  c-temp
//
//  Created by liyoucheng on 2018/7/23.
//  Copyright © 2018年 liyoucheng. All rights reserved.
//

#include "LinkListTest.h"

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef int ElemType;
//
//typedef struct Node
//{
//    ElemType data;
//    struct Node *next;
//} Node;
//
//typedef struct Node * LinkList;
//
////获取元素
//Status GetElem(LinkList L, int i, ElemType *e)
//{
//    LinkList p;
//    p = L->next;//带头结点
//    int j = 1;
//    while (p && j < i) {
//        p = p->next;
//        ++j;
//    }
//    
//    if (!p || j > i) {
//        return ERROR;
//    }
//    
//    *e = p->data;
//    
//    return OK;
//}
//
////插入元素
//Status ListInsert(LinkList *L, int i, ElemType e)
//{
//    LinkList p = *L;
//    LinkList s;
//    int j = 1;
//    
//    while (p && j < i) {
//        p = p->next;
//        ++j;
//    }
//    
//    if (!p || j > i) {
//        return ERROR;
//    }
//    
//    s = (LinkList)malloc(sizeof(Node));
//    s->data = e;
//    
//    s->next = p->next;
//    p->next = s;
//    
//    return OK;
//}
//
////删除元素
//Status ListDelete(LinkList *L, int i, ElemType *e)
//{
//    LinkList p = *L;
//    LinkList q;
//    int j = 1;
//    
//    //找到要删除的前一个节点
//    while (p->next && j < i) {
//        p = p->next;
//        ++j;
//    }
//    
//    if (!(p->next) || j > i) {
//        return ERROR;
//    }
//    q = p->next;
//    
//    p->next = q->next;
//    *e = q->data;
//    
//    free(q);
//    
//    return OK;
//}
//
////创建链表（头插法)
//void CreateListHead(LinkList *L, int n)
//{
//    LinkList p;
//    //初始化随机数种子
//    srand((unsigned)time(0));
//    
//    //创立带头结点的单链表
//    *L = (LinkList)malloc(sizeof(Node));
//    (*L)->next = NULL;
//    
//    for (int i = 0; i < n; i++) {
//        p = (LinkList)malloc(sizeof(Node));
//        p->data = rand()%100 + 1;
//        
//        p->next = (*L)->next;
//        (*L)->next = p;
//    }
//}
//
////创建链表（尾插法)
//void CreateListTail(LinkList *L, int n)
//{
//    LinkList p;
//    LinkList r;
//    //初始化随机数种子
//    srand((unsigned)time(0));
//    
//    //创立带头结点的单链表
//    *L = (LinkList)malloc(sizeof(Node));
//    r = *L;//r指向尾部的节点
//
//    for (int i = 0; i < n; i++) {
//        p = (LinkList)malloc(sizeof(Node));
//        p->data = rand()%100 + 1;
//        
//        r->next = p;
//        r = p;
//    }
//    r->next = NULL;
//}
//
////链表删除
//Status clearList(LinkList *L)
//{
//    LinkList p;
//    LinkList q;
//    p = (*L)->next;
//    while (p) {
//        q = p->next;
//        free(p);
//        p = q;
//    }
//    
//    (*L)->next = NULL;
//    return OK;
//}



