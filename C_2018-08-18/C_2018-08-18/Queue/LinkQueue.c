//
//  LinkQueue.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/19.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "LinkQueue.h"

#include <stdlib.h>

//带头结点

//初始化
LinkQueue *lq_InitQueue()
{
    LinkQueue *s = (LinkQueue *)malloc(sizeof(QNode));
    if (!s) {
        return NULL;
    }
    s->rear->next = NULL;
    s->front->next = NULL;
    s->count = 0;
    
    return s;
}

//队长
int lq_QueueLength(LinkQueue Q)
{
    return Q.count;
}


//入队
lq_Status lq_EnQueue(LinkQueue *Q, lq_ElemType e)
{
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if (!s) {
        exit(-1);
    }
    
    s->data = e;
    s->next = NULL;
    
    Q->rear->next = s;
    Q->rear = s;
    Q->count += 1;
    
    return OK;
}

//出队
lq_Status lq_DeQueue(LinkQueue *Q, lq_ElemType *e)
{
    
    if (Q->front == Q->rear) {
        //队空
        return ERROR;
    }
    
    QueuePtr p = Q->front->next;
    *e = p->data;
    
    Q->front->next = p->next;
    Q->count -= 1;
    
    if (Q->rear == p) {
        //若队头是队尾，则删除后要将rear指向头结点
        Q->rear = Q->front;
    }
    free(p);
    
    return OK;
}
