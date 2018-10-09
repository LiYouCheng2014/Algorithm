//
//  LinkListHead.c
//  List
//
//  Created by liyoucheng on 2018/10/9.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "LinkListHead.h"

#include <stdlib.h>
#include <string.h>

LinkList *CreatList(int n)
{
    //头结点
    LinkList *head = (LinkList *)malloc(sizeof(LinkList));

    //尾部节点
    LinkList *end = head;
    
    for (int i = 0; i < n; i++) {
        //普通节点
        LinkList *node = (LinkList *)malloc(sizeof(LinkList));
        scanf("%d", &node->data);
        
        //尾插法
        end->next = node;
        end = node;
    }
    
    //结束创建
    end->next = NULL;
    
    return head;
}

void Change(LinkList *list, int n)
{
    LinkList *t = list;
    int i = 0;
    while (i < n && t != NULL) {
        t = t->next;
        i++;
    }
    
    if (t != NULL) {
        scanf("%d",&t->data);
    }
    else {
        
    }
}

void Delete(LinkList *list, int n)
{
    LinkList *t = list;
    LinkList *in = NULL;
    int i = 0;
    while (i < n && t != NULL) {
        in = t;
        t = t->next;
        i++;
    }
    
    if (t != NULL) {
        in->next = t->next;
        free(t);
    }
    else {
        
    }
}

void Insert(LinkList *list, int n)
{
    LinkList *t = list;
    LinkList *in = NULL;
    int i = 0;
    while (i < n && t != NULL) {
        t = t->next;
        i++;
    }
    
    if (t != NULL) {
        in = (LinkList *)malloc(sizeof(LinkList));
        scanf("%d",&in->data);
        
        in->next = t->next;
        t->next = in;
    }
}

void PrintListHead(LinkList *list)
{
    
    LinkList *p = list->next;
    while (p) {
        printf("%d",p->data);
        if (p->next) {
            printf("->");
        }
        p = p->next;
    }
    printf("\n");
}

void testLinkList()
{
    
}
