//
//  SeqStack.h
//  leetcode
//
//  Created by liyoucheng on 2018/8/13.
//  Copyright © 2018年 Liyoucheng. All rights reserved.
//

#ifndef SeqStack_h
#define SeqStack_h

#include <stdio.h>

#include "CalcExp.h"

typedef struct SqStack
{
    //为符合日常习惯 从1开始
    DATA data[SIZE + 1];
    //top=0栈空,top=size 栈满
    int top;
    
}SeqStack;

//初始化
SeqStack *SeqStackInit(void);

//销毁栈
void SeqStackFree(SeqStack *s);

//是否空
int SeqStackIsEmpty(SeqStack *s);

//是否满
int SeqStackIsFull(SeqStack *s);

//清空栈
void SeqStackClear(SeqStack *s);

//入栈
int SeqStackPush(SeqStack *s, DATA data);

//出栈
DATA SeqStackPop(SeqStack *s);

//获取栈顶元素
DATA SeqStackPeek(SeqStack *s);

#endif /* SeqStack_h */
