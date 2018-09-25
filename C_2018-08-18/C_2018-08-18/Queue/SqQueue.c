//
//  SqQueue.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/19.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "SqQueue.h"

//队初始化
sq_Status sq_InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    
    return OK;
}

//队长
int sq_QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

//入队
sq_Status sq_EnQueue(SqQueue *Q, sq_ElemType e)
{
    //队满
    if ((Q->rear + 1) % MAXSIZE == Q->front) {
        return ERROR;
    }
    
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    
    return OK;
}

//出队
sq_Status sq_DeQueue(SqQueue *Q, sq_ElemType *e)
{
    //队空
    if (Q->front == Q->rear) {
        return ERROR;
    }
    
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    
    return OK;
}
