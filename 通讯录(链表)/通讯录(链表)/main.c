//
//  main.c
//  通讯录(链表)
//
//  Created by LiYouCheng on 2018/7/5.
//  Copyright © 2018年 Liyoucheng. All rights reserved.
//

#include <stdio.h>

#include "ChainListTest.h"
#include "ChainListTest.c"

int main(int argc, const char * argv[]) {
    
    ChainListType *node;
    ChainListType *head = NULL;
    DATA data;
    char key[15];
    char findKey[15];
    
    printf("姓名、姓名、年龄，输入0则退出\n");
    do {
        fflush(stdin);
        scanf("%s",data.key);
        if (strcmp(data.key, "0") == 0) {
            break;
        }
        scanf("%s%d",data.name,&data.age);
        head = ChainListAddEnd(head, data);
    } while (1);
    
    printf("共有%d个节点\n",ChainListLength(head));
    ChainListAll(head);
    
    return 0;
}
