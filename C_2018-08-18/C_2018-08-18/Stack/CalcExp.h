//
//  CalcExp.h
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/19.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef CalcExp_h
#define CalcExp_h

#include <stdio.h>

//获取中缀表达式
void getInfixExpression(char str[]);
//中缀表达式转换为后缀表达式
void InfixExpressionToSuffixExpression(char infixExpression[],char suffixExpression[]);
//后缀表达式求值
void calculateSuffixExpression(char suffixExpression[]);

#endif /* CalcExp_h */
