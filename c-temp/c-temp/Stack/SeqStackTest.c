//
//  SeqStack.c
//  c-temp
//
//  Created by liyoucheng on 2018/7/25.
//  Copyright © 2018年 liyoucheng. All rights reserved.
//

#include "SeqStackTest.h"

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef int ElemType;

////顺序栈
//typedef struct
//{
//    ElemType data[MAXSIZE];
//    int top;//栈顶
//}SqStack;
//
////入栈
//Status Push(SqStack *S, ElemType e)
//{
//    if (S->top == MAXSIZE - 1) {
//        return ERROR;//栈满
//    }
//    S->top++;
//    S->data[S->top] = e;
//    
//    return OK;
//}
//
////出栈
//Status Pop(SqStack *S, ElemType *e)
//{
//    if (S->top == - 1) {
//        return ERROR;//栈满
//    }
//    *e = S->data[S->top];
//    S->top--;
//    
//    return OK;
//}

