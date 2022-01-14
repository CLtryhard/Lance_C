//
// Created by LanceChan on 2022/1/4.
//

#include <cstdlib>
#include <iostream>
#include <opencl-c.h>
using namespace std;

/* 利用递归调用，从一颗二叉树中找出结点值为m的结点,计算其子树的深度，树结构如下 */
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
}*BiTree;

//定义一颗空树
BiTree root = nullptr;

void CreatBST(const int &a) {
    BiTree p, q, s;
    //分配结点s的内存空间
    s = (BiTree) malloc(sizeof(BiTNode));
    //将插入的值a赋值给s结点,并初始化左右孩子
    s->data = a;
    s->lchild = nullptr;
    s->rchild = nullptr;
    //判断根节点是否为空
    if (root == nullptr) {//为空
        root = s;
        return;
    } else {
        //不为空
        p = root;
        while (p) {
            //保存p指针
            q = p;
            if (p->data == a) {
                cout << "该结点已经存在，请重新输入" << endl;
                return;
            } else if (p->data > a) {
                //指向左孩子
                p = p->lchild;
            } else {
                //指向右孩子
                p = p->rchild;
            }
        }
        //插入s结点
        if (s->data > q->data)
            q->rchild = s;
        else
            q->lchild = s;
    }
}

int getDepth(BiTree &T) {
    if (T) return 0;
    return 1 + max(getDepth(T->lchild), getDepth(T->rchild));
}

int getSubTreeDepth(BiTree &node, int m) {
    //检验空值
    if (node) return 0;
    //判断数据是否为m
    if (node->data == m) {
        printf("结点值为m的子树的深度为", getDepth(node));
        exit(0);
    }
    if (node->lchild) getSubTreeDepth(node->lchild, m);
    if (node->rchild) getSubTreeDepth(node->rchild, m);
    return 0;
}

int main() {
    int x;
    CreatBST(x);
    getSubTreeDepth(root, x);
    return 0;
}