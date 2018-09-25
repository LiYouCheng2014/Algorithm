//
//  LYCSeqList.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/9/11.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "LYCSeqList.h"

#include <stdlib.h>

typedef int SElementType;

#define MAXSIZE 100

struct SLNode {
    SElementType Data[MAXSIZE];
    int Last;//线性表最后一个元素位置，从0开始
};

//线性表顺序存储实现
typedef struct SLNode *SList;

//struct SLNode SL;

//初始化 建立空的顺序表
SList SLMakeEmpty()
{
    SList PtrSL;
    PtrSL = (SList)malloc(sizeof(struct SLNode));
    PtrSL->Last = -1;
    return PtrSL;
}

//查找
int SLFind(SElementType X, SList L)
{
    int i = 0;
    while (i <= L->Last && L->Data[i] != X) {
        i++;
    }
    
    if (i > L->Last) {
        return -1;
    }
    else {
        return i;
    }
}

//插入 第i个位置从1开始
void SLInsert(SElementType X, int i, SList L)
{
    int j;
    if (L->Last == MAXSIZE - 1) {
        //表满
        return;
    }
    
    if (i < 1 || i > L->Last + 2) {
        //位置不合法
        return;
    }
    
    for (j = L->Last; j >= i - 1; j--) {
        L->Data[j + 1] = L->Data[j];
    }
    L->Data[i - 1] = X;
    L->Last++;
    
    return;
}

//删除 第i个位置从1开始
void SLDelete(int i, SList L)
{
    if (L->Last <= 0) {
        //表空
        return;
    }
    
    if (i < 1 || i > L->Last + 1) {
        //位置不合法
        return;
    }
    
    for (int j = i; j <= L->Last; j++) {
        L->Data[j - 1] = L->Data[j];
    }
    L->Last--;
    
    return;
}
