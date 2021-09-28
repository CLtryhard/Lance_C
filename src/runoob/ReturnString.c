//
// Created by Lance on 2021/9/28.
//

#include "string.h"
#include "stdio.h"
#include "stdlib.h"

char global_var[15];

char *fun1() {
    strcpy(global_var, "let me test1");
    return global_var;
}

char *fun2(char* param) {
    strcpy(param, "let me test2");
    return param;
}

/* 将局部变量返回,但局部变量的生存期只在fun3块内,故无法正常返回 */
char *fun3() {
    char str[15];
    strcpy(str,"let me test3");
    return str;
}

char *fun4() {
    char *str;
    str = (char *)malloc(30);
    strcpy(str,"let me test4");
    return str;
}

char *fun5() {
    static char static_str[15];
    strcpy(static_str,"let me test5");
    return static_str;
}

int main() {
    char main_str[15];
    char *funReturnResult;
    funReturnResult = fun5();
    printf("%s\n", funReturnResult);
//    free(funReturnResult);
}
