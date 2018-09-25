//
//  lc_002.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/21.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "lc_002.h"

#include <stdlib.h>

/*
 给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
 
 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 
 示例：
 
 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 输出：7 -> 0 -> 8
 原因：342 + 465 = 807
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p = l1;
    struct ListNode *q = l2;
    
    struct ListNode *ret = (struct ListNode *)malloc(sizeof(struct ListNode));;
    struct ListNode *tmp = ret;
    
    int carray = 0;
    while(p != NULL || q != NULL) {
        int x = (p != NULL) ? p->val : 0;
        int y = (q != NULL) ? q->val : 0;
        int sum = x + y + carray;
        
        struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val = sum % 10;
        carray = sum / 10;
        tmp->next = temp;
        
        tmp = tmp->next;
        if (p != NULL) {
            p=p->next;
        }
        
        if (q != NULL) {
            q=q->next;
        }
    }
    
    if (carray == 1) {
        //最后一位进位
        struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val = carray;
        tmp->next = temp;
        
        tmp = tmp->next;
    }
    tmp->next = NULL;
    
    return ret->next;
}
