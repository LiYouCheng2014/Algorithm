//
//  main.c
//  C-0020
//
//  Created by LiYouCheng on 2018/6/25.
//  Copyright © 2018年 Liyoucheng. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "Parenthesis.h"

bool isValid(char* s) {
//    '('，')'，'{'，'}'，'['，']'
    //会越界
    char p[99999] = {};
    int k = 0;
    p[k] = '\0';
    for (int i = 0; i < strlen(s); i++) {
        //入栈
        if (s[i] == '(') {
            p[k++] = s[i];
            p[k] = '\0';
        }
        else if (s[i] == '{') {
            p[k++] = s[i];
            p[k] = '\0';
        }
        else if (s[i] == '[') {
            p[k++] = s[i];
            p[k] = '\0';
        }
        
        if (s[i] == ')') {
            if (k > 0 && p[k-1] == '(') {
                //出栈
                k--;
                p[k]='\0';
            }
            else {
                return false;
            }
        }
        else if (s[i] == '}') {
            if (k > 0 && p[k-1] == '{') {
                //出栈
                k--;
                p[k]='\0';
                
            }
            else {
                return false;
            }
        }
        else if (s[i] == ']') {
            if (k > 0 && p[k-1] == '[') {
                //出栈
                k--;
                p[k]='\0';
                
            }
            else {
                return false;
            }
        }
    }
    
    if (k > 0) {
        return false;
    }
    else {
        return true;
    }
}

/*
 括号匹配
 1.若是左括号，则将其位置序号进入栈中
 2.若是右括号，则从栈中弹出一个左括号与之匹配。如果栈已为空，表示多了一个右括号
 
 所有字符扫描检查之后，若栈中还有数据，表示还有左括号没有右括号与之匹配
 */

int main(int argc, const char * argv[]) {
//    ()[]{}
//    (]
//    {[]}
//    ()
//    char *s = "(]";
//    printf("%d\n",isValid(s));

    
    char expr[MAXLENGTH];
    printf("输入一个带括号的表达式（长度不超过%d个字符):",MAXLENGTH);
    scanf("%s",expr);
    
    int ret = ParenthesisMatch(expr);
    printf("ret=>%d\n",ret);
    getchar();
    
    return 0;
}
