//
//  lc_010.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/26.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "lc_010.h"

#include <stdbool.h>
#include <string.h>

bool isMatch(char* s, char* p) {
    
    if (*p == '\0') {
        return *s == '\0';
    }
    
    if (*(p + 1) == '\0' || *(p + 1) != '*') {
        if (*s == '\0' || (*p != '.' && *s != *p)) {
            return false;
        }
        else {
            return isMatch(s + 1, p + 1);
        }
    }
    
    int len = strlen(s);
    int i = -1;
    while (i < len && (i < 0 || *p == '.' || *p == *(s + i))) {
        if (isMatch(s + i + 1, p + 2)) {
            return true;
        }
        i++;
    }
    return false;
}
