//
//  SqList.c
//  leetcode
//
//  Created by kaisa-ios-001 on 2018/8/18.
//  Copyright © 2018年 Liyoucheng. All rights reserved.
//

#include "SqList.h"

#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SqList;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
