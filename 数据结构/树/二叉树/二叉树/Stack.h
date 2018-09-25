//
//  Stack.h
//  二叉树
//
//  Created by liyoucheng on 2018/9/25.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>

//

//树结构
typedef int ElementType;
typedef struct TreeNode *Position;
typedef Position BinTree;

//二叉树
struct TreeNode {
    ElementType data;
    BinTree left;
    BinTree right;
};

//堆
typedef BinTree ElemType;

struct StackNode{
    ElemType data;
    struct StackNode *next;
};
typedef struct StackNode *StackPtr;

struct LinkStack {
    StackPtr top;
    int count;
};
typedef struct LinkStack *Stack;

Stack createStack(void);

void clearStack(Stack s);

void destroyStack(Stack s);

int isEmpty(Stack s);

void getTop(Stack s, ElemType *item);

void push(Stack s, ElemType item);

void pop(Stack s, ElemType *item);

int length(Stack s);

void stackTraverse(Stack s);

void test(void);

#endif /* Stack_h */
