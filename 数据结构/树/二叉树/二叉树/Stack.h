//
//  Stack.h
//  二叉树
//
//  Created by liyoucheng on 2018/9/25.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "TreeNode.h"

//栈结构
struct LinkStack {
    Ptr top;//栈顶
    int count;
};
typedef struct LinkStack *Stack;

//创建栈
Stack InitStack(void);

//栈是否空
bool IsEmptyStack(Stack stack);

//入栈
void PushStack(Stack stack, ElementType val);

//出栈
void PopStack(Stack stack, ElementType *val);
#endif /* Stack_h */
