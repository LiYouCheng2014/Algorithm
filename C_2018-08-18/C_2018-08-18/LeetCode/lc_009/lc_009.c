//
//  lc_009.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/26.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "lc_009.h"

#include <stdbool.h>

bool isPalindrome(int x) {
    
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }
    
    int revertedNumber = 0;
    while (x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }
    
    return x == revertedNumber || x == revertedNumber / 10;
}
