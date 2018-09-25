//
//  main.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include <stdio.h>

#include "CalcExp.h"

#include "StringTest.h"

#include <stdlib.h>

#include "lc_005.h"

#include "MergeSort.h"
#include "BubbleSort.h"
#include "QuicklySort.h"
#include "SelectSort.h"
#include "HeapSort.h"
#include "InsertSort.h"
#include "ShellSort.h"

#include "Search.h"
#include "DataStruct.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct AVLNode *Position;
typedef Position AVLTree;
typedef int ElementType;
//二叉平衡树
struct AVLNode {
    ElementType data;
    AVLTree left;
    AVLTree right;
    int height;
};

int Max(int x, int y) {
    return x > y ? x : y;
}

int GetHeight(AVLTree T) {
    return T == NULL ? -1 : T->height;
}

//左旋
AVLTree SingleLeftRotation(AVLTree A) {
    //A必须有一个左子结点B
    //将A与B做左单旋，更新A与B的高度，返回新的根结点B
    AVLTree B = A->left;
    A->left = B->right;
    B->right = A;
    A->height = Max(GetHeight(A->left), GetHeight(A->right)) + 1;
    B->height = Max(GetHeight(B->left), GetHeight(B->right)) + 1;
    
    return B;
}

//右旋
AVLTree SingleRightRotation(AVLTree A) {
    //A必须有一个右子结点B
    //将A与B做右单旋，更新A与B的高度，返回新的根结点B
    AVLTree B = A->right;
    A->right = B->left;
    B->left = A;
    A->height = Max(GetHeight(A->left), GetHeight(A->right)) + 1;
    B->height = Max(GetHeight(B->left), GetHeight(B->right)) + 1;
    
    return B;
}

//左右旋
AVLTree DoubleLeftRightRotation(AVLTree A)
{
    //A必须有一个左子节点B，且B必须有一个右子节点C
    //将A、B与C做两次单旋，返回新的根结点C
    //B与C做右单旋，C被返回
    A->left = SingleRightRotation(A->left);
    //A与C做左单旋，C被返回
    return SingleLeftRotation(A);
}

//右左旋
AVLTree DoubleRightLeftRotation(AVLTree A)
{
    //A必须有一个右子节点B，且B必须有一个左子节点C
    //将A、B与C做两次单旋，返回新的根结点C
    //B与C做左单旋，C被返回
    A->right = SingleLeftRotation(A->right);
    //A与C做右单旋，C被返回
    return SingleRightRotation(A);
}

AVLTree Insert(AVLTree T, ElementType X) {
    //将X插入AVL树中，并且返回调整后的AVL树
    if (!T) {
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->data = X;
        T->height = 0;
        T->left = T->right = NULL;
    } else if (X < T->data) {
        //插入T的左子树
        T->left = Insert(T->left, X);
        if (GetHeight(T->left) - GetHeight(T->right) == 2) {
            if (X < T->left->data) {
                T = SingleLeftRotation(T);//左单旋
            } else {
                T = DoubleLeftRightRotation(T);//左右双旋
            }
        }
    } else if (X > T->data) {
        //插入T的右子树
        T->right = Insert(T->right, X);
        if (GetHeight(T->left) - GetHeight(T->right) == -2) {
            if (X > T->right->data) {
                T = SingleRightRotation(T);//右单旋
            } else {
                T = DoubleRightLeftRotation(T);//右左双旋
            }
        }
    }
    
    T->height = Max(GetHeight(T->left), GetHeight(T->right)) + 1;
    
    return T;
}

int main()
{
    int N;
    scanf("%d",&N);
    
    int *nums = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d",&nums[i]);
    }
    
    AVLTree T = NULL;
    for (int i = 0; i < N; i++) {
        T = Insert(T, nums[i]);
    }
    
    printf("%d\n",T->data);
    return 0;
}

//#define N 10
//
//#define MAX_SIZE 30
//#define STR_LEN 5
//
//typedef struct Node {
//    int data;
//    struct Node *left;
//    struct Node * right;
//} *treeNode;
//
//treeNode Stack[MAX_SIZE];
//int values[MAX_SIZE];
//
//int num = 0;
//int top = -1;
//
//void Push(treeNode tn)
//{
//    Stack[++top] = tn;
//}
//
//treeNode Pop()
//{
//    return Stack[top--];
//}
//
//treeNode Top()
//{
//    return Stack[top];
//}
//
//bool isEmpty()
//{
//    return top == -1;
//}
//
//void PostOrderTraversal(treeNode root)
//{
//    treeNode tn = root;
//    if (tn) {
//        PostOrderTraversal(tn->left);
//        PostOrderTraversal(tn->right);
//        values[num++] = tn->data;
//    }
//}
//
//int main()
//{
//    int n;
//    scanf("%d\n",&n);
//
//    char operation[STR_LEN];
//    treeNode father = NULL;
//    treeNode root = NULL;
//    bool findRoot = 0;
//    bool Poped = 0;
//
//    for (int i = 0; i < 2 * n; i++) {
//        scanf("%s", operation);
//        if (strcmp(operation, "Push") == 0) {
//            int value;
//            scanf("%d",&value);
//
//            treeNode newNode = (treeNode)malloc(sizeof(struct Node));
//            newNode->data = value;
//            newNode->left = NULL;
//            newNode->right = NULL;
//            if (!findRoot) {
//                root = newNode;
//                Push(newNode);
//                findRoot = 1;
//            }
//            else {
//                if (!Poped) {
//                    father = Top();
//                }
//                if (father->left == NULL) {
//                    father->left = newNode;
//                }
//                else {
//                    father->right = newNode;
//                }
//                Push(newNode);
//            }
//            Poped = 0;
//        }
//        else {
//            father = Pop();
//            Poped = 1;
//        }
//    }
//    PostOrderTraversal(root);
//    for (int i = 0; i < num - 1; i++) {
//        printf("%d ",values[i]);
//    }
//    printf("%d\n",values[num-1]);
    
    
    
//    test();
//    int M;
//    int N;
//    int K;
//    scanf("%d %d %d",&M,&N,&K);
//
//    int Origin[MAXSIZE];
//    int This[MAXSIZE];
//
//    int Result[K];
//    for (int i = 0; i < N; i++) {
//        Origin[i] = i + 1;
//    }
//
//    int cnt = 0;
//    while (cnt < K) {
//        for (int i = 0; i < N; i++) {
//            scanf("%d",&This[i]);
//        }
//
//        if (CompareStack(Origin, This, M, N)) {
//            Result[cnt] = 1;
//        }
//        else {
//            Result[cnt] = 0;
//        }
//    }
//
//    for (int i = 0; i < K; i++) {
//        if (Result[i]) {
//            printf("YES\n");
//        }
//        else {
//            printf("NO\n");
//        }
//    }
//
//    return 0;
//}

//    List L;
//    ElementType X;
//    Position P;
//
////    L = ReadInput();
//    scanf("%d", &X);
//    P = BinarySearch( L, X );
//    printf("%d\n", P);

//    test();

//return 0;
//
//Position BinarySearch( List L, ElementType X )
//{
//    int low = 0;
//    int high = L->Last - 1;
//    while (low <= high) {
//        int mid = (low + high) / 2;
//        if (L->Data[mid] > X) {
//            high = mid - 1;
//        }
//        else if (L->Data[mid] < X) {
//            low = mid + 1;
//        }
//        else {
//            return mid;
//        }
//    }
//    return NotFound;
//}

//int maxSubseqSum(int arr[], int n)
//{
//    int maxSum = 0;
//    int sum = 0;
//    for (int i = 0; i < n; i++) {
//        sum += arr[i];
//        if (maxSum < sum) {
//            maxSum = sum;
//        }
//        else if (sum < 0) {
//            sum = 0;
//        }
//    }
//    return maxSum;
//}
//
//
//int main(int argc, const char * argv[]) {
//    int n;
//    scanf("%d",&n);
//
//    int *arr = malloc(sizeof(int) * n);
//
//    for (int i = 0; i < n; i++) {
//        int num = 0;
//        scanf("%d",&num);
//
//        arr[i] = num;
//    }
//
//    int sum = maxSubseqSum(arr, n);
//    printf("%d\n",sum);
////    int nums[] = {-2,0,0,2,2};
////    int i, count;
////    int **triplets = threeSum(nums, sizeof(nums) / sizeof(*nums), &count);
////    for (i = 0; i < count; i++) {
////        printf("%d %d %d\n", triplets[i][0], triplets[i][1], triplets[i][2]);
////    }
//
////    int i, size = 0;
////    char **letters = letterCombinations("23", &size);
////    for (i = 0; i < size; i++) {
////        printf("%s\n", letters[i]);
////        free(letters[i]);
////    }
////    testHeapSort();
////    testInsertSort();
////    testShellSort();
////    testSearch();
////    test();
//    return 0;
//}



