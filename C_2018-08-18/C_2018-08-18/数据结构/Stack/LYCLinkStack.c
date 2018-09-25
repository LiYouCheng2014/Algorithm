//
//  LYCLinkStack.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/9/11.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "LYCLinkStack.h"

Stack CreateStack1(int MaxSize)
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode1));
    S->Next = NULL;
    return S;
}

bool IsEmpty1(Stack S)
{
    return (S->Next == NULL);
}

bool Push1(Stack S, ElementType1 item)
{
    struct SNode1 *tmpCell;
    tmpCell = (PtrToSNode)malloc(sizeof(struct SNode1));
    tmpCell->Data = item;
    tmpCell->Next = S->Next;
    S->Next = tmpCell;
    return true;
}

ElementType1 Pop1(Stack S)
{
    PtrToSNode FirstCell;
    ElementType1 TopElem;
    if (IsEmpty1(S)) {
        //栈空
        return -1;
    } else {
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        TopElem = FirstCell->Data;
        free(FirstCell);
        return TopElem;
    }
}

//int IsFull(Stack S, int MaxSize);
//
//
//ElementType Pop(Stack S);
