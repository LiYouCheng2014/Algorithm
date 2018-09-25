//
//  stack.h
//  leetcode
//
//  Created by liyoucheng on 2018/8/12.
//  Copyright © 2018年 Liyoucheng. All rights reserved.
//

#ifndef stack_h
#define stack_h

#define maxsize 10

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;

//struct stack
//{
//    datatype *data;
//    int top;
//};
//
//typedef struct stack Stack;
//
//void init(Stack *s);
//
//bool Empty(Stack *s);
//
//void Full(Stack *s);
//
//void Push(Stack *s,datatype element);
//
//void Pop(Stack *s);
//
//datatype Top(Stack *s);
//
//void Destroy(Stack *s);

//#include <stdio.h>
//#include <stdlib.h>
//
//#define OK 1
//#define OVERFLOW -2
//#define ERROR 0
//
//#define STACK_INIT_SIZE 100
//#define STACKINCREMENT 10
//
////栈的顺序存储结构
//typedef int SElemType;
//
//typedef struct
//{
//    SElemType *base;//构造之前和销毁后值是NULL 栈底
//    SElemType *top;//栈顶
//    int stacksize;//已分配的存储空间
//}SqStack;
//
////初始化
//int InitStack(SqStack *S);
////进栈
//int Push(SqStack *S, int e);
////出栈
//int Pop(SqStack *S, int *e);
////取出栈顶元素
//void GetElem(SqStack *S, int *e);
////打印出栈的各个元素
//void PrintfStack(SqStack *S);
#endif /* stack_h */
