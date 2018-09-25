//
//  lc_014.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/27.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "lc_014.h"

#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize)
{
    int count = 0;
    char *result = malloc(1000);
    while (1) {
        char c = strs[0][count];
        int i = 0;
        for (i = 0; i < strsSize; i++) {
            if (c != strs[i][count]) {
                break;
            }
        }
        
        if (i == strsSize && c != '\0') {
            result[count++] = c;
        }
        else {
            break;
        }
    }
    result[count++] = '\0';
    return result;
}
