//
//  CTree.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/20.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "CTree.h"

#define MAX_TREE_SIZE 100

typedef int TElemType;

typedef struct CTNode
{
    int child;
    struct CTNode *next;
} *ChildPtr;//孩子结点

typedef struct//表头结构
{
    TElemType data;
    ChildPtr firstchild;
} CTBox;

typedef struct
{
    CTBox nodes[MAX_TREE_SIZE];
    int r; //根的位置
    int n; //结点数
}CTree;
