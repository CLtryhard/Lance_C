//
// Created by Lance on 2021/10/28.
// 在计算机科学中，并查集（英文：Disjoint-set data structure，直译为不交集数据结构）是一种数据结构，用于处理一些不交集（Disjoint sets，一系列没有重复元素的集合）的合并及查询问题。
//
#include "DataStructuresStd.h"
#include <cstdlib>

typedef struct {
    int *parent;//双亲数组,其中数组下标表示元素,数组存储对应元素所属树的双亲结点的位序,当为-1时,表示是树的根节点.
    int n;//森林中结点数目
} PForest, MFSet;//森林、并查集

/* 构造由n个单元素子集构成的并查集S */
Status InitMFSet(MFSet &S, int n);

/* 销毁并查集S */
Status DestroyMFSet(MFSet &S);

/* 查找元素i在并查集中所属的子集,并返回其代表元 */
int FindMFSet(MFSet &S, int i);

/* 判断并查集S中元素i和j是否同属于一个子集,若是返回TURE,否则返回FALSE */
Status DiffMFSet(MFSet &S, int i, int j);

/* 合并并查集S中元素i和j所属的两个子集 */
Status UnionMFSet(MFSet &S, int i, int j);

/* 加权合并规则法(Weighted Union Rule):将小树合入大树,同时将根节点存储的数改为该数所含结点的负数,此方法可以将树的整体深度限制在O(log N). */
Status UnionMFSet_WUR(MFSet &S, int i, int j);

/* 路径压缩法(Path Compression):在每次查找的过程中,同时将查找路径上的每个结点的双亲位标值改为根节点 */
Status FindMFSet_PC(MFSet &S, int i);

int main() {
    return 0;
}

/* 各功能具体实现 */
Status InitMFSet(MFSet &S, int n) {
    int i;
    S.parent = (int *) malloc(n * sizeof(int));
    if (nullptr == S.parent) return OVERFLOW;
    for (i = 0; i < n; ++i) S.parent[i] = -1; //每个元素自成一棵树
    S.n = n;
    return OK;
}

int FindMFSet(MFSet &S, int i) {
    if (i < 0 || i >= S.n) return -1; //元素i不存在
    while (S.parent[i] >= 0) i = S.parent[i];
    return i; //返回代表元
}

Status UnionMFSet(MFSet &S, int i, int j) {
    int ri, rj;
    if (i < 0 || i >= S.n || j < 0 || j >= S.n) return FALSE; //元素i或j不存在
    //找i和j所在树的根节点
    /* 合并操作需要查找元素所属子树,则合并操作所需时间主要取决于查找的长度,即树的长度,可以通过加权合并规则法和路径压缩法降低树的高度 */
    ri = FindMFSet(S, i);
    rj = FindMFSet(S, j);
    if (ri == rj) return FALSE; //属于同一子集,无须合并
    S.parent[ri] = rj; //把根节点ri的双亲结点改为rj,实现合并
    return TRUE;
}

Status UnionMFSet_WUR(MFSet &S, int i, int j) {
    int ri, rj;
    if (i < 0 || i >= S.n || j < 0 || j >= S.n) return FALSE; //元素i或j不存在
    //找i和j所在树的根节点
    ri = FindMFSet(S, i);
    rj = FindMFSet(S, j);
    if (ri == rj) return FALSE; //属于同一子集,无须合并
    if (S.parent[ri] > S.parent[rj]) { //比较的是结点个数的负数
        //j所在子树(大树)不小于i所在子树(小树),则i并入j
        S.parent[rj] += S.parent[ri];//大树累加小树双亲位标的值
        S.parent[ri] = rj; //将元素i所在的子集并到元素j所在子集,i子树代表元的双亲位标改为j子树的根节点
    } else {
        //i所在子树不小于j所在子树,则j并入i
        S.parent[ri] += S.parent[rj];
        S.parent[rj] = ri; //将元素j所在的子集并到元素i所在子集
    }
    return TRUE;
}

Status FindMFSet_PC(MFSet &S, int i) {
    if (i < 0 || i >= S.n) return -1;
    if (S.parent[i] < 0) return i; //找到根节点
    S.parent[i] = FindMFSet_PC(S, S.parent[i]); //i的双亲结点置为根节点
    return S.parent[i];
}
