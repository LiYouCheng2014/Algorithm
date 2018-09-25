//
//  LinkStack.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "LinkStack.h"

#include <stdlib.h>


#define MAXSIZE 2000

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0



//初始化
LinkStack *ls_StackInit()
{
    LinkStack *p;
    if ((p = (LinkStack *)malloc(sizeof(StackNode)))) {
        return p;
    }
    
    return NULL;
}

//入栈
LStatus ls_Push(LinkStack *S, LSElemType e)
{
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top;//栈顶元素赋值给新结点的直接后继
    S->top = s;
    S->count++;
    
    return OK;
}

//是否为空
LStatus ls_StackEmpty(LinkStack S)
{
    return S.count == 0 ? 1 : 0;
}

//出栈
LStatus ls_Pop(LinkStack *S, LSElemType *e)
{
    if (ls_StackEmpty(*S)) {
        return ERROR;
    }
    
    *e = S->top->data;
    LinkStackPtr p = S->top;
    S->top = S->top->next;
    free(p);
    
    S->count--;
    
    return OK;
}
