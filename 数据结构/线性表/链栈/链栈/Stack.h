//
//  Stack.h
//  链栈
//
//  Created by liyoucheng on 2018/9/26.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;

//结点
struct Node{
    ElementType data;
    struct Node *next;
};
typedef struct Node *Ptr;

//栈结构
struct LinkStack {
    Ptr top;//栈顶
    int count;
};
typedef struct LinkStack *Stack;

//创建栈
Stack InitStack(void);
//栈是否空
bool IsEmptyStack(Stack stack);
//入栈
void PushStack(Stack stack, ElementType val);
//出栈
void PopStack(Stack stack, ElementType *val);
//销毁栈
void DestroyStack(Stack stack);
//遍历栈
void TraverseStack(Stack stack);
//清空栈
void ClearStack(Stack stack);
//栈长度
int LengthStack(Stack stack);
//获取栈顶元素
void GetTop(Stack stack, ElementType *val);
//栈测试
void test(void);


#endif /* Stack_h */
