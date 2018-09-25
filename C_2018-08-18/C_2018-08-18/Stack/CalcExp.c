//
//  CalcExp.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/19.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "CalcExp.h"

#include <stdlib.h>
#include <string.h>

#include "SqStack.h"
#include "LinkStack.h"

/*
 逆波兰（后缀表达式）RPN
 中缀表达式转后缀表达式（栈用来存放运算符号）
 
 从左到右遍历中缀表达式中的每个数字和符号，若是数字就输出，成为后缀表达式的一部分；若是符号，则判断其与栈顶符号的优先级，如果是有括号或者该符号低于栈顶符号(乘除优先加减)，则栈顶元素依此出栈并输出，并将该符号进栈，一直到最后得到后缀表达式。
 
 后缀表达式求值（栈用来存放运算数）
 
 从左到右遍历表达式的每个数字和符号，遇到数字就进栈，遇到符号，就将处于栈顶两个数字出栈，运算后结果进栈，一直到得出结果。
 */

struct optrNode {
    char optr;//运算符
    int level;//优先级越高，值越大
};

SqStack *optrStack;
LinkStack *opndStack;

//运算符优先级表,{运算符，级别，运算符，级别~~ }
struct optrNode optrTable[7] = {
    '(',5,
    ')',5,
    '*',4,
    '/',4,
    '+',2,
    '-',2,
    '#',0
};

//获取中缀表达式
void getInfixExpression(char str[])
{
    int len;
    while (1) {
        printf("请输入中缀表达式，以#结束\n");
        fflush(stdin);
        gets(str);
        len = (int)strlen(str);
        
        if (str[0] == '#') {
            printf("不要以#开头，请重新输入!\n");
            continue;
        }
        
        if (str[len - 1] != '#') {
            printf("表达式必须以#结束,请重新输入!\n");
            continue;
        }
        break;
    }
    return;
}

//运算符优先级别比较, a>b,返回1, a==b,返回0, a<b,返回-1
int optrCompare(char optrA,char optrB)
{
    int i,levelA = 0,levelB = 0;
    for(i=0;i<7;i++)//总共7个运算符,查找optrA的优先级别
    {
        if(optrTable[i].optr==optrA)
        {
            levelA=optrTable[i].level;
            break;
        }
    }
    for(i=0;i<7;i++)//总共7个运算符,查找optrB的优先级别
    {
        if(optrTable[i].optr==optrB)
        {
            levelB=optrTable[i].level;
            break;
        }
    }
    if(levelA>levelB)
        return 1;
    else if(levelA==levelB)
        return 0;
    else
        return -1;
}

//将数字符与数值n合并转换为整数并返回
int charCombineToInt(int n,char c)
{
    int v;
    v=c-48;//将数字字符转换为数值
    n=n*10+v;//接接到n中
    return n;//返回
}

//中缀表达式转换为后缀表达式
void InfixExpressionToSuffixExpression(char infixExpression[],char suffixExpression[])
{
    char ch,optr;
    
    optrStack = ss_StackInit();//初始化栈

    int i = 0;
    int si = 0;//后缀表达式下标
    int j = 0;
    
    while((ch=infixExpression[i])!='\0')//未处理完循环
    {
        if (ch >= '0' && ch <= '9') {
            j = i + 1;
            suffixExpression[si] = ch;//结果
            si++;
            while(infixExpression[j] >= '0' && infixExpression[j] <= '9')  //先把数字放在前面
            {
                suffixExpression[si] = infixExpression[j];
                j++;//继续判断下一字符
                i++;//标识当前字符已处理完
                si++;
            }
            suffixExpression[si] = 32;//以空格隔开
            i++;//继续处理下一个字符
            si++;

        }
        else {
            if (ss_StackEmpty(optrStack)) {
                if (infixExpression[i] == '#') {
                    break;
                }
                else {
                    ss_Push(optrStack, ch);//运算符入栈
                    i++;//继续处理下一个字符
                }
            }
            else {
                char topOptr = ss_GetTop(optrStack);
                if(topOptr == '#' && ch == '#')//#匹配，转换结束
                {
                    break;//转换结束
                }
                else if(topOptr != '#' && ch == '#')//当前运算符是#，栈顶运算符不是'#'
                {
                    ss_Pop(optrStack, &optr);//运算符出栈
                    suffixExpression[si] = optr;
                    si++;
                    suffixExpression[si] = 32;//空格
                    si++;
                }
                else if(ch == ')' && topOptr != '(')//当前运算符是右括号')',且栈顶运算符不是左括号'('
                {
                    ss_Pop(optrStack, &optr);//运算符出栈
                    suffixExpression[si] = optr;
                    si++;
                    suffixExpression[si] = 32;//空格
                    si++;
                }
                else if(topOptr == '(' && ch != ')')//如果栈顶运算符是左括号'('且当前运算符不是右括号')'，则运算符入栈
                {
                    ss_Push(optrStack, ch);//运算符入栈
                    i++;//继续处理下一个字符
                }
                else if(topOptr == '(' && ch == ')')//如果栈顶运算符是左括号'('且当前运算符是右括号')'，则运算符出栈，继续处理一下字符
                {
                    ss_Pop(optrStack, &optr);//运算符出栈
                    i++;//继续处理下一个字符
                }
                else if(optrCompare(ch,topOptr) == 1)//当前运算符比栈顶运算符优先级别高
                {
                    ss_Push(optrStack, ch);//运算符入栈
                    i++;//继续处理下一个字符
                }
                else if(optrCompare(ch,topOptr) == -1)//当前运算符比栈顶运算符优先级别低
                {
                    ss_Pop(optrStack, &optr);//运算符出栈
                    suffixExpression[si] = optr;
                    si++;
                    suffixExpression[si] = 32;//空格
                    si++;
                }
                else if(optrCompare(ch,topOptr) == 0)//运算符优先级别相等,从左到右按先后次序计算
                {
                    ss_Pop(optrStack, &optr);//运算符出栈
                    suffixExpression[si] = optr;
                    si++;
                    suffixExpression[si] = 32;//空格
                    si++;
                }

            }
        }
    }
    suffixExpression[si]='\0';//表达式结束
    return;
}


//opnd出栈两个运算对象，执行optr运算，结果入opnd栈
void calculate(char optr)
{
    int a,b,result = 0;
    ls_Pop(opndStack, &a);//出栈一个运算对象
    ls_Pop(opndStack, &b);//再出栈一个运算对象
    switch(optr)
    {
        case '*': result=a*b; break;
        case '/': result=b/a; break;
        case '+': result=a+b; break;
        case '-': result=b-a; break;
    }
    ls_Push(opndStack, result);//运算结果入栈
    return;
}


//后缀表达式求值
void calculateSuffixExpression(char suffixExpression[])
{
    int i,j,ret,value;
    char ch;
    opndStack = ls_StackInit();//初始化栈
    i=0;
    while((ch=suffixExpression[i])!='\0')//逐一处理表达式的每个字符
    {
        if(ch>='0' && ch<='9')//是数字字符
        {
            j=i+1;
            value=ch-48;
            while(suffixExpression[j]>='0' && suffixExpression[j]<='9')
            {
                value=charCombineToInt(value,suffixExpression[j]);
                j++;//继续判断下一字符
                i++;//标识当前字符已处理完
            }
            ls_Push(opndStack, (value));//运算对象入栈;
            i++;//继续处理下一个字符
        }
        else if(ch==32)//是空格，忽略
            i++;
        else//是运算符，从opndStack出栈两个运算对象，执行运算并将结果入栈
        {
            calculate(ch);
            i++;
        }
    }//逐一处理表达式的每个字符
    ret=ls_Pop(opndStack, &value);//运算结果出栈
    printf("%d\n",value);
    return;
}






