//
//  LYCLinkList.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/9/11.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "LYCLinkList.h"

#include <stdlib.h>
#include <stdbool.h>

//线性表链式存储结构

typedef int LElementType;

typedef struct LLNode *PtrToLNode;

struct LLNode{
    LElementType Data;
    PtrToLNode Next;
};

typedef PtrToLNode Position;
typedef PtrToLNode List;

#define ERROR NULL


//struct LLNode LL;
//LList PtrL;

//求表长
int LLLength(List PtrL)
{
    List p = PtrL;
    int j = 0;
    while (p) {
        p = p->Next;
        j++;
    }
    return j;
}


//按序号查找
List LLFindKth(int K, List PtrL)
{
    List p = PtrL;
    int i = 1;
    while (p != NULL && i < K) {
        p = p->Next;
        i++;
    }
    
    if (i == K) {
        return p;
    }
    else {
        return NULL;
    }
}

//按值查找
List LLFind(LElementType X, List PtrL)
{
    List p = PtrL;
    while (p && p->Data != X) {
        p = p->Next;
    }
    
    if (p) {
        return p;
    }
    else {
        return NULL;
    }
}

/* 带头结点的插入 */
/*注意:在插入位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是链表结点指针，在P之前插入新结点 */
bool LLInsert(LElementType X, int i, List PtrL)
{
    //带头结点
    List pre;
    for (pre = PtrL; pre && pre->Next != PtrL; pre=pre->Next) {
        ;
    }
    
    if (pre == NULL) {
        //插入位置错误
        return false;
    }
    else {
        List temp = (List)malloc(sizeof(struct LLNode));
        temp->Data = X;
        temp->Next = PtrL;
        pre->Next = temp;
        return true;
    }
}

/* 带头结点的删除 */
/*注意:在删除位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是拟删除结点指针 */
bool LLDelete(int i, List PtrL)
{
    //带头结点
    List pre;
    for (pre = PtrL; pre && pre->Next != PtrL; pre=pre->Next) {
        ;
    }
    
    if (pre == NULL || PtrL == NULL) {
        //插入位置错误
        return false;
    }
    else {
        pre->Next = PtrL->Next;
        free(PtrL);
        return true;
    }
}

////插入操作
//List LLInsert(LElementType X, int i, LList PtrL)
//{
//    //不带头结点
//    LList s;
//    if (i == 1) {
//        s = (LList)malloc(sizeof(struct LLNode));
//        s->Data = X;
//        s->Next = PtrL;
//        return s;
//    }
//
//    LList p;
//    p = LLFindKth(i - 1, PtrL);
//    if (p == NULL) {
//        //参数i错
//        return NULL;
//    } else {
//        s = (LList)malloc(sizeof(struct LLNode));
//        s->Data = X;
//        s->Next = p->Next;
//        p->Next = s;
//        return PtrL;
//    }
//}

////删除操作
//LList LLDelete(int i, LList PtrL)
//{
//    //不带头结点
//    LList s;
//    if (i == 1) {
//        s = PtrL;
//        if (PtrL != NULL) {
//            PtrL = PtrL->Next;
//        } else {
//            return NULL;
//        }
//        free(s);
//        return PtrL;
//    }
//
//    LList p;
//    p = LLFindKth(i - 1, PtrL);
//    if (p == NULL) {
//        //i-1节点不存在
//        return NULL;
//    }else if (p->Next == NULL) {
//        //i节点不存在
//        return NULL;
//    } else {
//        s = p->Next;
//        p->Next = s->Next;
//        free(s);
//        return PtrL;
//    }
//}
