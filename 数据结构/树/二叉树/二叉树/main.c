//
//  main.c
//  二叉树
//
//  Created by liyoucheng on 2018/9/25.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

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
        printf("%d\n",BT->data);
        preOrderTraversal(BT->left);
        preOrderTraversal(BT->right);
    }
}

//中序 左根右
void inOrderTraversal(BinTree BT)
{
    if (BT) {
        preOrderTraversal(BT->left);
        printf("%d\n",BT->data);
        preOrderTraversal(BT->right);
    }
}

//后序 左右根
void postOrderTraversal(BinTree BT)
{
    if (BT) {
        preOrderTraversal(BT->left);
        preOrderTraversal(BT->right);
        printf("%d\n",BT->data);
    }
}

#pragma mark - 迭代遍历

//先序
void preOrderTraversalIter(BinTree BT)
{
    BinTree T = BT;
    Stack s = createStack();
    while (T || !isEmpty(s)) {
        //一直向左并将沿途经点入栈
        if (T) {
            printf("%5d\n", T->data);
            push(s, T);
            T = T->left;
        }
        else {
            pop(s, &T);
            //转向右子树
            T = T->right;
        }
    }
}

//中序
void inOrderTraversalIter(BinTree BT)
{
    BinTree T = BT;
    Stack s = createStack();
    while (T || !isEmpty(s)) {
        //一直向左并将沿途经点入栈
        if (T) {
            push(s, T);
            T = T->left;
        }
        else {
            pop(s, &T);
            printf("%5d\n", T->data);
            //转向右子树
            T = T->right;
        }
    }
}

//后序
void postOrderTraversalIter(BinTree BT)
{
    BinTree T = BT;
    Stack s1 = createStack();
    Stack s2 = createStack();
    while (T || !isEmpty(s2)) {
        if (T) {
            push(s1, T);
            push(s2, T);
            T = T->right;
        }
        else {
            pop(s2, &T);
            T = T->left;
        }
    }
    
    while (!isEmpty(s1)) {
        pop(s1, &T);
        printf("%5d\n", T->data);
    }
}

int main(int argc, const char * argv[]) {
    
//    test();
    
    return 0;
}
