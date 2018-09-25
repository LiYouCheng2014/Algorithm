//
//  BiThrTree.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/21.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "BiThrTree.h"


typedef int Status;
#define OK 1
#define ERROR 0

typedef char TElemType;

typedef enum {
    Link,//Link == 0表示左右孩子指针
    Thread//Thread==1表示指向前驱或后继的线索
} PointerTag;

typedef struct BiThrNode
{
    TElemType data;
    struct BiThrNode *lchild;
    struct BiThrNode *rchild;
    PointerTag LTag;
    PointerTag RTag;
} BiThrNode, *BiThrTree;

BiThrTree pre;//指向刚刚访问过得结点


//中序便利进行中序线索化
void InThreading(BiThrTree p)
{
    if (p) {
        InThreading(p->lchild);
        if (!p->lchild) {//没有左孩子
            p->LTag = Thread;
            p->lchild = pre;
        }
        if (!pre->rchild) {//前驱没有右孩子
            pre->RTag = Thread;
            pre->rchild = p;
        }
        pre = p;
        InThreading(p->rchild);
    }
}

Status InOrderTraverse_Thr(BiThrTree T)
{
    BiThrTree p;
    p = T->lchild;
    while (p != T) {
        while (p->LTag == Link) {
            p = p->lchild;
        }
        printf("%c",p->data);
        while (p->RTag == Thread && p->rchild != T) {
            p = p->rchild;
            printf("%c",p->data);
        }
        p = p->rchild;
    }
    return OK;
}
