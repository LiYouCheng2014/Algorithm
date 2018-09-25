//
//  HeapSort.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/9/2.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "HeapSort.h"


/**
 创建大堆

 @param a 原数组
 @param s 当前结点
 @param n 堆的大小
 */
void HeapAdjus(int a[], int s, int n)
{
    while (2 * s + 1 < n) {
        int j = 2 * s + 1;
        if ((j + 1) < n) {
            //左子树小于右子树，则需要比较右子树
            if (a[j] < a[j + 1]) {
                j++;//序号增加1，指向右子树
            }
        }
        
        //比较s与j为序号的数据
        if (a[s] < a[j]) {
            int t = a[s];
            a[s] = a[j];
            a[j] = t;
            //堆被破坏，需要重新调整
            s = j;
        }
        else {
            //不再需要调整
            break;
        }
    }
}

/**
 堆排序
 
 @param a 原数组
 @param len 数组长度
 */
void heapSort(int a[], int len)
{
    //将a[0]至a[n-1]构成堆
    for (int i = len / 2 - 1; i >= 0; i--) {
        HeapAdjus(a, i, len);
    }
    
    //取根节点与末节点交换
    for (int i = len - 1; i > 0; i--) {
        int t = a[0];
        a[0] = a[i];//与第i个记录交换
        a[i] = t;
        //将a[0]至a[i]重新调整为堆
        HeapAdjus(a, 0, i);
    }
}

/**
 测试堆排序
 */
void testHeapSort()
{
    int arr[8] = { 19, 3, 10, 9, 16, 11, 28, 26 };
    int len = sizeof(arr)/ sizeof(arr[0]);
    
    printf("堆排序前:");
    for (int i = 0; i < len; i++) {
        printf("%d ",arr[i]);
    }
    
    heapSort(arr, len);
    
    printf("\n堆排序后:");
    for (int i = 0; i < len; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
