//
//  main.c
//  Sort
//
//  Created by liyoucheng on 2018/7/9.
//  Copyright © 2018年 liyoucheng. All rights reserved.
//

#include <stdio.h>
int heapsize;

void printArray(int a[],int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

/*
 插入排序
 是否稳定:稳定
 平均时间复杂度:O(n^2)
 思路:
 简单的说就是将序列分为有序序列和无序序列。每一趟排序都是将无序序列的第一个元素插入有序序列中。R[1 … i-1]  <-  R[i … n] , 每次取R[i]插入到R[1 … i-1]中。
 
 步骤如下：
 
 1>  在R[1 … i-1]中找到R[i]的插入位置k （0 < k < i）
 
 2>  将R[k … i-1]均后移一位，K位置上插入R[i]
 
 改进版：
 
 1>    在R[1 … i-1]中将R[i]从右向左一一比较，R[j] > R[i],则R[j]后移一位（j = i-1开始）
 
 2>    如果R[j] <= R[i],则j+1 为R[i]的插入位置
 */
void insert_sort(int a[],int n)
{
    for (int i = 1; i < n; i++) {
        int temp = a[i];//哨兵
        int j = 0;
        for (j = i - 1; j >= 0 && temp < a[j]; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}
/*
 希尔排序
 是否稳定：不稳定
 平均复杂度:O(
 思路:
 算法是先将要排序的一组数按照某个增量d分成若干组，对每组中的元素进行排序，然后在用更小的增量来进行再次分组，并给每个分组重新排序，直到增量为1时，整个要排序的数被分成一组，排序结束。
 
 形象点说，例如[R1 ,R2 , R3, R4,R5,R6,R7,R8]，先增量d =len/2 =4 ,则先分成[R1 R5] ,[R2 R6] ,[R3 R7] ,[R4 R8]四组，进行组内排序；再d=d/2 =2,分成[R1 R3 R5R7] 和 [R2 R4 R6 R8]两组，组内排序；再d=d/2=1,整个数组只剩一个大的分组[R1 , R2 , R3, R4,R5,R6,R7,R8]，组内排序。全部结束。
 */
void shell_sort(int a[],int n)
{
    int d;
    int temp;
    for (d = n / 2; d > 0; d = d / 2) {
        for (int i = d; i < n; i++) {
            temp = a[i];
            int j;
            for (j = i - d; j >= 0 && temp < a[j]; j -= d) {
                a[j + d] = a[j];
            }
            a[j + d] = temp;
        }
    }
}

/*
 冒泡排序
 是否稳定:稳定
 思路:
 每一趟，从左到右，两两比较，大的（小的）后移，最后最轻的气泡到最后的位置R[i]，为最大或最小值，然后下一趟，选出次大的到R[i-1]，以此，到最后R[1]，至此全部有序。（按照递增递减都可以）
 */
void buble_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 2; j >= i; j--) {
            if (a[j + 1] < a[j]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

/*
 是否稳定:不稳定
 快速排序是一种划分交换排序，采用的是分治法的策略。该方法的基本思想是：
 
 1．先从数列中取出一个数作为基准数。
 
 2．分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。
 
 3．再对左右区间重复第二步，直到各区间只有一个数。
 
 对挖坑填数进行总结
 
 1．i =L; j = R; 将基准数挖出形成第一个坑a[i]。
 
 2．j--由后向前找比它小的数，找到后挖出此数填前一个坑a[i]中。
 
 3．i++由前向后找比它大的数，找到后也挖出此数填到前一个坑a[j]中。
 
 4．再重复执行2，3二步，直到i==j，将基准数填入a[i]中。
 */

void quick_sort(int a[], int low, int high)
{
    int i,j;
    int pivot;
    if (low < high) {
        pivot = a[low];
        i = low;
        j = high;
        
        while (i < j) {
            while (i < j && a[j] >= pivot) {
                j--;
            }
            
            if (i < j) {
                a[i++] = a[j];
            }
            
            while (i < j && a[i] <= pivot) {
                i++;
            }
            
            if (i < j) {
                a[j--] = a[i];
            }
        }
        
        a[i] = pivot;
        quick_sort(a, low, i - 1);
        quick_sort(a, i + 1, high);
    }
}

/*
 直接选择排序
 不稳定
 每一次从待排序的记录中选出关键字最小的记录，顺序的放在有序的序列的最后，直至全部记录排序完毕。
 */
void select_sort(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

/*
 堆排序
 不稳定
 堆排序是一种树形选择排序方法，它的特点是：在排序过程中，将A[n]看成是一棵完全二叉树的顺序存储结构，利用完全二叉树中双亲节点和孩子节点之间的内在关系，在当前无序区中选择关键字最大（或最小）的元素。
 
 堆的定义如下：n个关键字序列A[n]成为堆，当且仅当该序列满足：
 ①L(i) <= L(2i)且L(i) <= L(2i+1)  或者  ②L(i) >=L(2i)且L(i) >= L(2i+1)  其中i属于[1, n/2]。
 
 满足第①种情况的堆称为小根堆（小顶堆），满足第②种情况的堆称为大根堆（大顶堆）。
 
 
 
 如上的小根堆或大根堆，输出堆顶的最小（大）值之后，使得剩下的n-1个元素的序列重新建成一个新的堆，则又得到n个数中的次小（大）值，如此反复，最后得到的有序序列，这个过程就是堆排序。
 */
void swap(int *a ,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void HeapAdjust(int a[],int i)
{
    int left = 2*i+1;//左孩子节点
    int right = 2*i + 2;//右孩子节点
    int max = 0;//暂存最大元素下标
    if(left <=heapsize  && a[left] >a[i])
        max = left;
    else
        max = i;
    if(right <= heapsize&& a[right] > a[max])
        max = right;
    if(max != i)//表明当前的父节点并不是最大的
    {
        swap(&a[i],&a[max]);
        HeapAdjust(a,max);//有交换就要递归把子树也整成最大堆
    }
}

void BuildHeap(int a[],int len)
{
    int i = 0;
    heapsize = len;
    for( i = len/ 2;i >=0;i--)//非叶节点最大下标为/2
    {
        HeapAdjust(a,i);
    }
}

//堆排序对要排序的序列有个要求就是下标是从1开始到size的，而并非常用的0~size-1
void heap_sort(int a[],int len)
{
    int i;
    BuildHeap(a,len-1);//先建立初始的最大堆
    for( i = len-1;i >=1;i--)
    {
        swap(&a[0],&a[i]);//把最大的元素放到最后面
        heapsize--;//不再包括最大的元素
        HeapAdjust(a,0);
    }
    //至此数组就已经从小到大排好序了,
    
    //如果要从大到小输出，则倒着输出就行了；
    
    //而如果要将序列从大到小排序，则应建立最小堆。
    
}

/*
 归并排序
 稳定
 归并是指将若干个已排序的子文件合并成一个有序的文件。常见的归并排序有两路归并排序。它是采用分治法的。
 
 归并操作的基本步骤如下：
 1.申请两个与已经排序序列相同大小的空间，并将两个序列拷贝其中；
 2.设定最初位置分别为两个已经拷贝排序序列的起始位置，比较两个序列元素的大小，依次选择相对小的元素放到原始序列；
 3.重复2直到某一拷贝序列全部放入原始序列，将另一个序列剩下的所有元素直接复制到原始序列尾。
 
 
 
 设归并排序的当前区间是R[low..high]，三个步骤分别是：
 1.分解：将当前区间一分为二，即求分裂点
 2.求解：递归地对两个子区间R[low..mid]和R[mid+1..high]进行归并排序；
 3.组合：将已排序的两个子区间R[low..mid]和R[mid+1..high]归并为一个有序的区间R[low..high]。
 递归的终结条件：子区间长度为1（一个记录自然有序）。
 */

void Merge(int *a, int p, int q, int r)
{
//    int n1 = q-p+1;
//    int n2 = r-q;
//    int *L = new int[n1+1];
//    int *R = new int[n2+1];
//    int i, j, k;
//    for (i=0; i<n1; i++)
//    {
//        L[i] = a[p+i];
//    }
//    for (j=0; j<n2; j++)
//    {
//        R[j] = a[q+j+1];
//    }
//    L[n1] = 10000000;
//    R[n2] = 10000000;
//    for (i=0, j=0, k=p; k<=r; k++)
//    {
//        if (L[i]<=R[j])
//        {
//            a[k] = L[i];
//            i++;
//        }
//        else
//        {
//            a[k] = R[j];
//            j++;
//        }
//    }
//    delete []L;
//    delete []R;
}

void merge_sort(int *a, int p, int r)  //测试时候，参为a，0，len-1
{
    if (p<r)
    {
        int q = (p+r)/2;
        merge_sort(a, p, q);
        merge_sort(a, q+1, r);
        Merge(a, p, q, r);
    }
}

/*
 基数排序
 
 
 */
int maxbit(int data[], int n)
{
    int d = 1; //保存最大的位数
    int p = 10;
    for(int i = 0; i < n; ++i)
    {
        while(data[i] >= p)
        {
            p *= 10;
            ++d;
        }
    }
    return d;
}

void radix_sort(int data[], int n) //基数排序
{
    int d = maxbit(data, n);
    int tmp[n];
    int count[10]; //计数器
    int i, j, k;
    int radix = 1;
    for(i = 1; i <= d; i++) //进行d次排序
    {
        for(j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
        for(j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
        for(j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
        for(j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
        {
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for(j = 0; j < n; j++) //将临时数组的内容复制到data中
            data[j] = tmp[j];
        radix = radix * 10;
    }
}

int main(int argc, const char * argv[]) {
    
    int array[10] = {5, 9, 0, 1, 3, 6, 8, 7, 2, 4};
    printArray(array, 10);
//    insert_sort(array, 10);
//    shell_sort(array, 10);
//    buble_sort(array, 10);
//    quick_sort(array, 0, 9);
//    select_sort(array,10);
//    heap_sort(array, 10);
    radix_sort(array, 10);
    printArray(array, 10);
    
    return 0;
}
