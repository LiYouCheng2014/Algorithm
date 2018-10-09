//
//  LinkList.c
//  List
//
//  Created by liyoucheng on 2018/10/9.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "LinkList.h"

#include <stdlib.h>
#include <string.h>

/**
 创建节点

 @param data 数据
 @return 节点
 */
struct node *CreateNode(int data)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    
    if (p == NULL) {
        printf("malloc error.\n");
        return NULL;
    }
    
    //清理申请到的堆内存
    bzero(p, sizeof(struct node));
    
    //填充节点
    p->data = data;
    p->next = NULL;
    
    return p;
}

void PrintList(struct node *list)
{
    
    struct node *p = list;
    while (p) {
        printf("%d",p->data);
        if (p->next) {
            printf("->");
        }
        p = p->next;
    }
    printf("\n");
}

//插入尾节点
void InsertTail(struct node *list, struct node *new)
{
    struct node *p = list;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = new;
}

void PrintList_Head(struct node *list)
{
    
    struct node *p = list->next;
    while (p) {
        printf("%d",p->data);
        if (p->next) {
            printf("->");
        }
        p = p->next;
    }
    printf("\n总结点:%d\n",list->data);
}

//插入尾部 带头结点
void InsertTail_Head(struct node *list, struct node *new)
{
    int cnt = 0;
    struct node *p = list;
    while (p->next != NULL) {
        p = p->next;
        cnt++;
    }
    p->next = new;
    list->data = cnt + 1;
}

//插入头部 带头结点
void InsertHead_Head(struct node *list, struct node *new)
{
    new->next = list->next;
    list->next = new;
    list->data += 1;
}

void test()
{
    //定义头指针
    struct node *head1 = NULL;
    head1 = CreateNode(1);

    InsertTail(head1, CreateNode(2));
    InsertTail(head1, CreateNode(3));
    InsertTail(head1, CreateNode(4));
    PrintList(head1);
    
    //定义头结点
    struct node *head2 = NULL;
    head2 = CreateNode(0);
    
    InsertTail_Head(head2, CreateNode(1));
    InsertTail_Head(head2, CreateNode(2));
    InsertTail_Head(head2, CreateNode(3));
    
    PrintList_Head(head2);
    
    //定义头结点
    struct node *head3 = NULL;
    head3 = CreateNode(0);
    
    InsertHead_Head(head3, CreateNode(1));
    InsertTail_Head(head3, CreateNode(2));
    InsertHead_Head(head3, CreateNode(3));
    
    PrintList_Head(head3);
}
