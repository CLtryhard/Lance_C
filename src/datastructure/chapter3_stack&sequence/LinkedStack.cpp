//
// Created by Lance on 2021/9/24.
//
#include <stdlib.h>
#include <stdio.h>

typedef struct LinknodeWithoutF {
    int data;
    struct LinknodeWithoutF* next;
} *LinkStack;

/*用链式存储方式实现的栈*/
/*初始化,进栈,出栈,获取栈顶元素,判空判满*/
int InitStack(LinkStack &L){
    L = NULL;
    return true;
}

// 头插法
bool Push(LinkStack &L, int param) {
    LinknodeWithoutF* x = (LinknodeWithoutF*)malloc(sizeof(LinknodeWithoutF));
    if (x == NULL)
        return false;
    x->data = param;
    if (L == NULL)
    {
        x->next = NULL;
        L = x;
        return true;
    }
    x->next = L;
    L = x;
    return true;
}
// 出栈

bool Pop(LinkStack &L, int &top) {
    if (L == NULL)
    {
        return false;
    }
    LinknodeWithoutF* del;
    del = L;
    top = L->data;
    L = L->next;
    free(del);
    return true;
}

int GetTop(LinkStack& L) {
    if (L == NULL)
    {
        return NULL;
    }
    return L->data;
}

void printStack(LinkStack& L) {
    LinknodeWithoutF* node;
    node = L;
    while (node != NULL)
    {
        printf("Current Param:%d\n", node->data);
        node = node->next;
    }
    return;
}

void main() {
	LinkStack stack;
	InitStack(stack);
	Push(stack, 5);
	printf("Current Top Param:%d\n", GetTop(stack));
	Push(stack, 6);
	Push(stack, 7);
	Push(stack, 8);
	printf("Current Top Param:%d\n", GetTop(stack));
	int del;
	Pop(stack, del);
	printf("Delete Param:%d\n", del);
	printf("Current Top Param:%d\n", GetTop(stack));
	printStack(stack);
}