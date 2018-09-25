//
//  StaticLinkListTest.c
//  c-temp
//
//  Created by liyoucheng on 2018/7/24.
//  Copyright © 2018年 liyoucheng. All rights reserved.
//

#include "StaticLinkListTest.h"

#define MAXSIZE 1000
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef int ElemType;
//
//typedef struct
//{
//    ElemType data;
//    int cur;//0表示无指向
//} Component, StaticLinkList[MAXSIZE];
//
//Status InitList(StaticLinkList space)
//{
//    for (int i = 0; i < MAXSIZE - 1; i++) {
//        space[i].cur = i + 1;
//    }
//    space[MAXSIZE - 1].cur = 0;//最后一个元素的游标
//
//    return OK;
//}
//
//int Malloc_SLL(StaticLinkList space)
//{
//    int i = space[0].cur;
//    if (space[0].cur) {
//        space[0].cur = space[i].cur;
//    }
//
//    return i;
//}
//
//int ListLength(StaticLinkList L)
//{
//    int j = 0;
//    int i = L[MAXSIZE - 1].cur;
//    while (i) {
//        i = L[i].cur;
//        j++;
//    }
//    return j;
//}
//
//void Free_SSL(StaticLinkList space, int k)
//{
//    space[k].cur = space[0].cur;
//}
//
////插入
//Status ListInsert(StaticLinkList L,int i , ElemType e)
//{
//    int k = MAXSIZE - 1;
//    if (i < 1 || i > ListLength(L) + 1) {
//        return ERROR;
//    }
//
//    int j = Malloc_SLL(L);//获得空闲分量的下标
//    if (j) {
//        L[j].data = e;
//        for (int l = 1; l <= i - 1; l++) {
//            k = L[k].cur;
//        }
//        L[j].cur = L[k].cur;//第i个元素之前的cur赋值给新元素的cur
//        L[k].cur = j;//把新元素的下标赋值给第i个元素之前的cur
//
//        return OK;
//    }
//
//    return ERROR;
//}
//
////删除
//Status ListDelete(StaticLinkList L, int i)
//{
//    if (i < 1 || i > ListLength(L)) {
//        return ERROR;
//    }
//
//    int k = MAXSIZE - 1;
//    for (int j = 1; j <= i - 1; j++) {
//        k = L[k].cur;
//    }
//    int j = L[k].cur;
//    L[k].cur = L[j].cur;
//    Free_SSL(L, j);
//
//    return OK;
//}
