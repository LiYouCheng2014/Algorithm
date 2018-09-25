//
//  SqList.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "SqList.h"

typedef int ElemType;
#define MAXSIZE 20

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SqList;

//i从1开始

//获取元素
Status SLGetElem(SqList L, int i, ElemType *e)
{
    if (L.length == 0 || i < 1 || i > L.length) {
        return ERROR;
    }
    
    *e = L.data[i - 1];
    
    return OK;
}

//插入
Status SLListInsert(SqList *L,int i, ElemType e)
{
    if (L->length == MAXSIZE) {
        return ERROR;//线程满
    }
    
    if (i < 1 || i > L->length + 1) {
        return ERROR;//i不在范围内
    }
    
    if (i <= L->length) {//插入数据不在末尾
        for (int j = L->length - 1; j >= i - 1; j--) {
            L->data[j + 1] = L->data[j];
        }
    }

    L->data[i - 1] = e;
    L->length++;
    
    return OK;
}

//删除
Status SLListDelete(SqList *L, int i, ElemType *e)
{
    if (L->length == 0) {
        return ERROR;//线性表空
    }
    
    if (i < 1 || i > L->length) {
        return ERROR;
    }
    
    *e = L->data[i - 1];
    
    if (i < L->length) {//删除数据不在末尾
        for (int j = i; j < L->length; j++) {
            L->data[j - 1] = L->data[j];
        }
    }
    L->length--;
    
    return OK;
}

//InitList(*L)
//ListEmpty(L)
//CelarList*L)
//LocateElem(L,e)
//ListLength(L)
