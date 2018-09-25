//
//  lc_007.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/26.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "lc_007.h"

#include <limits.h>
//#include <stdlib.h>

int reverse(int x) {
    
    int y = 0;
    while (x != 0) {
        if (y > INT_MAX / 10 || y < INT_MIN / 10) {
            return 0;
        }
        
        y = y * 10 + x % 10;
        x /= 10;
    }
    
    return y;
}
