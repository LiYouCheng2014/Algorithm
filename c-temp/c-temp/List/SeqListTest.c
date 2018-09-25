//
//  SeqListTest.c
//  c-temp
//
//  Created by liyoucheng on 2018/7/23.
//  Copyright © 2018年 liyoucheng. All rights reserved.
//

#include "SeqListTest.h"

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef int ElemType;
//
////顺序表
//typedef struct
//{
//    ElemType data[MAXSIZE];
//    int length;
//}SqList;
//
////获取元素
////下标从1开始计算
//Status GetElem(SqList L, int i, ElemType *e)
//{
//    if (L.length == 0 || i < 1 || i > L.length) {
//        return ERROR;
//    }
//    *e = L.data[i - 1];
//    return OK;
//}
//
////插入元素
//Status ListInsert(SqList *L, int i, ElemType e)
//{
//    if (L->length >= MAXSIZE) {
//        return ERROR;
//    }
//    
//    if (i < 1 || i > L->length + 1) {
//        return ERROR;
//    }
//    
//    if (i <= L->length) {
//        //不在末尾，则此数据后的需要移动
//        for (int k = L->length - 1; k >= i - 1; k--) {
//            L->data[k + 1] = L->data[k];
//        }
//    }
//    L->data[i - 1] = e;
//    L->length++;
//    return OK;
//}
//
////删除元素
//Status ListDelete(SqList *L, int i, ElemType *e)
//{
//    if (L->length == 0) {
//        return ERROR;
//    }
//    
//    if (i < 1 || i > L->length) {
//        return ERROR;
//    }
//    
//    *e = L->data[i - 1];
//    
//    for (int k = i; k < L->length; k++) {
//        L->data[k - 1] = L->data[k];
//    }
//    L->length--;
//    return OK;
//}
