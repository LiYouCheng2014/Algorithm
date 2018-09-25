//
//  Search.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/9/3.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "Search.h"

#include <stdlib.h>

/**
 普通查找

 @param a 元素组
 @param n 数组大小
 @param key 要查找的key
 @return 查找的位置
 */
int search(int a[], int n, int key)
{
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            index = i;
            break;
        }
    }
    return index;
}


/**
 二分查找

 @param a 元素组
 @param n 数组大小
 @param key 要查找的key
 @return 查找的位置
 */
int binarySearch(int a[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == key) {
            return mid;
        }
        else if (a[mid] > key) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

/*
 生成二叉排序树
 1.申请保存节点p的内存，将关键字保存在节点的数据域
 2. 在二叉树中查找插入节点的父节点
 3. 比较p节点的数据域父节点的数据，决定将p插入父节点的左子树还是右子树
 */

typedef struct bst {
    int data;
    struct bst *left;
    struct bst *right;
}BSTree;

void insertBST(BSTree *t, int key)
{
    BSTree *p;
    if (!(p = (BSTree *)malloc(sizeof(BSTree *)))) {
        printf("申请内存失败\n");
        exit(0);
    }
    
    p->data = key;
    p->left = p->right = NULL;
    
    BSTree *head = t;
    BSTree *parent = NULL;
    while (head != NULL) {
        parent = head;
        if (key < head->data) {
            head = head->left;
        }
        else {
            head = head->right;
        }
    }
    
    if (key < parent->data) {
        parent->left = p;
    }
    else {
        parent->right = p;
    }
}

void CreateBST(BSTree *t, int data[], int n)
{
    t->data = data[0];
    t->left = t->right = NULL;
    for (int i = 1; i < n; i++) {
        insertBST(t, data[i]);
    }
}

void BST_LDR(BSTree *t)
{
    if(t != NULL) {
        BST_LDR(t->left);
        printf("%d ",t->data);
        BST_LDR(t->right);
    }
    
    return;
}

/*
 1. 从根节点开始查找
 2. 若节点为空，则查找失败
 3. 若key值与节点的数据相等，表示查找成功，返回节点指针
 4. 若key值小于节点的数据，继续在当前结点的左子树查找
 5. 若key值大于结点的数据，继续在当前结点的右子树查找
 */
BSTree *searchBST(BSTree *t, int key)
{
    if (t != NULL || t->data == key) {
        return t;
    }
    else if (key > t->data) {
        return searchBST(t->right, key);
    }
    else {
        return searchBST(t->left, key);
    }
}

void testSearch()
{
//    int arr[8] = { 3, 9, 10, 11, 16, 19, 26, 28 };
//    int len = sizeof(arr)/sizeof(arr[0]);
////    int ret = search(arr, len, 10);
//    int ret = binarySearch(arr,len,10);
    
    int arr1[8] = { 19, 3, 10, 9, 16, 11, 28, 26 };
    int len = sizeof(arr1)/sizeof(arr1[0]);
    BSTree bst;// = (BSTree *)malloc(sizeof(BSTree *));;
    CreateBST(&bst, arr1, 8);
    BST_LDR(&bst);
    
    printf("\n");
    BSTree *pos = searchBST(&bst, 10);
    if (pos) {
        printf("查找成功%d\n",pos->data);
    }
    else {
        printf("查找失败\n");
    }
}
