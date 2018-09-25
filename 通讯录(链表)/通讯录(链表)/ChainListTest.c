//
//  ChainListTest.c
//  通讯录(链表)
//
//  Created by LiYouCheng on 2018/7/5.
//  Copyright © 2018年 Liyoucheng. All rights reserved.
//

#include "ChainListTest.h"

#include "ChainList.h"
#include "ChainList.c"

void ChainListAll(ChainListType *head)
{
    ChainListType *h;
    DATA data;
    h = head;
    printf("链表数据如下\n");
    while (h) {
        data = h->data;
        printf("%s,%s,%d\n",data.key,data.name,data.age);
        h = h->next;
    }
    return;
}
