//
//  LYCSeqQueue.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/9/11.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "LYCSeqQueue.h"

#include <stdlib.h>
#include <stdbool.h>


typedef int Position;
struct QNode{
    Position *Data;
    Position Front;
    Position Rear;
    int MaxSize;
};

typedef struct QNode *Queue;

Queue CreateQueue(int MaxSize)
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (Position *)malloc(MaxSize * sizeof(Position));
    Q->Front = Q->Rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

bool IsFullQ(Queue Q)
{
    return ((Q->Rear+1)%Q->MaxSize == Q->Front);
}

bool AddQ(Queue Q, Position item)
{
    if (IsFullQ(Q)) {
        //队满
        return false;
    }
    else {
        Q->Rear = (Q->Rear + 1) % Q->MaxSize;
        Q->Data[Q->Rear] = item;
        return true;
    }
}

int IsEmptyQ(Queue Q)
{
    return (Q->Front == Q->Rear);
}

Position DeleteQ(Queue Q)
{
    if (IsEmptyQ(Q)) {
        //队空
        return -1;
    }
    else {
        Q->Front = (Q->Front + 1) % Q->MaxSize;
        return Q->Data[Q->Front];
    }
}
