//
//  QuicklySort.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/9/2.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "QuicklySort.h"

/**
 分治法拆分数组

 @param a 原数组
 @param left 左边
 @param right 右边
 @return 拆分点
 */
int patition(int a[], int left, int right)
{
    //基准元素
    int base = a[left];
    
    while (left < right) {
        while (left < right && a[right] > base) {
            --right;
        }
        a[left] = a[right];
        
        while (left < right && a[left] < base) {
            ++left;
        }
        a[right] = a[left];
    }
    a[left] = base;
    
    return left;
}

/**
 快速排序

 @param a 原数组
 @param left 左边
 @param right 右边
 */
void quicklySort(int a[], int left, int right)
{
    if (left < right) {
        int i = patition(a, left, right);
        quicklySort(a, left, i - 1);
        quicklySort(a, i + 1, right);
    }
}


/**
 测试快速排序
 */
void testQuicklySort()
{
    int arr[8] = { 19, 3, 10, 9, 16, 11, 28, 26 };
    int len = sizeof(arr)/ sizeof(arr[0]);
    
    printf("快速排序前:");
    for (int i = 0; i < len; i++) {
        printf("%d ",arr[i]);
    }
    
    quicklySort(arr, 0, len - 1);
    
    printf("\n快速排序后:");
    for (int i = 0; i < len; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
