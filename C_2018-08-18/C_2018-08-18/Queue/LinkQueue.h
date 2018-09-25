//
//  LinkQueue.h
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/19.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef LinkQueue_h
#define LinkQueue_h

#include <stdio.h>

typedef char lq_ElemType;
#define MAXSIZE 2000

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int lq_Status;

typedef struct QNode
{
    lq_ElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
    int count;
}LinkQueue;

#endif /* LinkQueue_h */
