//
//  String.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/19.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "StringTest.h"

#include <String.h>

void get_next(char *T,int *next)
{
    int i = 1;
    int j = 0;
    next[1] = 0;
    while (i < 6) {
        if (j == 0 || T[i] == T[j]) {
            ++i;
            ++j;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
    
    for (int i = 0; i < sizeof(next) / sizeof(next[0]); i++) {
        printf("%d ",next[i]);
    }
    printf("\n");
}
