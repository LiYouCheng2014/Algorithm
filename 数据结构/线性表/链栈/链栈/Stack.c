//
//  Stack.c
//  链栈
//
//  Created by liyoucheng on 2018/9/26.
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

//销毁栈
void DestroyStack(Stack stack)
{
    ClearStack(stack);
    free(stack);
}

//遍历栈
void TraverseStack(Stack stack)
{
    Ptr p = stack->top;
    while (p) {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

//清空栈
void ClearStack(Stack stack)
{
    Ptr p;
    while (stack->top) {
        p = stack->top;
        stack->top = p->next;
        stack->count--;
        free(p);
    }
}

//栈长度
int LengthStack(Stack stack)
{
    return stack->count;
}

//获取栈顶元素
void GetTop(Stack stack, ElementType *val)
{
    if (!IsEmptyStack(stack)) {
        *val = stack->top->data;
    }
}

//栈测试
void test(void)
{
    printf("初始化栈并将1-10入栈\n");
    Stack s = InitStack();
    for (int i = 1; i < 11; i++) {
        PushStack(s, i);
    }

    printf("栈中元素从栈顶依次为:\n");
    TraverseStack(s);

    printf("栈长度:%d\n",LengthStack(s));

    ElementType e;
    PopStack(s, &e);
    printf("第一次弹出的元素为:%d\n",e);

    PopStack(s, &e);
    printf("第二次弹出的元素为:%d\n",e);

    printf("栈是否空:%d(1:是，0:不是)\n",IsEmptyStack(s));

    GetTop(s, &e);
    printf("当前栈顶的元素为:%d\n",e);

    ClearStack(s);
    printf("栈清空后，是否空:%d(1:是，0:不是)\n",IsEmptyStack(s));

    DestroyStack(s);
    printf("栈销毁\n");
}
