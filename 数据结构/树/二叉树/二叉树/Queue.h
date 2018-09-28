//
//  Queue.h
//  二叉树
//
//  Created by liyoucheng on 2018/9/26.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "TreeNode.h"

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

#endif /* Queue_h */
