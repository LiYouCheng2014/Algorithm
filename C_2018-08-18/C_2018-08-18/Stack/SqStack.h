//
//  SqStack.h
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef SqStack_h
#define SqStack_h

#include <stdio.h>

typedef char SElemType;
#define MAXSIZE 2000

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

typedef struct
{
    SElemType data[MAXSIZE + 1];
    int top;
}SqStack;

//初始化
SqStack *ss_StackInit(void);

//销毁栈
void ss_StackFree(SqStack *S);

//是否空
int ss_StackEmpty(SqStack *S);

//是否满
int ss_StackIsFull(SqStack *S);

//清空栈
void ss_StackClear(SqStack *S);

//入栈
Status ss_Push(SqStack *S, SElemType e);

//出栈
Status ss_Pop(SqStack *S, SElemType *e);

//获取栈顶元素
SElemType ss_GetTop(SqStack *S);

#endif /* SqStack_h */
