//
// Created by Lance on 2021/9/24.
//

#include <stdlib.h>
#include <stdio.h>
#include "SequenceList.h"

#define InitSize 10    //默认最大长度
typedef struct {
    //int data[MaxSize];	//用静态的"数组"存放数据元素
    int *data;    //指示动态分配数组的指针
    int MaxSize;    //顺序表的最大容量
    int length;    //顺序表的当前长度
} SeqList;    //顺序表的类型定义(此处练习动态分配的方式)

void InitList(SeqList &L) {
    //用malloc函数申请一片连续的存储空间
    L.data = (int *) malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

void IncreaseSize(SeqList &L, int len) {
    if (len == NULL || len <= 0) {
        len = (1.5 * L.MaxSize) + 1;
    }
    int *p = L.data;
    // malloc函数返回一个指针,需要强制转型为顺序表指针的数据类型
    printf("即将进行扩容!扩容后的大小为%d\n", len);
    L.data = (int *) malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++) {
        L.data[i] = p[i];    //将数据复制到新区域
    }
    L.MaxSize = L.MaxSize + len;    //顺序表最大长度增加len
    free(p);    //释放原来的内存空间
}

bool ListInsert(SeqList &L, int i, int element) {
    if (i < 1 || i > L.length + 1) {
        printf("非法插入位置:%d!\n", i);
        return false;
    }
    //如果当前存储空间已满,则进行自动扩容
    if (L.length == L.MaxSize) {
        printf("空间已满,将进行扩容!\n");
        IncreaseSize(L, 0);
    }
    //将第i个元素及之后的元素后移
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = element;
    L.length++;
    printf("元素:%d 插入成功!\n", element);
    return true;
}

bool ListDelete(SeqList &L, int i) {
    if (i < 1 || i > L.length) {
        printf("非法入参:%d!\n", i);
    }
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    printf("元素:%d, 次序:%d 删除成功!\n", L.data[i], i);
    return true;
}

void printList(SeqList L) {
    printf("当前集合大小为:%d\n", L.length);
    for (int i = 0; i < L.length; i++) {
        printf("当前元素为:%d, 次序为:%d\n", L.data[i], i);
    }
}

int main() {
    SeqList L;    //声明一个顺序表
    InitList(L);    //初始化顺序表
    //插入元素
    ListInsert(L, 1, 1234);
    ListInsert(L, 2, 2345);
    ListInsert(L, 3, 3345);
    ListInsert(L, 4, 4345);
    ListInsert(L, 5, 5345);
    printList(L);
    ListInsert(L, 8, 3345);
    ListInsert(L, 3, 9999);
    printList(L);
    ListDelete(L, 9);
    ListDelete(L, 3);
    printList(L);
    return 0;
}
