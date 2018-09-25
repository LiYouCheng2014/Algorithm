//
//  lc_005.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/23.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "lc_005.h"

#include <string.h>
#include <stdlib.h>

int testMin(int a, int b)
{
    return a < b ? a : b;
}

int manacher(char *s, char output[])
{
    int i, j;
    char s2[3000] = { '\0' };
    
    s2[0] = '$';
    for (i = 0; s[i] != '\0'; i++) {
        s2[(i<<1)+1] = '#';
        s2[(i<<1)+2] = s[i];
    }
    s2[(i<<1)+1] = '#';
    int len = (i<<1)+2;
    s2[len] = '\0';
    
    int p[3000] = { 0 }; // 以s2中某一点为中心的回文半径
    int id = 0; // 回文的中心点
    int limit = 0; // 最长回文的右边界点
    int maxLen = 0; // 最大回文长度
    int maxId = 0; // 最长回文的中心点
    for (i = 1; i < len; i++) {
        if (i < limit) {
            p[i] = testMin(p[2*id-i], limit-i);
        } else {
            p[i] = 1;
        }
        
        while (s2[i+p[i]] == s2[i-p[i]]) {
            p[i]++;
        }
        
        if (i+p[i] > limit) {
            limit = i+p[i];
            id = i;
        }
        if (maxLen < p[i]-1) {
            maxLen = p[i]-1;
            maxId = i;
        }
    }
    
    for (j = 0, i = maxId - maxLen; i <= maxId+maxLen; i++) {
        if (s2[i] != '#') {
            output[j++] = s2[i];
        }
    }
    return maxLen;
}

char *longestPalindrom(char *s)
{
    int i;
    if (s == NULL) {
        return NULL;
    }
    
    int len = strlen(s);
    if (len <= 1) {
        return s;
    }
    
    char *palindrome = malloc(2000);
    memset(palindrome, 0, sizeof(palindrome));
    
    int size = manacher(s, palindrome);
    palindrome[size] = '\0';
    return palindrome;
}


//char* longestPalindrome(char* s) {
//    int len = (int)strlen(s);
//    char *t = (char *)malloc(sizeof(char *) * (len * 2 + 2));
//    t[0] = '$';
//    t[1] = '#';
//
//    for (int i = 1; i < len + 1; i++) {
//        t[2 * i] = s[i - 1];
//        t[2 * i + 1] = '#';
//    }
//
//    int tlen = (int)strlen(t);
//    char *p = (char *)malloc(sizeof(char *) * tlen);
//    for (int i = 0; i < tlen; i++) {
//        p[i] = 0;
//    }
//
//    int id = 0;
//    int mx = 0;
//
//    int resMx = 0;
//    int resId = 0;
//    for (int i = 0; i < tlen; i++) {
//        p[i] = mx > i ? (p[2 * id - i] > mx - i ? mx - i : p[2 * id - i]) : 1;
//        while (t[i + p[i]] == t[i - p[i]]) {
//            ++p[i];
//        }
//
//        if (mx < i + p[i]) {
//            mx = i + p[i];
//            id = i;
//        }
//
//        if (resMx < p[i]) {
//            resMx = p[i];
//            resId = i;
//        }
//    }
//
//    char *ret = (char *)malloc(sizeof(char *) * (resMx - 1));
//    return strncpy(ret, s + (resId - resMx) / 2, resMx - 1);
//}



//char* longestPalindrome(char* s) {
//    int len = (int)strlen(s);
//    char **a;
//    a = (char **)malloc(sizeof(char *) * len);
//    for (int j = 0; j < len; j++) {
//        a[j] = (char *)malloc(sizeof(char *) * len);
//    }
//
//    for (int i = 0; i < len; i++) {
//        for (int j = 0; j < len; j++) {
//            a[i][j] = 0;
//        }
//    }
//
//    int tlen = 0;
//    int left = 0;
//    int right = 0;
//    for (int i = 0; i < len; i++) {
//        for (int j = 0; j < i; j++) {
//            a[j][i] = (s[i] == s[j] && (i - j < 2 || a[j + 1][i - 1]));
//            if (a[j][i] && tlen < i - j + 1) {
//                tlen = i - j + 1;
//                left = j;
//                right = i;
//            }
//        }
//        a[i][i] = 1;
//    }
//
//    char *ret = (char *)malloc(sizeof(char *) * (right - left + 1));
//    return strncpy(ret, s + left, right - left + 1);
//}


//void searchPalindrome(char *s, int left, int right, int *startIdx, int *len)
//{
//    int step = 1;
//    while ((left - step) >= 0 && (right + step) < strlen(s)) {
//        if (s[left - step] != s[right + step]) {
//            break;
//        }
//        ++step;
//    }
//
//    int wide = right - left + 2 * step - 1;
//    if (left < wide) {
//        *len = wide;
//        *startIdx = left - step + 1;
//    }
//}
//
//char* longestPalindrome(char* s) {
//    int startIdx = 0;
//    int left = 0;
//    int right = 0;
//    int len = 0;
//    for (int i = 0; i < strlen(s); i++) {
//        if (s[i] == s[i + 1]) {
//            left = i;
//            right = i + 1;
//            searchPalindrome(s, left, right, &startIdx, &len);
//        }
//        left = right = i;
//        searchPalindrome(s, left, right, &startIdx, &len);
//    }
//
//    if (len == 0) {
//        len = strlen(s);
//    }
//
//    char dest[100] = {""};
//
//    return strncpy(dest, s + startIdx, len);
//}

