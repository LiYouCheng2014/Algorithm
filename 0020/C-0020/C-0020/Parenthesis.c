//
//  Parenthesis.c
//  C-0020
//
//  Created by LiYouCheng on 2018/6/26.
//  Copyright © 2018年 Liyoucheng. All rights reserved.
//

#include "Parenthesis.h"

#include <stdlib.h>
#include <string.h>


#define STACK_INIT_SIZE 100 //栈的初始大小
#define SIZE_INCREMENT 5 //栈的增量

//上顶
//下底
typedef struct
{
    int *base;//栈底
    int *top;//栈顶
    int stacksize;//栈大小
}SqStack,*SQSQTACK;

//初始化栈
int StackInit(SQSQTACK s)
{
    s->base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
    if (!(s->base)) {
        exit(0);
    }
    
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
    
    return 1;
}

//入栈
int PUSH(SQSQTACK s, int e)
{
    if (s->base+s->stacksize == s->top) {
        //满了，增加一定内存空间
        s->base = (int *)realloc(s->base,(SIZE_INCREMENT+s->stacksize)*sizeof(int));
        s->top = s->base+s->stacksize;
        s->stacksize += SIZE_INCREMENT;
    }
    
    *(s->top) = e;
    s->top += 1;
    return 1;
}

//出栈
int POP(SQSQTACK s, int *p)
{
    if (s->base == s->top) {
        return 0;
    }
    
    *p = *(s->top - 1);
    s->top--;
    return 1;
}

//获取栈顶元素位置
int GET(SQSQTACK s)
{
    return (int)(s->top - s->base);
}

//栈长度
int StackLength(SQSQTACK s)
{
    return (int)(s->top - s->base);
}

//释放栈
int StackFree(SQSQTACK s)
{
    free(s->base);
    s->top = s->base = NULL;
    return 1;
}

//括号匹配
int ParenthesisMatch(char *expr)
{
    SqStack s;
    int no;
    //初始化栈失败就退出
    if (!StackInit(&s)) {
        exit(0);
    }
    
    int result = 1;
    int len = (int)strlen(expr);
    for (int i = 1; i <= len; i++) {
        if (expr[i-1] == '(') {
            //左括号(位置序号入栈
            PUSH(&s, i);
        }
        else if (expr[i-1] == '[') {
            //左括号[位置序号入栈
            PUSH(&s, i);
        }
        else if (expr[i-1] == '{') {
            //左括号{位置序号入栈
            PUSH(&s, i);
        }
        else {
            if (expr[i-1] == ')') {
                //右括号出栈 & no位置的括号是(
                if (POP(&s, &no) && expr[no-1] == '(') {
                    printf("()括号配对:%d--%d\n",no,i);
                }
                else {
                    result = 0;
                    printf("()没有左括号与位于第%d个位置的右括号配对\n",i);
                }
            }
            else if (expr[i-1] == ']') {
                //右括号出栈 & no位置的括号是[
                if (POP(&s, &no) && expr[no-1] == '[') {
                    printf("[]括号配对:%d--%d\n",no,i);
                }
                else {
                    result = 0;
                    printf("[]没有左括号与位于第%d个位置的右括号配对\n",i);
                }
            }
            else if (expr[i-1] == '}') {
                //右括号出栈 & no位置的括号是{
                if (POP(&s, &no) && expr[no-1] == '{') {
                    printf("{}括号配对:%d--%d\n",no,i);
                }
                else {
                    result = 0;
                    printf("{}没有左括号与位于第%d个位置的右括号配对\n",i);
                }
            }
            else {
                printf("不是括号\n");
            }
        }
    }
    
    if (StackLength(&s) == 0 && result == 1) {
        result = 1;
    }
    else {
        result = 0;
    }
    
    //若栈还有数据，表示左括号没有配对
    while (StackLength(&s) > 0) {
        POP(&s, &no);
        printf("没有左括号与位于第%d个位置的右括号配对\n",no);
    }
    
    //释放栈
    StackFree(&s);
    
    return result;
}
