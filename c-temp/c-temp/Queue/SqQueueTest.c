//
//  SqQueueTest.c
//  c-temp
//
//  Created by liyoucheng on 2018/7/26.
//  Copyright © 2018年 liyoucheng. All rights reserved.
//

#include "SqQueueTest.h"

//#define MAXSIZE 20
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//
//typedef int Status;
//
//typedef int ElemType;
//
////循环队列
//typedef struct
//{
//    ElemType data[MAXSIZE];
//    int front;//头指针
//    int rear;//尾指针,若队列不空，指向队列尾元素的下一个位置
//}SqQueue;
//
//Status InitQueue(SqQueue *Q)
//{
//    Q->front = 0;
//    Q->rear = 0;
//    return OK;
//}
//
//int QueueLength(SqQueue Q)
//{
//    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
//}
//
////入队
//Status EnQueue(SqQueue *Q,ElemType e)
//{
//    if ((Q->rear + 1) % MAXSIZE == Q->front) {
//        return ERROR;
//    }
//    
//    Q->data[Q->rear] = e;
//    Q->rear = (Q->rear + 1) % MAXSIZE;
//    
//    return OK;
//}
//
////出队
//Status DeQueue(SqQueue *Q,ElemType *e)
//{
//    if (Q->front == Q->rear) {
//        return ERROR;
//    }
//    
//    *e = Q->data[Q->front];
//    Q->front = (Q->front + 1) % MAXSIZE;
//    
//    return OK;
//}
