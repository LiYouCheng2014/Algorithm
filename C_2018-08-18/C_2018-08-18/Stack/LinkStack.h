//
//  LinkStack.h
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef LinkStack_h
#define LinkStack_h

#include <stdio.h>

typedef int LSElemType;
typedef int LStatus;

typedef struct StackNode
{
    LSElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;//栈顶
    int count;
}LinkStack;

//初始化
LinkStack *ls_StackInit(void);

//入栈
LStatus ls_Push(LinkStack *S, LSElemType e);

//是否为空
LStatus ls_StackEmpty(LinkStack S);

//出栈
LStatus ls_Pop(LinkStack *S, LSElemType *e);

#endif /* LinkStack_h */
