//
//  DoubleLinkList.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "DoubleLinkList.h"

typedef int ElemType;
#define MAXSIZE 2000

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

typedef struct DulNode
{
    ElemType data;
    struct DulNode *prior;
    struct DulNode *next;
} DulNode, *DuLinkList;

//带头结点

//插入
//p p->next
//之间插入s
void DLLInsert(DuLinkList L)
{
    //先解决s的前驱和后继，再搞定后接点的前驱，最后解决前结点的后继
//    s->prior = p;
//    s->next = p->next;
//    p->next->prior = s;
//    p->next = s;
}

//删除
//p
void DLLDelete(DuLinkList L)
{
//    p->prior->next = p->next;
//    p->next->prior = p->prior;
    //    free(p);
}

//删除

