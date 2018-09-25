//
//  CircularLinkList.c
//  C_2018-08-18
//
//  Created by liyoucheng on 2018/8/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "CircularLinkList.h"

//带头结点

/*
 rearA为A的尾指针
 rearB为B的尾指针
 合并A,B都头结点
 P为A的头指针
 
 p = rearA->next;
 rearA->next = rearB->next->next;
 rearB->next = p;
 free(p);
 
 */
