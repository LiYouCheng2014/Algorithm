//
//  lc_013.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/27.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "lc_013.h"

int roman_to_integer(char c)
{
    switch(c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int romanToInt (char *s)
{
    int result = roman_to_integer(s[0]);
    for (int i = 1; s[i] != '\0'; i++) {
        int prev = roman_to_integer(s[i-1]);
        int curr = roman_to_integer(s[i]);
        if (prev < curr) {
            result = result - prev + (curr - prev);
        }
        else {
            result = result + curr;
        }
    }
    
    return result;
}
