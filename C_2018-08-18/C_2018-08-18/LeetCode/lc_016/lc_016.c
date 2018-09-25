//
//  lc_016.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/28.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "lc_016.h"

#include <stdlib.h>
#include <limits.h>

int tcompare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int threeSumClosest(int* nums, int numsSize, int target)
{
    int min_diff = INT_MAX;
    
    if (numsSize < 3) {
        return min_diff;
    }
    
    qsort(nums, numsSize, sizeof(*nums), tcompare);
    
    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;
        while (left < right) {
            int diff = nums[i] + nums[left] + nums[right] - target;
            if (abs(diff) < abs(min_diff)) {
                min_diff = diff;
            }
            
            if (diff < 0) {
                left++;
            }
            else if (diff > 0) {
                right--;
            }
            else {
                return target;
            }
        }
    }
    
    return min_diff + target;
}
