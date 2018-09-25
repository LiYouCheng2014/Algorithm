//
//  lc_015.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/27.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "lc_015.h"

#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void two_sum(int *nums, int low, int high, int target, int **results, int *count)
{
    while (low < high) {
        int diff = target - nums[low];
        if (diff > nums[high]) {
            while (++low < high && nums[low] == nums[low - 1]) {
                
            }
        }
        else if (diff < nums[high]) {
            while (--high > low && nums[high] == nums[high + 1]) {
                
            }
        }
        else {
            results[*count] = malloc(3 * sizeof(int));
            results[*count][0] = -target;
            results[*count][1] = nums[low];
            results[*count][2] = nums[high];
            (*count)++;
            
            while (++low < high && nums[low] == nums[low - 1]) {
                
            }
            
            while (--high > low && nums[high] == nums[high + 1]) {
                
            }
        }
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
    if (numsSize < 3) {
        return NULL;
    }
    
    qsort(nums, numsSize, sizeof(*nums), compare);
    
    *returnSize = 0;
    int capacity = 50000;
    int **results = malloc(capacity *sizeof(int *));
    for (int i = 0; i < numsSize; i++) {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
            two_sum(nums, i + 1, numsSize - 1, -nums[i], results, returnSize);
        }
    }
    
    return results;
}
