//
//  PTree.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/20.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "PTree.h"

#define MAX_TREE_SIZE 100

typedef int TElemType;

typedef struct PTNode
{
    TElemType data;
    int parent;//双亲位置
} PTNode;

typedef struct
{
    PTNode node[MAX_TREE_SIZE];//节点数组
    int r;//根的位置
    int n;//结点数
} PTree;
