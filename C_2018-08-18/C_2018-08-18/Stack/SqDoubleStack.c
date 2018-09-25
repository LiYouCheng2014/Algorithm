//
//  SqDoubleStack.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "SqDoubleStack.h"

typedef int SElemType;
#define MAXSIZE 2000

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

typedef struct
{
    SElemType data[MAXSIZE];
    int top1;
    int top2;
}SqDoubleStack;

//入栈
Status sds_Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
    if (S->top1 + 1 == S->top2) {
        //栈满
        return ERROR;
    }
    
    if (stackNumber == 1) {
        S->data[++S->top1] = e;
    }
    else if (stackNumber == 2) {
        S->data[--S->top2] = e;
    }
    
    return OK;
}

//出栈
Status sds_Pop(SqDoubleStack *S, SElemType *e, int stackNumber)
{
    if (stackNumber == 1) {
        if (S->top1 == -1) {
            return ERROR;//1空栈
        }
        *e = S->data[S->top1--];
    }
    else if (stackNumber == 2) {
        if (S->top2 == MAXSIZE) {
            return ERROR;//2空栈
        }
        *e = S->data[S->top2++];
    }
    
    return OK;
}

