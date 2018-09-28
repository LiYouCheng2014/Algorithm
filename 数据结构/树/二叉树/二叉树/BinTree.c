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
#include "Queue.h"

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
void preOrderTraversal(BinTree bt)
{
    if (bt) {
        printf("%c ",bt->data);
        preOrderTraversal(bt->left);
        preOrderTraversal(bt->right);
    }
}

//中序 左根右
void inOrderTraversal(BinTree bt)
{
    if (bt) {
        inOrderTraversal(bt->left);
        printf("%c ",bt->data);
        inOrderTraversal(bt->right);
    }
}

//后序 左右根
void postOrderTraversal(BinTree bt)
{
    if (bt) {
        postOrderTraversal(bt->left);
        postOrderTraversal(bt->right);
        printf("%c ",bt->data);
    }
}

#pragma mark - 迭代遍历
//有左子树就入栈
//先序
void preOrderTraversalIter(BinTree bt)
{
    BinTree T = bt;
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
void inOrderTraversalIter(BinTree bt)
{
    BinTree T = bt;
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
void postOrderTraversalIter(BinTree bt)
{
    BinTree T = bt;
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

#pragma mark - 其它
//层次遍历
void levelOrderTraversal(BinTree bt)
{
    if (bt) {
        Queue q = InitQueue();
        BinTree T;
        InsertQueue(q, bt);
        while (!IsEmptyQueue(q)) {
            DeleteQueue(q, &T);
            printf("%c ", T->data);
            if (T->left) {
                InsertQueue(q, T->left);
            }
            if (T->right) {
                InsertQueue(q, T->right);
            }
        }
    }
}

#pragma mark - 应用
//二叉树高度
int height(BinTree bt)
{
    int h1,h2;
    if (bt == NULL) {
        return 0;
    }
    else {
        h1 = height(bt->left);
        h2 = height(bt->right);
        return (h1 > h2 ? h1 : h2) + 1;
    }
}

//每层结点个数
void levelCount(BinTree bt, int l, int num[])
{
    if (bt) {
        num[l]++;
        levelCount(bt->left, l + 1, num);
        levelCount(bt->right, l + 1, num);
    }
}

//结点总数
int countTree(BinTree bt)
{
    int lcount,rcount;
    if (bt == NULL) {
        return 0;
    }
    lcount = countTree(bt->left);
    rcount = countTree(bt->right);
    return lcount + rcount + 1;
}

//测试二叉树
void test()
{
//    ABD#G###CE##FH###
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
    
    printf("层次遍历:");
    levelOrderTraversal(tree);
    printf("\n");
    
    int treeHeight = height(tree);
    printf("树深度:%d\n",treeHeight);
    
    int count = countTree(tree);
    printf("结点总数:%d\n",count);
    
    
    int l = 1;
    int *t = (int *)malloc(sizeof(int) * (treeHeight + 1));
    for (int i = 0; i < treeHeight + 1; i++) {
        t[i] = 0;
    }
    levelCount(tree, l, t);
    for(int i = 1; i <= treeHeight; i++){
        printf("第%d层数目: %d\n",i,t[i]);
    }
}
