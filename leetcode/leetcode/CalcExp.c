//
//  CalcExp.c
//  leetcode
//
//  Created by liyoucheng on 2018/8/14.
//  Copyright © 2018年 Liyoucheng. All rights reserved.
//

#include "CalcExp.h"

#include "SeqStack.h"

int IsOperator(char c)
{
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case '=':
            return 1;
            break;
        default:
            return 0;
            break;
    }
}

int PRI(char oper1, char oper2)
{
    int pri;
    switch (oper2) {
        case '+':
        case '-':
            if (oper1 == '(' || oper1 == '=') {
                pri = -1;
            }
            else {
                pri = 1;
            }
            break;
        case '*':
        case '/':
            if (oper1 == '*' || oper1 == '/' || oper1 == ')') {
                pri = 1;
            }
            else {
                pri = -1;
            }
            break;
        case '(':
            if (oper1 == ')') {
                printf("语法错误\n");
                exit(0);
            }
            else {
                pri = -1;
            }
            break;
        case ')':
            if (oper1 == '(') {
                pri = 0;
            }
            else if (oper1 == '=') {
                printf("括号不匹配\n");
                exit(0);
            }
            else {
                pri = 1;
            }
            break;
        case '=':
            if (oper1 == '(') {
                printf("括号不匹配\n");
                exit(0);
            }
            else if (oper1 == '=')
            {
                pri = 0;
            }
            else {
                pri = 1;
            }
            break;
    }
    return pri;
}

int Calc(int a, int oper, int b)
{
    switch (oper) {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            if (b != 0) {
                return a/b;
            }
            else {
                printf("除以0退出\n");
                exit(0);
            }
    }
    
    return 0;
}

int CalcExp(char exp[])
{
    SeqStack *StackOper;
    SeqStack *StackData;
    int i = 0;
    int flag = 0;//处理多位数
    
    DATA a,b,c,q,x,t,oper;
    
    StackOper = SeqStackInit();
    StackData = SeqStackInit();

    q = 0;
    x = '=';
    
    SeqStackPush(StackOper, x);
    
    c = exp[i++];
    while (c != '=' || x != '=') {
        if (IsOperator(c)) {
            if (flag) {
                //操作数未入栈
                SeqStackPush(StackData, q);
                q = 0;//操作数清0
                flag = 0;//已入栈
            }
            
            switch (PRI(x, c)) {
                case -1:
                    SeqStackPush(StackOper, c);//运算符入栈
                    c = exp[i++];
                    break;
                case 0:
                    SeqStackPop(StackOper);//运算符出栈
                    c = exp[i++];
                    break;
                case 1:
                    oper = SeqStackPop(StackOper);//运算符出栈
                    b = SeqStackPop(StackData);
                    a = SeqStackPop(StackData);
                    t = Calc(a, oper, b);
                    SeqStackPush(StackData, t);//运算结果入栈
                    break;
            }
        }
        else if (c >= '0' && c <= '9')
        {
            c -= '0';
            q = q * 10 + c;
            flag = 1;
            c = exp[i++];
        }
        else {
            printf("输入错误\n");
            getchar();
            exit(0);
        }
        x = SeqStackPeek(StackOper);
    }
    
    q = SeqStackPop(StackData);
    SeqStackFree(StackOper);
    SeqStackFree(StackData);
    
    return q;
}

//char exp[80];
//printf("请输入要计算的表达式以=结束\n");
//scanf("%s",exp);
//printf("%s%d\n",exp,CalcExp(exp));
//getchar();

