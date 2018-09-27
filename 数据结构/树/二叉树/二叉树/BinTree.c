//
//  BinTree.c
//  二叉树
//
//  Created by liyoucheng on 2018/9/27.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "BinTree.h"

#include "TreeNode.h"
#include "Stack.h"

//创建树
BinTree createTree()
{
    BinTree tree;
    char str = getchar();
    if (str == '#') {
        tree = NULL;
    }
    else {
        tree = (BinTree)malloc(sizeof(struct TreeNode));
        tree->data = str;
        tree->left = createTree();
        tree->right = createTree();
    }
    return tree;
}

#pragma mark - 递归遍历

//先序 根左右
void preOrderTraversal(BinTree BT)
{
    if (BT) {
        printf("%c ",BT->data);
        preOrderTraversal(BT->left);
        preOrderTraversal(BT->right);
    }
}

//中序 左根右
void inOrderTraversal(BinTree BT)
{
    if (BT) {
        inOrderTraversal(BT->left);
        printf("%c ",BT->data);
        inOrderTraversal(BT->right);
    }
}

//后序 左右根
void postOrderTraversal(BinTree BT)
{
    if (BT) {
        postOrderTraversal(BT->left);
        postOrderTraversal(BT->right);
        printf("%c ",BT->data);
    }
}

#pragma mark - 迭代遍历
//有左子树就入栈
//先序
void preOrderTraversalIter(BinTree BT)
{
    BinTree T = BT;
    Stack s = InitStack();
    while (T || !IsEmptyStack(s)) {
        //一直向左并将沿途经点入栈
        if (T) {
            printf("%c ", T->data);
            PushStack(s, T);
            T = T->left;
        }
        else {
            PopStack(s, &T);
            //转向右子树
            T = T->right;
        }
    }
}

//中序
void inOrderTraversalIter(BinTree BT)
{
    BinTree T = BT;
    Stack s = InitStack();
    while (T || !IsEmptyStack(s)) {
        //一直向左并将沿途经点入栈
        if (T) {
            PushStack(s, T);
            T = T->left;
        }
        else {
            PopStack(s, &T);
            printf("%c ", T->data);
            //转向右子树
            T = T->right;
        }
    }
}

//有右子树就入栈
//后序
void postOrderTraversalIter(BinTree BT)
{
    BinTree T = BT;
    Stack s1 = InitStack();
    Stack s2 = InitStack();
    while (T || !IsEmptyStack(s2)) {
        if (T) {
            PushStack(s1, T);
            PushStack(s2, T);
            T = T->right;
        }
        else {
            PopStack(s2, &T);
            T = T->left;
        }
    }
    
    while (!IsEmptyStack(s1)) {
        PopStack(s1, &T);
        printf("%c ", T->data);
    }
}

void test()
{
    BinTree tree = createTree();
    printf("先序递归遍历:");
    preOrderTraversal(tree);
    printf("\n");
    printf("先序非递归遍历:");
    preOrderTraversalIter(tree);
    printf("\n");
    
    printf("中序递归遍历:");
    inOrderTraversal(tree);
    printf("\n");
    printf("中序非递归遍历:");
    inOrderTraversalIter(tree);
    printf("\n");
    
    printf("后序递归遍历:");
    postOrderTraversal(tree);
    printf("\n");
    printf("后序非递归遍历:");
    postOrderTraversalIter(tree);
    printf("\n");
}
