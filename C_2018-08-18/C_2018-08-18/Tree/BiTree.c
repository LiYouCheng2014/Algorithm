//
//  BiTree.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/20.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "BiTree.h"

#include <stdlib.h>

#define MAX_TREE_SIZE 100

typedef char TElemType;

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

//前序
void PreOrderTraverse(BiTree T)
{
    if (T == NULL) {
        return;
    }
    
    printf("%c",T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

//中序
void InOrderTraverse(BiTree T)
{
    if (T == NULL) {
        return;
    }
    
    InOrderTraverse(T->lchild);
    printf("%c",T->data);
    InOrderTraverse(T->rchild);
}

//后序
void PostOrderTraverse(BiTree T)
{
    if (T == NULL) {
        return;
    }
    
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c",T->data);
}

//按前序创造树
void CreateBiTree(BiTree *T)
{
    TElemType ch;
    scanf("%c",&ch);
    if (ch == '#') {
        *T = NULL;
    }
    else {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!*T) {
            exit(-1);
        }
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}
