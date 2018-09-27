//
//  Stack.c
//  二叉树
//
//  Created by liyoucheng on 2018/9/25.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "Stack.h"

//创建栈
Stack InitStack(void)
{
    //可能分配失败 内存不足
    Stack stack = (Stack)malloc(sizeof(struct LinkStack));
    if (!stack) {
        printf("分配内存失败\n");
        return NULL;
    }
    stack->top = NULL;
    stack->count = 0;
    return stack;
}

//栈是否空
bool IsEmptyStack(Stack stack)
{
    return stack->top ? 0 : 1;
}

//入栈
void PushStack(Stack stack, ElementType val)
{
    Ptr p = (Ptr)malloc(sizeof(struct Node));
    if (!p) {
        printf("分配内存失败\n");
        exit(-1);
    }
    p->data = val;
    p->next = stack->top;
    stack->top = p;
    stack->count++;
}

//出栈
void PopStack(Stack stack, ElementType *val)
{
    if (!IsEmptyStack(stack)) {
        Ptr p = stack->top;
        *val = p->data;
        stack->top = p->next;
        stack->count--;
        free(p);
    }
}
