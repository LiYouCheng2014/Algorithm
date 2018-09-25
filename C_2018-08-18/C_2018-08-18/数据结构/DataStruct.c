//
//  DataStruct.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/9/9.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "DataStruct.h"

#include <stdlib.h>

#include "LYCLinkStack.h"

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

//静态链表
struct TreeNode {
    ElementType Element;
    Tree Left;
    Tree Right;
}T1[MaxTree],T2[MaxTree];

Tree BuildTree(struct TreeNode T[])
{
    int N = 0;
    scanf("%d\n",&N);
    Tree Root = Null;
//    int *check = (int *)malloc(sizeof(sizeof(int) * N));
    int check[MaxTree];
    char cl;
    char cr;
    
    if (N) {
        for (int i = 0; i < N; i++) {
            check[i] = 0;
        }
        
        for (int i = 0; i < N; i++) {
            scanf("%c %c %c\n",&T[i].Element,&cl,&cr);
            if (cl != '-') {
                T[i].Left = cl - '0';
                check[T[i].Left] = 1;
            } else {
                T[i].Left = Null;
            }
            
            if (cr != '-') {
                T[i].Right = cr - '0';
                check[T[i].Right] = 1;
            } else {
                T[i].Right = Null;
            }
        }
        
        for (int i = 0; i < N; i++) {
            if (!check[i]) {
                Root = i;
                break;
            }
        }
    }
    return Root;
}

int Isomerphic(Tree R1, Tree R2) {
    if ((R1 == Null) && (R2 == Null)) {
        return 1;
    }
    if (((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null))) {
        return 0;
    }
    if (T1[R1].Element != T2[R2].Element) {
        return 0;
    }
    if ((T1[R1].Left == Null) && (T2[R2].Left == Null)) {
        return Isomerphic(T1[R1].Right, T2[R2].Right);
    }
    if ((T1[R1].Left != Null) && (T2[R2].Left != Null) && ((T1[T1[R1].Left].Element) == (T2[T2[R2].Left].Element))) {
        return Isomerphic(T1[R1].Left, T2[R2].Left) && Isomerphic(T1[R1].Right, T2[R2].Right);
    }
    else {
        //交换
        return Isomerphic(T1[R1].Left, T2[R2].Right) && Isomerphic(T1[R1].Right, T2[R2].Left);
    }
}

void test()
{
    Tree R1 = BuildTree(T1);
    Tree R2 = BuildTree(T2);
    if (Isomerphic(R1, R2)) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
}



