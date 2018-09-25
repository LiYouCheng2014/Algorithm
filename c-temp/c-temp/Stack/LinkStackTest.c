//
//  LinkStackTest.c
//  c-temp
//
//  Created by liyoucheng on 2018/7/25.
//  Copyright © 2018年 liyoucheng. All rights reserved.
//

#include "LinkStackTest.h"

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef int ElemType;
//
//typedef struct StackNode
//{
//    ElemType data;
//    struct StackNode *next;
//} StackNode, *LinkStackPtr;
//
////链栈
//typedef struct LinkStack
//{
//    LinkStackPtr top;
//    int count;
//}LinkStack;
//
//
////入栈
//Status Push(LinkStack *S, ElemType e)
//{
//    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
//    s->data = e;
//    s->next = S->top;
//    S->top = s;
//    S->count++;
//    
//    return OK;
//}
//
//int StackEmpty(LinkStack S)
//{
//    return 1;
//}
//
////出栈
//Status Pop(LinkStack *S, ElemType *e)
//{
//    LinkStackPtr p;
//    if (StackEmpty(*S)) {
//        return  ERROR;
//    }
//    
//    *e = S->top->data;
//    p = S->top;
//    
//    S->top = S->top->next;
//    free(p);
//    S->count--;
//    
//    
//    return OK;
//}
