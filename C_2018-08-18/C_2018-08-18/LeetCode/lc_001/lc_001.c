//
//  lc_001.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/21.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "lc_001.h"

#include <stdlib.h>

/*
 
 给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
 你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
 
 给定 nums = [2, 7, 11, 15], target = 9
 因为 nums[0] + nums[1] = 2 + 7 = 9
 所以返回 [0, 1]
 */

//类似字典
struct object {
    int val;
    int index;
};

//排序
static int compare(const void *a, const void *b)
{
    return ((struct object *) a)->val - ((struct object *) b)->val;
}

int *twoSum(int *nums, int numSize, int target)
{
    //类似map函数
    struct object *objs = malloc(numSize * sizeof(*objs));
    for (int i = 0; i < numSize; i++) {
        objs[i].val = nums[i];
        objs[i].index = i;
    }
    
    //排序
    qsort(objs, numSize, sizeof(*objs), compare);
    
    //存储结果
    int *results = malloc(2 * sizeof(int));
    int i = 0;
    int j = numSize - 1;
    while (i < j) {
        int diff = target - objs[i].val;
        if (diff > objs[j].val) {
            //过滤相同的值
            while (++i < j && objs[i].val == objs[i - 1].val) {}
        }
        else if (diff < objs[j].val) {
            //过滤相同的值
            while (--j > i && objs[j].val == objs[j + 1].val) {}
        }
        else {
            results[0] = objs[i].index;
            results[1] = objs[j].index;
            return results;
        }
    }
    
    return NULL;
}
