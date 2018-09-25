//
//  lc_003.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/21.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "lc_003.h"

#include <stdlib.h>
#include <string.h>

/*
 给定一个字符串，找出不含有重复字符的最长子串的长度。
 
 示例 1:
 
 输入: "abcabcbb"
 输出: 3
 解释: 无重复字符的最长子串是 "abc"，其长度为 3。
 示例 2:
 
 输入: "bbbbb"
 输出: 1
 解释: 无重复字符的最长子串是 "b"，其长度为 1。
 示例 3:
 
 输入: "pwwkew"
 输出: 3
 解释: 无重复字符的最长子串是 "wke"，其长度为 3。
 请注意，答案必须是一个子串，"pwke" 是一个子序列 而不是子串。
 */

int lengthOfLongestSubstring(char *s)
{
    int m[256] = {0};
    int res = 0;
    int left = 0;
    
    for (int i = 0; i < strlen(s); i++) {
        if (m[s[i]] == 0 || m[s[i]] < left) {
            if (res < i - left + 1) {
                res = i - left + 1;
            }
        }
        else {
            left = m[s[i]];
        }
        m[s[i]] = i + 1;
    }
    return res;
}
//
//int lengthOfLongestSubstring(char *s)
//{
//    int offset[128];
//    int max_len = 0;
//    int len = 0;
//    int index = 0;
//
//    memset(offset, 0xff, sizeof(offset));
//    while (*s != '\0') {
//        if (offset[*s] == -1) {
//            len++;
//        }
//        else {
//            if (index - offset[*s] > len) {
//                len++;
//            }
//            else {
//                len = index - offset[*s];
//            }
//        }
//
//        if (len > max_len) {
//            max_len = len;
//        }
//
//        offset[*s++] = index++;
//    }
//
//    return max_len;
//}
