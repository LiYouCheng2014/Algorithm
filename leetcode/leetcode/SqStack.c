//
//  SqStack.c
//  leetcode
//
//  Created by liyoucheng on 2018/8/15.
//  Copyright © 2018年 Liyoucheng. All rights reserved.
//

#include "SqStack.h"

//#include <stdlib.h>
//
//#define STACK_INIT_SIZE 20
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//
//typedef int Status;
//
//Status InitStack(SqStack *S)
//{
//    S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
//    if (!S->base) {
//        return ERROR;
//    }
//    S->top = S->base;
//    S->StackSize = STACK_INIT_SIZE;
//
//    return OK;
//}
//
//Status TPush(SqStack *S,SElemType e)
//{
//    if (S->top - S->base >= S->StackSize) {
//        S->base = (SElemType *)realloc(S->base, (S->StackSize + STACK_INIT_SIZE) * sizeof(SElemType));
//        if (!S->base) {
//            return ERROR;
//        }
//        S->top = S->base + STACK_INIT_SIZE;
//        S->StackSize += STACK_INIT_SIZE;
//    }
//
//    *S->top++ = e;
//    return OK;
//}
//
//Status TGetTop(SqStack *S,SElemType *e)
//{
//    if (S->top == S->base) {
//        return ERROR;
//    }
//    *e = *(S->top - 1);
//
//    return OK;
//}
//
//int StackLength(SqStack *S)
//{
//    int length;
//    length = (int)(S->top - S->base);
//    return length;
//
//}
//
//Status TPop(SqStack *S,SElemType *e)
//{
//    if (S->top == S->base) {
//        return ERROR;
//    }
//
//    *e = *--S->top;
//
//    return OK;
//}
//
//Status ClearStack(SqStack *S)
//{
//    S->top = S->base;
//    return OK;
//}
