//
//  SeqStack.c
//  leetcode
//
//  Created by liyoucheng on 2018/8/13.
//  Copyright © 2018年 Liyoucheng. All rights reserved.
//

#include "SeqStack.h"

#include <stdlib.h>
#include <stdbool.h>

//初始化
SeqStack *SeqStackInit()
{
    SeqStack *p;
    if ((p = (SeqStack *)malloc(sizeof(SeqStack)))) {
        p->top = 0;
        return p;
    }
    return NULL;
}

//销毁栈
void SeqStackFree(SeqStack *s)
{
    if (s) {
        free(s);
    }
}

//是否空
int SeqStackIsEmpty(SeqStack *s)
{
    return (s->top == 0);
}

//是否满
int SeqStackIsFull(SeqStack *s)
{
    return (s->top == SIZE);
}

//清空栈
void SeqStackClear(SeqStack *s)
{
    s->top = 0;
}

//入栈
int SeqStackPush(SeqStack *s, DATA data)
{
    if ((s->top + 1) > SIZE) {
        printf("栈溢出\n");
        return 0;
    }
    s->data[++s->top] = data;
    return 1;
}

//出栈
DATA SeqStackPop(SeqStack *s)
{
    if (s->top == 0) {
        printf("栈为空\n");
        exit(0);
    }
    return (s->data[s->top--]);
}

//获取栈顶元素
DATA SeqStackPeek(SeqStack *s)
{
    if (s->top == 0) {
        printf("栈为空\n");
        exit(0);
    }
    return (s->data[s->top]);
}
