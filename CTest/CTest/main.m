//
//  main.m
//  CTest
//
//  Created by kaisa-ios-001 on 2018/8/16.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#import <Foundation/Foundation.h>


#include <stdio.h>
#include <stdlib.h>

typedef char SElemType;
#define MAXSIZE 100

typedef struct stack
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

void InitStack(SqStack s)
{
    s.base = (SElemType *)malloc(MAXSIZE *sizeof(SElemType));
    if (s.base == NULL) {
        exit(-2);
    }
    s.top = s.base;
    s.stacksize = MAXSIZE;
}

int Pop(SqStack s, SElemType e)
{
    if (s.top == s.base) {
        exit(-2);
    }
    s.top--;
    e = *s.top;
    
    return 1;
}

int Push(SqStack s, SElemType e)
{
    if (s.top - s.base == s.stacksize) {
        exit(-2);
    }
    
    *s.top = e;
    s.top++;
    
    return 1;
}

SElemType GetTop(SqStack s)
{
    if (s.top != s.base) {
        return *(s.top-1);
    }
    
    exit(-2);
}

//括号匹配
int Match(SqStack s, char *p)
{
    int flag = 0;
    while (*p != '\0') {
        if (*p == '(') {
            Push(s, *p);
        }
        else if (*p == ')') {
            if (GetTop(s) == '(') {
                char c = '\0';
                Pop(s, c);
                printf("%c\n",c);
                flag = 1;
            }
            else {
                flag = 2;
            }
        }
        p++;
    }
    if ((flag == 1 || flag == 0) && s.top == s.base) {
        return 1;
    }
    else {
        return 0;
    }
}


void Menu()
{//界面函数
    printf("*********表达式求值(只能包含+、-、*、/、（）和正整数)********* ******\n");
    printf("请选择：1.输入表达式 2.括号匹配检查 3.转换后缀表达式 4.表达式计算5.退出\n");
}


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        SqStack op;
        SqStack st;
        InitStack(op);
        InitStack(st);
        
        char *s1 = "(1+2)*3";
        char *s2 = "(1+2)*3)";
        printf("s1计算结果:%d\n",Match(op, s1));
        printf("s2计算结果:%d\n",Match(op, s2));
        
        
    }
    return 0;
}
