//
//  ChainList.c
//  通讯录(链表)
//
//  Created by LiYouCheng on 2018/7/5.
//  Copyright © 2018年 Liyoucheng. All rights reserved.
//

#include "ChainList.h"
#include <string.h>

//添加到末尾
ChainListType *ChainListAddEnd(ChainListType *head, DATA data)
{
    ChainListType *node;
    ChainListType *h;
    
    if (!(node = (ChainListType *)malloc(sizeof(ChainListType))))
    {
        printf("保存节点数据申请内存失败\n");
        return NULL;
    }
    
    node->data = data;
    node->next = NULL;
    if (head == NULL) {
        head = node;//链表头指针指向当前节点
        return head;
    }
    
    h = head;
    while (h->next != NULL) {
        h = h->next;
    }
    h->next = node;
    return head;
}

//添加到首部
ChainListType *ChainListAddFirst(ChainListType *head, DATA data)
{
    ChainListType *node;
    
    if (!(node = (ChainListType *)malloc(sizeof(ChainListType))))
    {
        printf("保存节点数据申请内存失败\n");
        return NULL;
    }
    
    node->data = data;
    node->next = head;
    head = node;
    
    return head;
}

//按关键字查找内容
ChainListType *ChainListFind(ChainListType *head, char *key)
{
    ChainListType *h;
    h = head;
    while (h) {
        if (strcmp(h->data.key,key) == 0) {
            return h;
        }
        h = h->next;
    }
    return NULL;
}

//插入节点到指定位置
ChainListType *ChainListInsert(ChainListType *head, char *findKey, DATA data)
{
    ChainListType *node;
    ChainListType *node1;
    
    if (!(node = (ChainListType *)malloc(sizeof(ChainListType))))
    {
        printf("保存节点数据申请内存失败\n");
        return NULL;
    }
    
    node->data = data;
    node1 = ChainListFind(head,findKey);
    if (node1) {
        node->next = node1->next;
        node1->next = node;
    }
    else {
        free(node);
        printf("未能找到插入位置\n");
    }
    
    return head;
}

//删除指定关键字
int ChainListDelete(ChainListType *head, char *key)
{
    ChainListType *node;
    ChainListType *h;
    node = h = head;
    
    while (h) {
        if (strcmp(h->data.key,key) == 0) {
            node->next = h->next;
            free(h);
            return 1;
        }
        else {
            node = h;
            h = h->next;
        }
    }
    return 0;
}

//节点数量
int ChainListLength(ChainListType *head)
{
    ChainListType *h;
    int i = 0;
    h = head;
    while (h) {
        i++;
        h = h->next;
    }
    return i;
}

