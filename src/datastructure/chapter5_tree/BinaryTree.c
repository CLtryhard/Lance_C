//
// Created by Lance on 2021/9/24.
//
#include "stdlib.h"

struct ElementType {
    int value;
};

typedef struct BiTNode {
    struct ElementType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int main() {
    //定义一颗空树
    BiTree root = NULL;
    //插入根节点
    root = (BiTree) malloc(sizeof(BiTNode));
    struct ElementType ele = {1};
    root->data = ele;
    root->lchild = NULL;
    root->rchild = NULL;
}
