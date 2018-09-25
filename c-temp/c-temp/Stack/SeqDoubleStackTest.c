//
//  SeqDoubleStackTest.c
//  c-temp
//
//  Created by liyoucheng on 2018/7/25.
//  Copyright © 2018年 liyoucheng. All rights reserved.
//

#include "SeqDoubleStackTest.h"

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef int ElemType;

//
////共享栈， 相同数据类型
//
////顺序栈
//typedef struct
//{
//    ElemType data[MAXSIZE];
//    int top1;//栈顶1
//    int top2;//栈顶1
//}SqDoubleStack;
//
////入栈
//Status Push(SqDoubleStack *S, ElemType e, int stackNumber)
//{
//    if (S->top1 + 1 == S->top2) {
//        return ERROR;//栈满
//    }
//    
//    if (stackNumber == 1) {
//        S->data[++S->top1] = e;
//    }
//    else if (stackNumber == 2) {
//        S->data[--S->top2] = e;
//    }
//
//    return OK;
//}
//
////出栈
//Status Pop(SqDoubleStack *S, ElemType *e, int stackNumber)
//{
//    if (stackNumber == 1) {
//        if (S->top1 == - 1) {
//            return ERROR;
//        }
//        *e = S->data[S->top1--];
//    }
//    else if (stackNumber == 2) {
//        if (S->top2 == MAXSIZE) {
//            return ERROR;
//        }
//        *e = S->data[S->top2++];
//    }
//
//    return OK;
//}
