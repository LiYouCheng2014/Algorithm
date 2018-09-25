//
//  main.c
//  leetcode
//
//  Created by LiYouCheng on 2018/7/30.
//  Copyright © 2018年 Liyoucheng. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#include "SeqStackTest.h"

#include "CalcExp.h"

#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int SElemType;

typedef struct
{
    SElemType *base;
    SElemType *top;
    int StackSize;
}SqStack;

typedef int Status;

Status InitStack(SqStack *S)
{
    S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S->base) {
        return ERROR;
    }
    S->top = S->base;
    S->StackSize = STACK_INIT_SIZE;
    
    return OK;
}

Status TPush(SqStack *S,SElemType e)
{
    if (S->top - S->base >= S->StackSize) {
        S->base = (SElemType *)realloc(S->base, (S->StackSize + STACKINCREMENT) * sizeof(SElemType));
        if (!S->base) {
            return ERROR;
        }
        S->top = S->base + S->StackSize;
        S->StackSize += STACKINCREMENT;
    }
    
    *S->top++ = e;
    return OK;
}

Status TGetTop(SqStack *S,SElemType *e)
{
    if (S->top == S->base) {
        return ERROR;
    }
    *e = *(S->top - 1);
    
    return OK;
}

int StackLength(SqStack *S)
{
    int length;
    length = (int)(S->top - S->base);
    return length;
    
}

Status TPop(SqStack *S,SElemType *e)
{
    if (S->top == S->base) {
        return ERROR;
    }
    
    *e = *--S->top;
    
    return OK;
}

Status StackEmpty(SqStack *S)
{
    if (S->top == S->base) {
        return TRUE;
    }
    else {
        return ERROR;
    }
}

Status ClearStack(SqStack *S)
{
    S->top = S->base;
    return OK;
}

//void parse(char *input, char *output)
//{
//    char *p = input;
//    char *q = output;
//
//    while (*p != '\0') {
//        int count = 1;
//        while (p[0] == p[1]) {
//            count++;
//            p++;
//        }
//
//        /* reverse number */
//        int n = 0;
//        while (count > 0) {
//            n += count % 10;
//            count /= 10;
//        }
//
//        /* parse count */
//        while (n > 0) {
//            *q++ = (n % 10) + '0';
//            n /= 10;
//        }
//
//        *q++ = p[0];
//        p++;
//    }
//
//    *q = '\0';
//}
//
//char *countAndSay(int n)
//{
//    if (n < 1) {
//        return NULL;
//    }
//
//    char *result = NULL;
//    char *prev = malloc(10000);
//    char *next = malloc(10000);
//    strcpy(prev, "1");
//
//    if (n == 1) {
//        return prev;
//    }
//
//    for (int i = 2; i <= n; i++) {
//        if (i & 0x1) {
//            parse(next, prev);
//            result = prev;
//        } else {
//            parse(prev, next);
//            result = next;
//        }
//    }
//
//    return result;
//}

int main(int argc, const char * argv[]) {
    
//    SqStack S;
//    InitStack(&S);
//
//    int e1,e2,e3,e4,e5;
//    printf("请输入五个数\n");
//    scanf("%d%d%d%d%d",&e1,&e2,&e3,&e4,&e5);
//
//    TPush(&S, e1);
//    TPush(&S, e2);
//    TPush(&S, e3);
//    TPush(&S, e4);
//    TPush(&S, e5);
//
//    SElemType e;
//    TGetTop(&S, &e);
//    printf("栈顶=%d\n",e);
//
//    while (!StackEmpty(&S)) {
//        TPop(&S, &e);
//        printf("%d \n",e);
//    }
//    TPop(S, &e);
//    TGetTop(S, &e);
//    printf("栈顶2=%d\n",e);
    
//    int c;
//    char exp[80];
//    printf("请输入要计算的表达式以=结束\n");
//    scanf("%s",exp);
//    printf("%s%d\n",exp,CalcExp(exp));
//    getchar();
    
//    SeqStack *stack;
//    DATA data,data1;
//    stack = SeqStackInit();
//    printf("入栈操作\n");
//    printf("请输入姓名 年龄进行入栈操作\n");
//    scanf("%s%d",data.name,&data.age);
//    SeqStackPush(stack, data);
//
//    printf("入栈操作\n");
//    printf("请输入姓名 年龄进行入栈操作\n");
//    scanf("%s%d",data.name,&data.age);
//    SeqStackPush(stack, data);
//
//    printf("出栈操作\n按任意键进行出栈\n");
//    getchar();
//
//    data1 = SeqStackPop(stack);
//    printf("出栈数据(%s,%d)\n",data1.name,data1.age);
//    printf("按任意键进行出栈\n");
//    getchar();
//
//    data1 = SeqStackPop(stack);
//    printf("出栈数据(%s,%d)\n",data1.name,data1.age);
//
//    //释放栈
//    SeqStackFree(stack);
//    getchar();
    
//    int i=0;
//    Stack p;
//    Stack *s;
//    s = &p;
//    // struct stack s;
//    //初始化栈
//    printf("\n###########初始化栈###########\n");
//    init(s);
//    printf("----------------------------------");
//    //入栈操作
//    printf("\n###########入栈操作###########\n");
//    for(i=0;i<=10;i++)
//    {
//        Push(s,i);
//    }
//    printf("----------------------------------");
//    printf("\n###########取栈顶元素###########\n");
//    printf("%d\n",Top(s));
//    printf("----------------------------------");
//    //出栈操作
//    printf("\n###########出栈操作###########\n");
//    for(i=0;i<=10;i++)
//    {
//        printf("%d\n",Top(s));
//        Pop(s);
//    }
//    printf("----------------------------------");
//    printf("\n###########取栈顶元素###########\n");
//    Top(s);
//    printf("----------------------------------");
//    printf("\n###########销毁栈###########\n");
//    Push(s,10);
//    Destroy(s);
//    Top(s);

//    char *s1 = "1010";
//    printf("s1 = %s\n",s1 + 1);
//    char *s2 = "1011";
//    char *res = addBinary(s1, s2);
//    printf("%s",res);
//    printf("\n");
//
//
    //前序 DLR ABDGHCEIF
    //中序 LDR GDHBAEICF
    //后序 LRD GHDBIEFCA
    //
    
//    int e,i;
//    int TextData[6] = {9,2,8,1,7,6};
//    SqStack Sa;
//    InitStack(&Sa);//初始化栈Sa;
//    for(i = 0; i < 6; i++){
//        Push(&Sa,TextData[i]);
//    }
//    printf("**************栈基本操作*************\n");
//    //初始化数据
//    printf("初始化后的Sa：");
//    PrintfStack(&Sa);
//
//    //得到栈顶元素
//    GetElem(&Sa,&e);
//    printf("Sa栈顶元素是：%d\n",e);
//
//    //初始化数据
//    printf("顶部出栈后Sa：");
//    Pop(&Sa,&e);
//    PrintfStack(&Sa);
    
    //    int level = 1;
    //    BiTree T = NULL;
    //    printf("请以前序遍历的方式输入扩展二叉树：\n"); //类似输入AB#D##C##
    //    //ABDG##H###CE#I##F##
    //    createBiTree(&T);
    //
    //    printf("递归前序遍历输出为：\n");
    //    PreOrdertraverse(T, level);
    //
    //    printf("递归中序遍历输出为：\n");
    //    InOrderTraverse(T, level);
    //
    //    printf("递归后序遍历输出为：\n");
    //    PostOrderTraverse(T, level);
    return 0;
}

//struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
//};

//dfs
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (!p && !q) {
//        return true;
//    }
//
//    if ((p && !q) || (!p && q) || (p->val != q->val)) {
//        return false;
//    }
//
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}

////二叉树
//typedef struct BiTNode
//{
//    char data;
//    struct BiTNode *lchild;
//    struct BiTNode *rchild;
//}BiTNode, *BiTree;
//
//void createBiTree(BiTree *T)
//{
//    char ch;
//    scanf("%c",&ch);
//    if (ch == '#') {
//        *T = NULL;
//    }
//    else {
//        *T = (BiTree)malloc(sizeof(BiTNode));
//        (*T)->data = ch;
//        createBiTree(&(*T)->lchild);
//        createBiTree(&(*T)->rchild);
//    }
//}
//
//void operation(char ch, int level)
//{
//    printf("%c在第%d层\n",ch,level);
//}
//
////前序
//void PreOrdertraverse(BiTree T,int level)
//{
//    if (T == NULL) {
//        return;
//    }
//    operation(T->data, level);
//    PreOrdertraverse(T->lchild, level+1);
//    PreOrdertraverse(T->rchild, level+1);
//}
//
////中序
//void InOrderTraverse(BiTree T,int level)
//{
//    if (T == NULL) {
//        return;
//    }
//    InOrderTraverse(T->lchild, level+1);
//    operation(T->data, level);
//    InOrderTraverse(T->rchild, level+1);
//}
//
////后序
//void PostOrderTraverse(BiTree T, int level)
//{
//    if (T == NULL) {
//        return;
//    }
//    PostOrderTraverse(T->lchild, level+1);
//    PostOrderTraverse(T->rchild, level+1);
//    operation(T->data, level);
//}


