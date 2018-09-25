//
//  stack.c
//  leetcode
//
//  Created by liyoucheng on 2018/8/12.
//  Copyright © 2018年 Liyoucheng. All rights reserved.
//

#include "stack.h"

//int realsize = maxsize;
//
//void init(Stack *s)
//{
//    s->data = (datatype *)malloc(sizeof(datatype) * maxsize);
//    s->top = -1;
//}
//
//bool Empty(Stack *s)
//{
//    if (s->top == -1) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}
//
//void Full(Stack *s)
//{
//    if (s->top == realsize - 1) {
//        realsize++;
//        s->data = (datatype *)realloc(s->data, realsize * sizeof(datatype));
//    }
//}
//
//void Push(Stack *s,datatype element)
//{
//    Full(s);
//    s->top++;
//    s->data[s->top] = element;
//}
//
//void Pop(Stack *s)
//{
//    if (!Empty(s)) {
//        s->top--;
//    }
//    else {
//        printf("栈空\n");
//    }
//}
//
//datatype Top(Stack *s)
//{
//    if (!Empty(s)) {
//        return s->data[s->top];
//    }
//    else {
//        printf("栈空\n");
//        return -1;
//    }
//}
//
//void Destroy(Stack *s)
//{
//    s->top = -1;
//    free(s->data);
//}

////表尾（栈顶）进行插入和删除的线性表 后进先出LIFO
////插入、删除、初始化、取栈顶元素、判断是否为空
//
//
//
////初始化
//int InitStack(SqStack *S)
//{
//    S->base = (int *)malloc(STACK_INIT_SIZE * sizeof(SqStack));
//    if (!S->base) {
//        exit(OVERFLOW);//分配空间失败
//    }
//    S->top = S->base;
//    S->stacksize = STACK_INIT_SIZE;
//
//    return OK;
//}
//
////进栈
//int Push(SqStack *S, int e)
//{
//    if (S->top - S->base >= S->stacksize) {
//        S->base = (int *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SqStack));
//        if (!S->base) {
//            exit(OVERFLOW);//分配失败
//        }
//        S->top = S->base + S->stacksize;
//        S->stacksize += STACKINCREMENT;
//    }
//    *S->top++ = e;
//    return OK;
//}
//
////出栈
//int Pop(SqStack *S, int *e)
//{
//    if (S->top != S->base) {
//        *e = *--S->top;
//        return OK;
//    }
//    else {
//        exit(OVERFLOW);
//    }
//}
//
////取出栈顶元素
//void GetElem(SqStack *S, int *e)
//{
//    if (S->top != S->base) {
//        *e = *(S->top - 1);
//    }
//    else {
//        exit(OVERFLOW);
//    }
//}
//
////打印出栈的各个元素
//void PrintfStack(SqStack *S)
//{
//    while(*(S->top-1) && S->top != S->base){//证明不是空栈,且有值
//        S->top = S->top - 1;
//        printf("%d ",*S->top);
//    }
//    printf("\n");
//}
