//
//  lc_006.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/26.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "lc_006.h"

#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows <= 1) {
        return s;
    }
    
    int len = strlen(s);
    char *new_str = malloc(len + 1);
    char *p = new_str;
    
    for (int row = 0; row < numRows; row++) {
        int interval1 = numRows + (numRows - 2) - row * 2;
        int interval2 = 2 * row;
        
        int i = row;
        int flag = 0;
        while (i < len) {
            *p++ = s[i];
            int delta = 0;
            do {
                delta = flag == 0 ? interval1 : interval2;
                flag = !flag;
            } while (delta == 0);
            i += delta;
        }
    }
    
    new_str[len] = '\0';
    return new_str;
}
