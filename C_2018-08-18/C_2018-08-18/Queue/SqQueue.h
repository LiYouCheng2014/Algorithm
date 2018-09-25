//
//  SqQueue.h
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/19.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef SqQueue_h
#define SqQueue_h

#include <stdio.h>

typedef char sq_ElemType;
#define MAXSIZE 2000

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int sq_Status;

typedef struct
{
    sq_ElemType data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

#endif /* SqQueue_h */
