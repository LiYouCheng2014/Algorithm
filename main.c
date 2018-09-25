//
//  main.c
//  C-0021
//
//  Created by liyoucheng on 2018/7/2.
//  Copyright © 2018年 liyoucheng. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *list1 = l1;
    struct ListNode *list2 = l2;
    
    struct ListNode *pTail = NULL;
    struct ListNode *newHead = NULL;
    if (list1 == NULL) {
        return list2;
    }
    else if (list2 == NULL) {
        return list1;
    }
    else {
        if (list1->val <= list2->val) {
            newHead = list1;
            list1 = list1->next;
        }
        else {
            newHead = list2;
            list2 = list2->next;
        }
        
        pTail = newHead;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                pTail->next = list1;
                list1 = list1->next;
            }
            else {
                pTail->next = list2;
                list2 = list2->next;
            }
            pTail = pTail->next;
        }
        
        if (list1 == NULL) {
            pTail->next = list2;
        }
        else if (list2 == NULL) {
            pTail->next = list1;
        }
    }
    
    return newHead;
}

struct ListNode* creatNode(int a[]) {
    struct ListNode *head, *pt, *p = NULL;
    head = pt = (struct ListNode *)malloc(sizeof(struct ListNode));
    
//    int a[3] = { 1,2,4 };
    for (int i = 0; i < 3; i++) {
        pt->val = a[i];
        p = pt;
        pt = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next = pt;
    }
    p->next = NULL;
    return head;
}

void printNode(struct ListNode *p) {
    printf("打印链表的值：\n");
    while(p->next != NULL){
        printf("%d ",p->val);
        p = p->next;
    }
    printf("%d\n",p->val);
}

int main(int argc, const char * argv[]) {
    
    int a[3] = { 1,2,4 };
    struct ListNode *aNode = creatNode(a);
    printNode(aNode);
    
    int b[3] = { 1,3,4 };
    struct ListNode *bNode = creatNode(b);
    printNode(bNode);
    
    struct ListNode *cNode = mergeTwoLists(aNode, bNode);
    printNode(cNode);
//    head = pt = (struct ListNode *)malloc(sizeof(struct ListNode));
//
//    int a[3] = { 1,2,4 };
//    for (int i = 0; i < 3; i++) {
//        pt->val = a[i];
//        p = pt;
//        pt = (struct ListNode *)malloc(sizeof(struct ListNode));
//        p->next = pt;
//    }
//    p->next = NULL;
//
//    p = head;
//    int b[3] = { 1,3,4 };
//    for (int i = 0; i < 3; i++) {
//        pt->val = b[i];
//        p = pt;
//        pt = (struct ListNode *)malloc(sizeof(struct ListNode));
//        p->next = pt;
//    }
//    p->next = NULL;
    
//    scanf("%d",&pt->val);
//    while(pt->val != 0){
//        p = pt;
//        pt = (struct ListNode *)malloc(sizeof(struct ListNode));
//        scanf("%d",&pt->val);
//        p->next = pt;
//    }
//    p->next = NULL;

//    struct ListNode *p = aNode;
//    printf("打印链表的值：\n");
//    while(p->next != NULL){
//        printf("%d ",p->val);
//        p = p->next;
//    }
//    printf("%d ",p->val);
//
//    int a[3] = { 1,2,4 };
//    struct ListNode *aNode = NULL;
//    for (int i = 0; i < 3; i++) {
//        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
//        if (i == 0) {
//            node->val = a[i];
//            node->next = NULL;
//            aNode = node;
//        }
//
//        aNode = aNode->next;
//    }
//
//    struct ListNode *p = aNode;
//    while (p) {
//        printf("%d=>",p->val);
//        p = p->next;
//    }
//    printf("\n");

//
//    int b[3] = { 1,3,4 };
//
//
//    struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
//    node1->val = 1;
//    node1->next = NULL;
//
//    struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
//    node2->val = 3;
//    node2->next = NULL;
//
//    struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
//    node3->val = 4;
//    node3->next = NULL;
//
//    nodeh->next = node1;
//    node1->next = node2;
//    node2->next = node3;
//
//    struct ListNode *p = nodeh->next;
//    while (p) {
//        printf("%d=>",p->val);
//        p = p->next;
//    }
//    printf("\n");
//
//    struct ListNode *nodeh1 = (struct ListNode *)malloc(sizeof(struct ListNode));
//
//    struct ListNode *node11 = (struct ListNode *)malloc(sizeof(struct ListNode));
//    node11->val = 1;
//    node11->next = NULL;
//
//    struct ListNode *node12 = (struct ListNode *)malloc(sizeof(struct ListNode));
//    node12->val = 2;
//    node12->next = NULL;
//
//    struct ListNode *node13 = (struct ListNode *)malloc(sizeof(struct ListNode));
//    node13->val = 4;
//    node13->next = NULL;
//
//    nodeh1->next = node11;
//    node11->next = node12;
//    node12->next = node13;
//
//    struct ListNode *p1 = nodeh1->next;
//    while (p1) {
//        printf("%d=>",p1->val);
//        p1 = p1->next;
//    }
//    printf("\n");
//
//    struct ListNode *newNode = mergeTwoLists(nodeh1, nodeh);
//    struct ListNode *p2 = newNode->next;
//    while (p2) {
//        printf("%d=>",p2->val);
//        p2 = p2->next;
//    }
//    printf("\n");
    
    return 0;
}
