//
// Created by Lance on 2021/9/24.
//
#include "LinkedString.cpp"

/* 朴素模式匹配,S为主串,T为模式串,最坏时间复杂度为O(mn) */
int index(SString S, SString T);

/* KMP匹配算法,S为子串,T为模式串,next为模式串预处理信息
   求next数组时间复杂度O(m),模式匹配过程最坏时间复杂度O(n)
*/
int index_KMP(SString S, SString T, int next[]);

int index(SString S, SString T) {
    // 主串与模式串的位序指针
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) {
            ++i;
            ++j;// 继续比较后继字符
        } else {
            // 主串指针回撤到下一个子串的第一个位置
            //此处为缺陷点，匹配时失败时会反复回撤
            i = i - j + 2;
            // 模式串指针重置
            j = 1;
        }
    }
    if (j > T.length) {
        return i - T.length;
    }
    // 匹配失败
    return 0;
}

/* 求不匹配时,模式串的next数组 */
void get_next(SString T, int next[]) {
    //i:当前主串指针,j:模式串指针
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            ++i;
            ++j;
            next[i] = j;//如果Pi=Pj,则next[j+1]=next[j]+1
        } else {
            j = next[j];//否则令j=next[j],循环继续
        }
    }
}

void get_nextval(SString T, int nextval[]) {
    int i = 1, j = 0;
    nextval[1] = 0;
    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            ++i;
            ++j;
            if (T.ch[i] != T.ch[j]) {
                nextval[i] = j;
            } else {
                nextval[i] = nextval[j];
            }
        } else {
            j = nextval[j];//否则令j=next[j],循环继续
        }
    }
}

int index_KMP(SString S, SString T, int next[]) {
    // 主串与模式串的位序指针
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            ++i;
            ++j;// 继续比较后继字符
        } else {
            //主串指针不回溯
            //模式串向右移动
            j = next[j];
        }
    }
    if (j > T.length) {
        return i - T.length;
    }
    // 匹配失败
    return 0;
}
