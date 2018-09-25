//
//  StaticLinkList.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "StaticLinkList.h"

typedef int ElemType;
#define MAXSIZE 2000

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
//数组的第一个和最后一个元素不处理 第一个元素存储第一个空余的下标，最后一个元素存储第一个有元素的下标

typedef struct
{
    ElemType data;
    int cur;//0表示无指向
} Component, StaticLinkList[MAXSIZE];

//初始化
Status SLLInitList(StaticLinkList space)
{
    for (int i = 0; i < MAXSIZE - 1; i++) {
        space[i].cur = i + 1;
    }
    space[MAXSIZE - 1].cur = 0;
    
    return OK;
}

//申请
int SLLMalloc_SLL(StaticLinkList space)
{
    int i = space[0].cur;
    if (space[0].cur) {
        space[0].cur = space[i].cur;
    }
    return i;
}

//销毁
void SLLFree_SSL(StaticLinkList space, int k)
{
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

int SLLListLengt(StaticLinkList L)
{
    int i = L[MAXSIZE - 1].cur;
    int j = 0;
    while (i) {
        i = L[i].cur;
        j++;
    }
    
    return j;
}

//插入
Status SLLListInsert(StaticLinkList L, int i, ElemType e)
{
    int k = MAXSIZE - 1;
    if (i < 1 || i > SLLListLengt(L) + 1) {
        return ERROR;
    }
    int j = SLLMalloc_SLL(L);
    if (j) {
        L[j].data = e;
        for (int l = 1; l <= i - 1; l++) {
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;
        L[k].cur = j;
        
        return OK;
    }
    
    return ERROR;
}

//删除
Status SLLListDelete(StaticLinkList L, int i)
{
    if (i < 1 || i > SLLListLengt(L)) {
        return ERROR;
    }
    int k = MAXSIZE - 1;
    
    for (int j = 1; j <= i - 1; j++) {
        k = L[k].cur;
    }
    int j = L[k].cur;
    L[k].cur = L[j].cur;
    
    SLLFree_SSL(L, j);
    
    return OK;
    
}
