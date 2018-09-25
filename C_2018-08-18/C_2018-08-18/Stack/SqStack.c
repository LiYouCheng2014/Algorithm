//
//  SqStack.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "SqStack.h"

#include <stdlib.h>

//初始化
SqStack *ss_StackInit()
{
    SqStack *p;
    if ((p = (SqStack *)malloc(sizeof(SqStack)))) {
        p->top = 0;
        return p;
    }
    
    return NULL;
}

//销毁栈
void ss_StackFree(SqStack *S)
{
    if (S) {
        free(S);
    }
}

//是否空
int ss_StackEmpty(SqStack *S)
{
    return (S->top == 0);
}

//是否满
int ss_StackIsFull(SqStack *S)
{
    return (S->top == MAXSIZE);
}

//清空栈
void ss_StackClear(SqStack *S)
{
    S->top = 0;
}

//入栈
Status ss_Push(SqStack *S, SElemType e)
{
    if (S->top + 1 == MAXSIZE) {
        //栈满
        return ERROR;
    }
    
    S->data[++S->top] = e;
    
    return OK;
}

//出栈
Status ss_Pop(SqStack *S, SElemType *e)
{
    if (S->top == 0) {
        //栈空
        return ERROR;
    }
    
    *e = S->data[S->top--];
    
    return OK;
}

//获取栈顶元素
SElemType ss_GetTop(SqStack *S)
{
    if (S->top == 0) {
        return 0;
    }
    
    return (S->data[S->top]);
}
