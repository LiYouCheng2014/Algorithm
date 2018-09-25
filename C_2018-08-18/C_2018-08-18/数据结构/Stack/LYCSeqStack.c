//
//  LYCSeqStack.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/9/11.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "LYCSeqStack.h"

#include <stdlib.h>
#include <stdbool.h>

typedef struct SNode *Stack;
typedef int ElementType;
struct SNode{
    ElementType *Data;
    int Top;
    int MaxSize;
};

Stack CreateStack2(int MaxSize)
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}

int IsFull2(Stack S)
{
    return (S->Top == S->MaxSize - 1);
}

bool Push2(Stack S, ElementType item)
{
    if (IsFull2(S)) {
        //栈满
        return false;
    } else {
        S->Data[++(S->Top)] = item;
        return true;
    }
}

int IsEmpty2(Stack S)
{
    return (S->Top == -1);
}

ElementType Pop2(Stack S)
{
    if (IsEmpty2(S)) {
        //栈空
        return -1;
    } else {
        return (S->Data[(S->Top)--]);
    }
}

//struct DStack {
//    ElementType Data[MaxSize];
//    int Top1;
//    int Top2;
//}S;
////S.Top1 = -1;
////S.Top2 = MaxSize;
//
//void Push1(struct DStack *PtrS, ElementType item, int Tag)
//{
//    if (PtrS->Top2 - PtrS->Top1 == 1) {
//        //栈满
//        return;
//    }
//
//    if (Tag == 1) {
//        PtrS->Data[++(PtrS->Top1)] = item;
//    }else {
//        PtrS->Data[--(PtrS->Top2)] = item;
//    }
//}
//
//ElementType Pop1(struct DStack *PtrS, int Tag)
//{
//    if (Tag == 1) {
//        if (PtrS->Top1 == -1) {
//            //栈1空
//            return -1;
//        }
//        else {
//            return PtrS->Data[(PtrS->Top1)--];
//        }
//    }else {
//        if (PtrS->Top2 == MaxSize) {
//            //栈2空
//            return -1;
//        }
//        else {
//            return PtrS->Data[(PtrS->Top2)++];
//        }
//    }
//}
