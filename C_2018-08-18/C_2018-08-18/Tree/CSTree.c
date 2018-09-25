//
//  CSTree.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/20.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "CSTree.h"

#define MAX_TREE_SIZE 100

typedef int TElemType;

typedef struct CSNode
{
    TElemType data;
    struct CSNode *firstchild;
    struct CSNode *rightsib;
} CSNode, *CSTree;
