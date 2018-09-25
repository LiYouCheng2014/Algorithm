//
//  lc_008.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/26.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "lc_008.h"

#include <limits.h>
#include <stdlib.h>
#include <string.h>

int myAtoi(char* str) {
    
    int len = strlen(str);
    if (len <= 0) {
        return 0;
    }
    
    int i = 0;
    while (i < len && str[i] == ' ') {
        ++i;
    }
    
    int sign = 1;
    if (str[i] == '+' || str[i] == '-') {
        sign = (str[i++] == '+') ? 1 : -1;
    }
    
    int base = 0;
    while (i < len && str[i] >= '0' && str[i] <= '9') {
        if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        base = 10 * base + (str[i++] - '0');
    }
    
    return base * sign;
}

