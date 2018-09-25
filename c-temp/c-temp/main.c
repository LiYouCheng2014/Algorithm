//
//  main.c
//  c-temp
//
//  Created by liyoucheng on 2018/7/23.
//  Copyright © 2018年 liyoucheng. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//#define NULLT 0
//#define TYPE struct stu
//#define LEN sizeof (struct stu)
//
//struct stu {
//    int num;
//    int age;
//    struct stu *next;
//};
//
//TYPE *creatNode(int n)
//{
//    struct stu *head = NULL;
//    struct stu *pf = NULL;
//    struct stu *pb;
//    
//    for (int i = 0; i < n; i++) {
//        pb = (TYPE *)malloc(LEN);
//        printf("input num age\n");
//        scanf("%d %d",&pb->num,&pb->age);
//        if (i == 0) {
//            pf = head = pb;
//        }
//        else {
//            pf->next = pb;
//        }
//        pb->next = NULLT;
//        pf = pb;
//    }
////    head->data = n;
//    
//    return head;
//}

int Fbi(int i)
{
    if (i < 2) {
        return i == 0 ? 0 : 1;
    }
    
    return Fbi(i - 1) + Fbi(i - 2);
}

int main(int argc, const char * argv[]) {
    
//    TYPE *student;
//    int count = 6;
//    student = creatNode(count);
//    printf("===============================\n");
//    for (int i = 0; i < count; i++) {
//        printf("%d \t%d\n",student->num,student->age);
//        student = student->next;
//    }
    
//    int a[40];
//    a[0] = 0;
//    a[1] = 1;
//    for (int i = 2; i < 40; i++) {
//        a[i] = a[i-1] + a[i-2];
//    }
//
//    for (int i = 0; i < 40; i++) {
//        printf("%d ",a[i]);
//    }
//    printf("\n");
    
    for (int i = 0; i < 40; i++) {
        printf("%d ",Fbi(i));
    }
    return 0;
}
