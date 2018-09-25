//
//  SortTest.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/29.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "SortTest.h"


#define MAXSIZE 10

typedef struct
{
    int r[MAXSIZE + 1];
    int length;
}SqList;

void swap(SqList *L, int i, int j)
{
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}



#pragma mark - 希尔排序
/*
 基本思想：将待排序的序列构成大顶堆，此时，整个序列的最大值就是堆顶的根节点。将他移走（与末尾元素交换）将剩下的n-1个序列构成一个队，如此重复
 堆：每个结点的值都大于或等于其左右孩子结点的值，称为大顶堆
 
 nlogn
 不稳定
 */
void HeapAdjust(SqList *L, int s, int m)
{
    int temp = L->r[s];
    for (int j = 2 * s; j <= m; j *= 2) {
        if (j < m && L->r[j] < L->r[j + 1]) {
            ++j;
        }
        if (temp >= L->r[j]) {
            break;
        }
        L->r[s] = L->r[j];
        s = j;
    }
    L->r[s] = temp;
}

void HeapSort(SqList *L)
{
    for(int i = L->length / 2; i > 0; i--) {
        HeapAdjust(L, i, L->length);
    }
    
    for (int i = L->length; i > 1; i--) {
        swap(L, 1, i);
        HeapAdjust(L, 1, i - 1);
    }
}

#pragma mark - 希尔排序
/*
 基本思想：
 n^(3/2)
 不稳定
 */
void ShellSort(SqList *L)
{
    int increment = L->length;
    do {
        increment = increment / 3 + 1;
        for (int i = increment + 1; i <= L->length; i++) {
            if (L->r[i] < L->r[i - increment]) {
                L->r[0] = L->r[i];
                int j;
                for (j = i - increment; j > 0 && L->r[0] < L->r[j]; j -= increment) {
                    L->r[j + increment] = L->r[j];
                }
                
                L->r[j + increment] = L->r[0];
            }
        }
    } while (increment > 1);
}

#pragma mark - 直接插入排序
/*
 基本思想：将一个记录插入到已经排好序的有序表中，从而得到一个新的、记录数增1的有序表
 (n+4)(n-1)/2
 稳定
 */
void InsertSort(SqList *L)
{
    for (int i = 2; i <= L->length; i++) {
        if (L->r[i] < L->r[i - 1]) {
            L->r[0] = L->r[i]; //设置哨兵
            int j;
            for (j = i - 1; L->r[j] > L->r[0]; j--) {
                L->r[j + 1] = L->r[j];
            }
            L->r[j + 1] = L->r[0];
        }
    }
}

#pragma mark - 简单选择排序
/*
 基本思想：通过n-i次关键字间的比较，从n-i+1个记录中选出关键字最小的记录，并和第i个记录交换之
 n(n-1)/2
 稳定
 */
void SelectSort(SqList *L)
{
    
    for (int i = 1; i < L->length; i++) {
        int min = i;
        for (int j = i + 1; j <= L->length; j++) {
            if (L->r[min] > L->r[j]) {
                min = j;
            }
        }
        if (i != min) {
            swap(L, i, min);
        }
    }
}

#pragma mark - 冒泡排序

/*
 基本思想：两两比较相邻记录的关键字，如果反序则交换，直到没有反序的记录为止
 n(n-1)/2
 稳定
 */
void BubleSort0(SqList *L)
{
    for (int i = 1; i <= L->length; i++) {
        for (int j = i + 1; j <= L->length; j++) {
            if (L->r[i] > L->r[j]) {
                swap(L, i, j);
            }
        }
    }
}

//标准
void BubleSort(SqList *L)
{
    for (int i = 1; i < L->length; i++) {
        for (int j = L->length - 1; j >= i; j--) {
            if (L->r[j] > L->r[j + 1]) {
                swap(L, j, j + 1);
            }
        }
    }
}

//优化的冒泡排序
void BubbleSort2(SqList *L)
{
    int flag = 1;
    for (int i = 1; i < L->length && flag == 1; i++) {
        flag = 0;
        for (int j = L->length - 1; j >= i; j--) {
            if (L->r[j] > L->r[j + 1]) {
                swap(L, j, j + 1);
                flag = 1;
            }
        }
    }
}

