//
//  main.c
//  二叉树
//
//  Created by liyoucheng on 2018/9/25.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include <stdio.h>

typedef int ElementType;
typedef struct TreeNode *Position;
typedef Position BinTree;

//二叉树
struct TreeNode {
    ElementType data;
    BinTree left;
    BinTree right;
};

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



int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
