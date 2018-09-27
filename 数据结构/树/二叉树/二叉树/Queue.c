//
//  Queue.c
//  二叉树
//
//  Created by liyoucheng on 2018/9/26.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "Queue.h"

//带头结点

//创建队列
Queue InitQueue(void)
{
    Queue queue = (Queue)malloc(sizeof(struct LinkQueue));
    queue->front = queue->rear = (Ptr)malloc(sizeof(struct Node));
    if (!queue || !queue->front) {
        printf("分配内存失败\n");
        return NULL;
    }
    queue->front->next = NULL;
    queue->count = 0;
    return queue;
}

//队列是否空
bool IsEmptyQueue(Queue queue)
{
    if (queue->front == queue->rear) {
        return true;
    }
    else {
        return false;
    }
}

//入队
void InsertQueue(Queue queue, ElementType val)
{
    Ptr p = (Ptr)malloc(sizeof(struct Node));
    if (!p) {
        printf("分配内存失败\n");
        exit(-1);
    }
    p->data = val;
    p->next = NULL;
    
    queue->rear->next = p;
    queue->rear = p;
    queue->count += 1;
}

//出队
void DeleteQueue(Queue queue, ElementType *val)
{
    if (!IsEmptyQueue(queue)) {
        Ptr p = queue->front->next;
        *val = p->data;
        
        queue->front->next = p->next;
        queue->count -= 1;
        
        //若队头是队尾，则删除后要将rear指向头结点
        if (queue->rear == p) {
            queue->rear = queue->front;
        }
        free(p);
    }
    else {
        printf("队空\n");
    }
}
