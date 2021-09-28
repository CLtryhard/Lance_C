//
// Created by Lance on 2021/9/24.
//
#include <stdlib.h>
#include <stdio.h>

#define ONE_BETY_MAX_LEN 255

/* 串的顺序存储,舍弃第一个位置ch[0],另外声明一个成员变量存放Length */
typedef struct {
    //按串长存储区,ch指向串的基地址
    char *ch;
    //串的长度
    int length;

    void InitString(SString &S) {
        //用malloc函数申请一片连续的存储空间
        S.ch = (char *) malloc(ONE_BETY_MAX_LEN * sizeof(char));
        S.length = 0;
    }
} SString;

typedef struct StringNode {
    char ch[4]; //每个结点存多个字符
    struct StringNode *next;
} StringNode, *String;

/* 求子串,用sub返回串S的第pos个字符起长度为len的子串 */
bool SubString(SString &Sub, SString S, int pos, int len);

/* 比较操作,若S<T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0 */
int StrCompare(SString S, SString T);

/* 定位操作.若主串S中存在与串T值相同的子串,则返回它在主串S中第一次出现的位置;否则函数值为0 */
int index(SString S, SString T);

int INDEX_KMP(SString S, SString T, int next[]);

bool SubString(SString &Sub, SString S, int pos, int len) {
    //子串范围越界
    if (pos + len - 1 > S.length) {
        return false;
    }
    for (int i = pos; i < pos + len; i++) {
        Sub.ch[i - pos + 1] = S.ch[i];
    }
    Sub.length = len;
    return true;
}

int StrCompare(SString S, SString T) {
    for (int i = 0; i < S.length && T.length; i++) {
        if (S.ch[i] != T.ch[i]) {
            return S.ch[i] - T.ch[i];
        }
    }
    //扫描过的所有字符都相同,则长度长的串更大
    return S.length - T.length;
}

int index(SString S, SString T) {
    int i = 1, n = S.length, m = T.length;
    SString sub;//用于暂存子串
    while (i <= n - m + 1) {
        SubString(sub, S, i, m);
        if (StrCompare(sub, T) != 0) {
            ++i;
        } else {
            return i;//返回子串在主串中的位置
        }
    }
    // S中不存在与T相等的子串
    return 0;
}

int INDEX_KMP(SString S, SString T, int next[]) {
    int i = 1, n = S.length, m = T.length;
    SString sub;//用于暂存子串
    while (i <= n - m + 1) {
        SubString(sub, S, i, m);
        if (StrCompare(sub, T) != 0) {
            ++i;
        } else {
            return i;//返回子串在主串中的位置
        }
    }
    // S中不存在与T相等的子串
    return 0;
}
