//
// Created by Lance on 2021/9/28.
//
#include <cstring>
#include <cstdio>

char result[6];

typedef struct {
    int value;
} ElemType;

typedef struct {
    ElemType *elem;
    int front;
    int rear;
    int tag;
    int maxSize;
} CTagQueue;

char *StatusEnCQueue(CTagQueue &Q, ElemType x) {
    //判断是否队满
    if ((Q.rear + 1) % Q.maxSize == Q.front) {
        strcpy_s(result, "ERROR");
        return result;
    }
    *(Q.elem + Q.rear) = x;
    Q.rear = (Q.rear + 1) % Q.maxSize;
    Q.tag = 1;
    strcpy(result, "OK");
    return result;
}

int main() {
    ElemType arr[5];
    CTagQueue queue;
    queue.elem = arr;
    queue.rear = 0;
    queue.front = 0;
    queue.maxSize = 6;
    queue.tag = 0;
    ElemType param = {1};
    char* enCQueue_result = StatusEnCQueue(queue, param);
    printf("Value of var[%d] = %d\n", 0, *(arr + 0));
    printf("Value of var[%d] = %d\n", 1, *(arr + 1));
    return 0;
};