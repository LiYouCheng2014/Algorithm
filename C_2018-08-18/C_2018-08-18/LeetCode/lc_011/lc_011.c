//
//  lc_011.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/26.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "lc_011.h"

int maxArea(int* height, int heightSize) {
    
    int min = 0;
    int max = heightSize - 1;
    int area_max = 0;
    while (min < max) {
        int area = (max - min) * (height[min] < height[max] ? height[min] : height[max]);
        area_max = area > area_max ? area : area_max;
        
        if (height[min] < height[max]) {
            while (++min < max && height[min] <= height[min - 1]) {
                continue;
            }
        }
        else {
            while (min < --max && height[max] <= height[max + 1]) {
                continue;
            }
        }
    }
    
    return area_max;
}
