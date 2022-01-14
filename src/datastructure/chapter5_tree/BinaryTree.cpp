//
// Created by Lance on 2021/9/24.
//
#include <cstdlib>
#include "DataStructuresStd.h"

struct ElementType {
    int value;
};

typedef struct BiTNode {
    struct ElementType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void InitBiTree(BiTree &T);

//创建一颗二叉树T,其中根节点的值为value,L和R分别作为左子树和右子树
BiTree MakeBiTree(ElementType root, BiTree L, BiTree R);

//销毁二叉树
Status DestroyBiTree(BiTree &T);

//对二叉树判空.若为空则返回TURE,否则返回FALSE
Status BiTreeEmpty(BiTree &T);

//将一颗二叉树T分解成根、左子树和右子树3个部分
Status BreakBiTree(BiTree &T, BiTree &L, BiTree &R);

//替换左子树.若T非空,则用LT替换T的左子树,并用LT返回T的原有左子树
Status ReplaceLeft(BiTree &T, BiTree &LT);

//替换右子树,若T非空,则用RT替换T的右子树,并用RT返回T的原有右子树
Status ReplaceRight(BiTree &T, BiTree &RT);

int main() {
    //定义一颗空树
    //插入根节点
    BiTree root;
    InitBiTree(root);
    struct ElementType ele = {1};
    root->data = ele;
    root->lchild = nullptr;
    root->rchild = nullptr;
}

void InitBiTree(BiTree &T){
    T = (BiTree) malloc(sizeof(BiTNode));
}

BiTree MakeBiTree(ElementType root, BiTree L, BiTree R){
    //创建一颗二叉树T,其中根节点的值为e,L和R分别作为左子树和右子树
    BiTree t;
    t = (BiTree) malloc(sizeof(BiTNode));
    if (nullptr==t) return nullptr;
    t->data = root;    //根节点的值为root
    t->lchild = L;  //L作为t的左子树
    t->rchild = R;  //R作为R的右子树
    return t;
}

Status ReplaceLeft(BiTree &T, BiTree &LT){
    BiTree temp;
    if (nullptr == T) return ERROR;
    temp = T->lchild;
    T->lchild = LT;
    LT = temp;
    return OK;
}

Status ReplaceRight(BiTree &T, BiTree &RT){
    BiTree temp;
    if (nullptr == T) return ERROR;
    temp = T->rchild;
    T->rchild = RT;
    RT = temp;
    return OK;
}

Status DestroyBiTree(BiTree &T){
    if (T) return OK;
    DestroyBiTree(T->rchild);
    DestroyBiTree(T->rchild);
    return OK;
}