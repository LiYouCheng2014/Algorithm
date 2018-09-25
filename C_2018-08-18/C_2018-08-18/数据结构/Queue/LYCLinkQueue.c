//
//  LYCLinkQueue.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/9/11.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "LYCLinkQueue.h"

#include <stdlib.h>
#include <stdbool.h>


typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node{
    ElementType Data;
    PtrToNode Next;
};

typedef PtrToNode Position;

struct QNode1{
    Position Front;
    Position Rear;
    int MaxSize;
};
typedef struct QNode1 *Queue;

//Queue CreateQueue(int MaxSize)
//{
//    Queue Q = (Queue)malloc(sizeof(struct QNode));
//    Q->Data = (Position *)malloc(MaxSize * sizeof(Position));
//    Q->Front = Q->Rear = 0;
//    Q->MaxSize = MaxSize;
//    return Q;
//}

bool IsEmptyQ1(Queue Q)
{
    return (Q->Front == NULL);
}


//bool IsFullQ(Queue Q)
//{
//    return ((Q->Rear+1)%Q->MaxSize == Q->Front);
//}

//bool AddQ(Queue Q, Position item)
//{
//    if (IsFullQ(Q)) {
//        //队满
//        return false;
//    }
//    else {
//        Q->Rear = (Q->Rear + 1) % Q->MaxSize;
//        Q->Data[Q->Rear] = item;
//        return true;
//    }
//}
//

ElementType DeleteQ1(Queue Q)
{
    Position FrontCell;
    ElementType FrontElem;
    
    if  ( IsEmpty1(Q) ) {
        //队空
        return -1;
    }
    else {
        FrontCell = Q->Front;
        if ( Q->Front == Q->Rear ) /* 若队列只有一个元素 */
            Q->Front = Q->Rear = NULL; /* 删除后队列置为空 */
        else
            Q->Front = Q->Front->Next;
        FrontElem = FrontCell->Data;
        
        free( FrontCell );  /* 释放被删除结点空间  */
        return  FrontElem;
    }
}
