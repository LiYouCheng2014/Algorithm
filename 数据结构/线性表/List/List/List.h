//
//  List.h
//  List
//
//  Created by liyoucheng on 2018/10/8.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef List_h
#define List_h

#include <stdio.h>

typedef struct ListElmt_
{
    void *data;
    struct ListElmt_ *next;
}ListElmt;

typedef struct List_
{
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    ListElmt *head;
    ListElmt *tail;
}List;

//初始化
void list_init(List *list, void (*destroy)(void *data));
//释放动态分配
void list_destroy(List *list);
//插入到element后一个，插入到链表头部
int list_ins_next(List *list, ListElmt *element, const void *data);
//删除element后一个，移除链表头元素
int list_rem_next(List *list, ListElmt *element, void **data);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element)==(list)->head ? 1 : 0)
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)

#endif /* List_h */
