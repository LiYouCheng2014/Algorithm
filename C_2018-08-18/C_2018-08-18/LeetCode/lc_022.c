//
//  lc_022.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/9/15.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "lc_022.h"
#include <stdlib.h>
#include <string.h>

void helper(char ***pppc, int *returnSize, int n, char *res, int level, int i, int index) {
    if (index == 2 * n) {
        res[index] = '\0';
        (*returnSize)++;
        (*pppc) = (char **)realloc(*pppc, sizeof(char) * (*returnSize + 1));
        (*pppc)[*returnSize - 1] = (char *)malloc(sizeof(char) * (2 * n + 1));
        strcpy((*pppc)[*returnSize - 1], res);
        return;
    }
    
    if (i < n) {
        res[index] = '(';
        helper(pppc, returnSize, n, res, level + 1, i + 1, index + 1);
    }
    
    if (level > 0) {
        res[index] = ')';
        helper(pppc, returnSize, n, res, level - 1, i, index + 1);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    char **ppc = (char **)malloc(sizeof(char *));
    *returnSize = 0;
    char *res = (char *)malloc(sizeof(char) * (2 * n + 1));
    helper(&ppc, returnSize, n, res, 0, 0, 0);
    
    return ppc;
}
