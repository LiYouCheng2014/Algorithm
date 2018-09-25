//
//  Stack.c
//  二叉树
//
//  Created by liyoucheng on 2018/9/25.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "Stack.h"
#include <stdlib.h>

Stack createStack()
{
    //可能分配失败 内存不足
    Stack s = (Stack)malloc(sizeof(struct LinkStack));
    s->top = NULL;
    s->count = 0;
    return s;
}

void clearStack(Stack s)
{
    StackPtr p;
    while (s->top) {
        p = s->top;
        s->top = s->top->next;
        s->count--;
        free(p);
    }
}

void destroyStack(Stack s)
{
    clearStack(s);
    free(s);
}

int isEmpty(Stack s)
{
    return s->top ? 0 : 1;
}

void getTop(Stack s, ElemType *item)
{
    if (!isEmpty(s)) {
        *item = s->top->data;
    }
}

void push(Stack s, ElemType item)
{
    StackPtr p = (StackPtr)malloc(sizeof(struct StackNode));
    p->data = item;
    p->next = s->top;
    s->top = p;
    s->count++;
}

void pop(Stack s, ElemType *item)
{
    if (!isEmpty(s)) {
        StackPtr p = s->top;
        *item = p->data;
        s->top = p->next;
        s->count--;
        free(p);
    }
}

int length(Stack s)
{
    return s->count;
}

void stackTraverse(Stack s)
{
    StackPtr p = s->top;
    while (p) {
//        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

void test()
{
//    printf("初始化栈并将1-10入栈\n");
//    Stack s = createStack();
//    for (int i = 1; i < 11; i++) {
//        push(s, i);
//    }
//
//    printf("栈中元素从栈顶依次为:\n");
//    stackTraverse(s);
//
//    printf("栈长度:%d\n",length(s));
//
//    ElemType e;
//    pop(s, &e);
//    printf("第一次弹出的元素为:%d\n",e);
//
//    pop(s, &e);
//    printf("第二次弹出的元素为:%d\n",e);
//
//    printf("栈是否空:%d(1:是，0:不是)\n",isEmpty(s));
//
//    getTop(s, &e);
//    printf("当前栈顶的元素为:%d\n",e);
//
//    clearStack(s);
//    printf("栈清空后，是否空:%d(1:是，0:不是)\n",isEmpty(s));
//
//    destroyStack(s);
//    printf("栈销毁\n");
}

