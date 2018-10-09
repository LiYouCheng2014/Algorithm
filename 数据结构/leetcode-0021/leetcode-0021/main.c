//
//  main.c
//  leetcode-0021
//
//  Created by liyoucheng on 2018/10/9.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include <stdio.h>

#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
}LinkList;

//带头结点
LinkList *CreateList()
{
    LinkList *list = (LinkList *)malloc(sizeof(LinkList));
    list->val = 0;
    list->next = NULL;
    
    return list;
}

void InsertList(LinkList *list, int data)
{
    //头插入
    LinkList *node = (LinkList *)malloc(sizeof(LinkList));
    node->val = data;
    node->next = NULL;
    
    node->next = list->next;
    list->next = node;
    list->val += 1;
}

void PrintList(LinkList *list)
{
    LinkList *p = list;
    while (p) {
        printf("%d",p->val);
        if (p->next) {
            printf("->");
        }
        p = p->next;
    }
    printf("\n");
}

void PrintList_head(LinkList *list)
{
    LinkList *p = list->next;
    while (p) {
        printf("%d",p->val);
        if (p->next) {
            printf("->");
        }
        p = p->next;
    }
    printf("\n");
}

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    if (l1 == NULL) {
        return l2;
    }
    
    if (l2 == NULL) {
        return l1;
    }
    
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    
    struct ListNode *ptr = dummy;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            ptr->next = l1;
            l1 = l1->next;
        }
        else {
            ptr->next = l2;
            l2 = l2->next;
        }
        ptr = ptr->next;
    }
    
    if (l1 == NULL) {
        ptr->next = l2;
    }
    
    if (l2 == NULL) {
        ptr->next = l1;
    }
    
    ptr = dummy->next;
    free(dummy);
    
    return ptr;
}

int main(int argc, const char * argv[]) {
    
    LinkList *listA = CreateList();
    InsertList(listA, 4);
    InsertList(listA, 2);
    InsertList(listA, 1);
    PrintList_head(listA);
    
    LinkList *listB = CreateList();
    InsertList(listB, 4);
    InsertList(listB, 3);
    InsertList(listB, 1);
    PrintList_head(listB);
    
    LinkList *p = mergeTwoLists(listA->next, listB->next);
    PrintList(p);
    return 0;
}
