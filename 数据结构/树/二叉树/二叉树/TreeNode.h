//
//  Tree.h
//  二叉树
//
//  Created by liyoucheng on 2018/9/27.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

//树结构
typedef int Type;
typedef struct TreeNode *Position;
typedef Position BinTree;

//二叉树
struct TreeNode {
    Type data;
    BinTree left;
    BinTree right;
};

//堆
typedef BinTree ElementType;

//结点
struct Node {
    ElementType data;
    struct Node *next;
};
typedef struct Node *Ptr;

#endif /* Tree_h */
