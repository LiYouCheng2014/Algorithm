//
//  Queue.h
//  链队
//
//  Created by liyoucheng on 2018/9/26.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;

//结点
struct Node {
    ElementType data;
    struct Node *next;
};
typedef struct Node *Ptr;

//队列结构
struct LinkQueue {
    Ptr front;//队头
    Ptr rear;//队尾
    int count;
};
typedef struct LinkQueue *Queue;

//创建队列
Queue InitQueue(void);
//队列是否空
bool IsEmptyQueue(Queue queue);
//入队
void InsertQueue(Queue queue, ElementType val);
//出队
void DeleteQueue(Queue queue, ElementType *val);
//销毁队
void DestoryQueue(Queue queue);
//遍历队列
void TraverseQueue(Queue queue);
//清空队列
void ClearQueue(Queue queue);
//队列长度
int LengthQueue(Queue queue);
//队测试
void test(void);

#endif /* Queue_h */
