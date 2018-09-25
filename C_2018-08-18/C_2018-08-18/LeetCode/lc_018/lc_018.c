//
//  lc_018.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/28.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "lc_018.h"

#include <stdlib.h>
#include <string.h>

int scompare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void k_sum(int *nums, int low, int high, int target, int total, int k, int *stack, int len, int **results, int *count)
{
    if (k == 2) {
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
                stack[len++] = nums[low];
                stack[len++] = nums[high];
                results[*count] = malloc(total * sizeof(int));
                memcpy(results[*count], stack, total * sizeof(int));
                (*count)++;
                len -= 2;
                while (++low < high && nums[low] == nums[low - 1]) {
                    
                }
                while (--high > low && nums[high] == nums[high + 1]) {
                    
                }
            }
        }
    }
    else {
        for (int i = low; i <= high - k + 1; i++) {
            if (i > low && nums[i] == nums[i - 1]) {
                continue;
            }
            stack[len++] = nums[i];
            k_sum(nums, i + 1, high, target - nums[i], 4, k - 1, stack, len, results, count);
            len--;
        }
    }
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    if (numsSize < 4) {
        return NULL;
    }
    
    qsort(nums, numsSize, sizeof(*nums), scompare);
    
    *returnSize = 0;
    int capacity = 50000;
    int **results = malloc(capacity * sizeof(int *));
    int *stack = malloc(4 * sizeof(int));
    k_sum(nums, 0, numsSize - 1, target, 4, 4, stack, 0, results, returnSize);
    
    return results;
}
