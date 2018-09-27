//
//  Queue.c
//  链队
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

//销毁队
void DestoryQueue(Queue queue)
{
    while (queue->front != NULL) {
        queue->rear = queue->front->next;
        free(queue->front);
        queue->front = queue->rear;
    }
}

//遍历队列
void TraverseQueue(Queue queue)
{
    if (!IsEmptyQueue(queue)) {
        Ptr p = queue->front->next;
        while (p) {
            printf("%d ",p->data);
            p = p->next;
        }
    }
    printf("\n");
}

//清空队列
void ClearQueue(Queue queue)
{
    Ptr p = queue->front->next;
    Ptr q = NULL;
    queue->rear = queue->front;
    queue->front->next = NULL;
    queue->count = 0;
    
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
}

//队列长度
int LengthQueue(Queue queue)
{
    return queue->count;
}

//队测试
void test(void)
{
    printf("初始化队并将1-10入队\n");
    Queue q = InitQueue();
    for (int i = 1; i < 11; i++) {
        InsertQueue(q, i);
    }

    printf("队中元素从队头依次为:\n");
    TraverseQueue(q);
    

    printf("队长度:%d\n",LengthQueue(q));

    ElementType e;
    DeleteQueue(q, &e);
    printf("第一次出队的元素为:%d\n",e);

    DeleteQueue(q, &e);
    printf("第二次出队的元素为:%d\n",e);

    printf("队是否空:%d(1:是，0:不是)\n",IsEmptyQueue(q));

    ClearQueue(q);
    printf("队清空后，是否空:%d(1:是，0:不是)\n",IsEmptyQueue(q));

    DestoryQueue(q);
    printf("队销毁\n");
}
