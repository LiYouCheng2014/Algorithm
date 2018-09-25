//
//  lc_019.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/28.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "lc_019.h"

#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
    if (!head->next) {
        return NULL;
    }
    
    struct ListNode *pre = head;
    struct ListNode *cur = head;
    
    for (int i = 0; i < n; ++i) {
        cur = cur->next;
    }
    
    if (!cur) {
        return head->next;
    }
    
    while (cur->next) {
        cur = cur->next;
        pre = pre->next;
    }
    pre->next = pre->next->next;
    
    return head;
}
