//
//  ChainList.h
//  通讯录(链表)
//
//  Created by LiYouCheng on 2018/7/5.
//  Copyright © 2018年 Liyoucheng. All rights reserved.
//

#ifndef ChainList_h
#define ChainList_h

#include <stdio.h>
#include <stdlib.h>

#include "ChainListTest.h"
//#include "ChainListTest.h"

typedef struct Node
{
    DATA data;
    struct Node *next;
}ChainListType;

//添加到末尾
ChainListType *ChainListAddEnd(ChainListType *head, DATA data);
//添加到首部
ChainListType *ChainListAddFirst(ChainListType *head, DATA data);
//按关键字查找内容
ChainListType *ChainListFind(ChainListType *head, char *key);
//插入节点到指定位置
ChainListType *ChainListInsert(ChainListType *head, char *findkey, DATA data);
//删除指定关键字
int ChainListDelete(ChainListType *head, char *key);
//节点数量
int ChainListLength(ChainListType *head);

#endif /* ChainList_h */
