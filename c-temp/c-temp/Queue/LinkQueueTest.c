//
//  LinkQueueTest.c
//  c-temp
//
//  Created by liyoucheng on 2018/7/26.
//  Copyright © 2018年 liyoucheng. All rights reserved.
//

#include "LinkQueueTest.h"

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef int ElemType;

//循环队列
typedef struct QNode
{
    ElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
    QueuePtr front,rear;//队头、队尾
}LinkQueue;


//入队
Status EnQueue(LinkQueue *Q,ElemType e)
{
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;

    return OK;
}

//出栈
Status DeQueue(LinkQueue *Q,ElemType *e)
{
    QueuePtr p;
    if (Q->front == Q->rear) {
        return ERROR;
    }
    
    p = Q->front->next;
    *e = p->data;
    
    Q->front->next = p->next;
    if (Q->rear == p) {
        Q->rear = Q->front;
    }
    free(p);
    
    return OK;
}
