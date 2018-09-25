//
//  LYCLinkStack.h
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/9/11.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef LYCLinkStack_h
#define LYCLinkStack_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct SNode1 *PtrToSNode;
typedef int ElementType1;
struct SNode1{
    ElementType1 Data;
    struct SNode1 *Next;
};
typedef PtrToSNode Stack;

Stack CreateStack1(int MaxSize);

bool IsEmpty1(Stack S);

bool Push1(Stack S, ElementType1 item);

ElementType1 Pop1(Stack S);

#endif /* LYCLinkStack_h */
