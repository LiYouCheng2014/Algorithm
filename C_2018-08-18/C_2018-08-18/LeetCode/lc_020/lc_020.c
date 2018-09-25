//
//  lc_020.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/28.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "lc_020.h"

#include <stdbool.h>
#include <stdlib.h>

bool isValid(char *s)
{
    int cap = 100;
    char *stack = malloc(cap);
    
    int n = 0;
    while (*s != '\0') {
        switch (*s) {
            case '(':
            case '[':
            case '{':
                if (n + 1 > cap) {
                    cap *= 2;
                    stack = realloc(stack, cap);
                }
                stack[n++] = *s;
                break;
            case ')':
                if (stack[--n] != '(') {
                    return false;
                }
                break;
            case ']':
                if (stack[--n] != '[') {
                    return false;
                }
                break;
            case '}':
                if (stack[--n] != '{') {
                    return false;
                }
                break;
            default:
                return false;
        }
        s++;
    }
    
    return n == 0;
}
