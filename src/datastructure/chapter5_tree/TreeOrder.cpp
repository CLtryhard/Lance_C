//
// Created by Lance on 2021/9/24.
//
#include <cstdlib>

/* 先序遍历(PreOrder)
* 中序遍历(InOrder)
* 后序遍历(PostOrder)
* 层次遍历(LevelOrder)
*/

/* 二叉树的节点(链式存储) */
typedef struct BiTNode {
    char data;
    struct BiTNode *lchidld, *rchild;
} BiTnode, BiTree;

/* 链式队列节点 */
typedef struct LinkNode {
    BiTNode *data;
    struct LinkNode *node;
} LinkNode;

typedef struct {
    LinkNode *front, *rear;//队头队尾
} LinkQueue;

/* 线索二叉树节点 */
typedef struct ThreadNode {
    char data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
    //可增加父节点指针
} ThreadNode, *ThreadTree;

/* 层序遍历
   初始化辅助队列
   根节点入队
   若队列非空,则队头节点出队,访问该节点,并将其左右孩子插入队尾(如果有的话)
   重复3直至队列为空
*/
void LevelOrder(BiTree T) {
    LinkQueue Q;
    //InitQueue{ Q };
}

/* 辅助全局变量,用于查找结点p的前驱(或者也可以传引用) */
BiTNode *p;//p指向目标结点
BiTNode *pre = nullptr;//指向当前访问结点的前驱
BiTNode *final = nullptr;//用于记录最终结果
ThreadNode *threadTreePre = nullptr;

void visit(ThreadNode *q) {
    if (q->lchild == nullptr)//左子树为空,建立前驱线索
    {
        q->lchild = threadTreePre;
        q->ltag = 1;
    }
    if (threadTreePre != nullptr && pre->rchild == nullptr) {
        threadTreePre->rchild = q;
        threadTreePre->rtag = 1;
    }
    threadTreePre = q;
}

/* 中序线索化 */
void InThread(ThreadTree T) {
    if (T != nullptr) {
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}

void CreateInThread(ThreadTree T) {
    threadTreePre = nullptr;
    if (T != nullptr) {
        InThread(T);
        if (threadTreePre->rchild == nullptr) {
            threadTreePre->rtag = 1;//处理遍历的最后一个结点
        }
    }
}

/* 找到以P为根的子树中,第一个被中序遍历的结点
   中序遍历时,某节点的后驱结点必定为右子树中最左下角的结点(ltag为0时)
*/
ThreadNode *Firstnode(ThreadNode *p) {
    //循环找到最左下结点(不一定是叶子结点)
    while (p->ltag == 0) {
        p = p->lchild;
    }
    return p;
}

/* 在中序线索二叉树中找到结点p的后继结点 */
ThreadNode *NextNode(ThreadNode *p) {
    //右子树中最左下结点
    if (p->rtag == 0) {
        return Firstnode(p->rchild);
    }
    return p->rchild;
}

/* 找到以P为根的子树中,最后一个被中序遍历的结点
   中序遍历时,根节点的前驱结点必定为左子树中最右下角的结点
*/
ThreadNode *Lastnode(ThreadNode *p) {
    //循环找到最右下结点(不一定是叶子结点)
    while (p->rtag == 0) {
        p = p->rchild;
    }
    return p;
}

/* 在中序线索二叉树中找到结点p的前驱结点 */
ThreadNode *NextNode(ThreadNode *p) {
    //右子树中最左下结点
    if (p->rtag == 0) {
        return Lastnode(p->lchild);
    }
    return p->lchild;
}

/* 对中序线索二叉树进行中序遍历(利用线索实现的非递归算法)
	空间复杂度O(1)
*/
void Inorder(ThreadNode *T) {
    for (ThreadNode *pThreadNode = Firstnode(T); pThreadNode != nullptr; pThreadNode = NextNode(pThreadNode)) {
        visit(pThreadNode);
    }
}

/* 先序遍历找先序前驱:优先往右走,右边没有则往左走 */

/* 先序线索二叉树找先序后继 */
/* 先序:根左右
   有左孩子,则后继为左孩子
   有右孩子,则后继为右孩子
*/
ThreadNode *PreOrderNextNode(ThreadNode *T) {
    if (T->ltag == 0 && T->lchild != nullptr) {
        return T->lchild;
    }

    if (T->rtag == 0 && T->rchild != nullptr) {
        return T->rchild;
    }
    return nullptr;
}