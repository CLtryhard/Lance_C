//
// Created by Lance on 2021/9/24.
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//位运算符

void bit_calculate();

void arr_access_by_pointer();

void enum_test();

void null_pointer();

void pointer_increase();

void pointer_arr();

void pointer_pointer();

void arr_as_pointer();

void callback_func();

void union_demo();

void main() {
    union_demo();
}

void bit_calculate() {
    unsigned int a = 60;    /* 60 = 0011 1100 */
    unsigned int b = 13;    /* 13 = 0000 1101 */
    int c = 0;

    c = a & b;       /* 12 = 0000 1100 */
    printf("Line 1 - c0 的值是 %d\n", c);

    c = a | b;       /* 61 = 0011 1101 */
    printf("Line 2 - c 的值是 %d\n", c);

    c = a ^ b;       /* 49 = 0011 0001 */
    printf("Line 3 - c 的值是 %d\n", c);

    c = ~a;          /*-61 = 1100 0011 */
    printf("Line 4 - c 的值是 %d\n", c);

    c = a << 2;     /* 240 = 1111 0000 */
    printf("Line 5 - c 的值是 %d\n", c);

    c = a >> 2;     /* 15 = 0000 1111 */
    printf("Line 6 - c 的值是 %d\n", c);
    return;
}

void arr_access_by_pointer() {
    /* 带有 5 个元素的整型数组 */
    double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
    double *p;
    int i;

    p = balance;
    /* 输出数组中每个元素的值 */
    printf("使用指针的数组值\n");
    for (i = 0; i < 5; i++) {
        printf("*(p + %d) : %f\n", i, *(p + i));
    }
    printf("使用 balance 作为地址的数组值\n");
    for (i = 0; i < 5; i++) {
        printf("*(balance + %d) : %f\n", i, *(balance + i));
    }
    /* 输出数组中每个元素的值 */
    printf("使用指针的数组值\n");
    printf("使用 p[i] 作为地址的数组值\n");
    for (i = 0; i < 5; i++) {
        printf("p[%d]: %f\n", i, p[i]);
    }
    return;
}

void enum_test() {
    enum color {
        red = 1, green, blue
    };

    enum color favorite_color;

    /* 用户输入数字来选择颜色 */
    printf("请输入你喜欢的颜色: (1. red, 2. green, 3. blue): ");
    scanf("%u", &favorite_color);

    /* 输出结果 */
    switch (favorite_color) {
        case red:
            printf("你喜欢的颜色是红色");
            break;
        case green:
            printf("你喜欢的颜色是绿色");
            break;
        case blue:
            printf("你喜欢的颜色是蓝色");
            break;
        default:
            printf("你没有选择你喜欢的颜色");
    }
    //将整数转换为枚举
    enum day {
        saturday,
        sunday,
        monday,
        tuesday,
        wednesday,
        thursday,
        friday
    } workday;

    int a = 1;
    enum day weekend;
    weekend = (enum day) a;  //类型转换
    //weekend = a; //错误
    printf("weekend:%d", weekend);

    return;
}

/*
*	首先记住核心概念,指针的本质是内存地址
	所以只要获取到指针就可以进行操作,不管接下来访问的地址是不是某个变量里面的数据(例如数组)
	指针用*来声明,在使用时,用*来解指针(即获取指针存储的地址值所指向的值)
	同理如 int** Pt2; 的二级指针,可以用**Pt2来访问一级指针指向的值
*/

void null_pointer() {
    int *ptr = NULL;
    printf("ptr 的地址是 %p\n", ptr);
    //如果p非空,则完成
    if (ptr) {
        printf("指针非空");
    }
    if (!ptr) {
        printf("指针为空");
    }
    return;
}

const int POINTER_INCREASE_MAX = 3;

/*	指针的每一次递增，它其实会指向下一个元素的存储单元。
	指针的每一次递减，它都会指向前一个元素的存储单元。
	指针在递增和递减时跳跃的字节数取决于指针所指向变量数据类型长度，比如 int 就是 4 个字节。*/
void pointer_increase() {
    int var[] = {10, 100, 200};
    int i, *ptr;

    /* 指针中的数组地址 */
    ptr = var;
    //ptr = &var[MAX - 1];
    for (i = 0; i < POINTER_INCREASE_MAX; i++) {
        printf("存储地址：var[%d] = %p\n", i, ptr);
        printf("存储值：var[%d] = %d\n", i, *ptr);

        /* 指向下一个位置 */
        ptr++;
        ptr--;
    }
    return;
}

#define POINTER_ARR_MAX 3

void pointer_arr() {
    int var[] = {10, 100, 200};
    int i, *ptr[POINTER_ARR_MAX];

    for (i = 0; i < POINTER_ARR_MAX; i++) {
        //赋值为整数的地址
        ptr[i] = &var[i];
    }
    for (i = 0; i < POINTER_ARR_MAX; i++) {
        printf("Value of var[%d] = %d\n", i, *ptr[i]);
    }
    const char *names[4] = {
            "Zara Ali",
            "Hina Ali",
            "Nuha Ali",
            "Sara Ali",
    };

    for (i = 0; i < 4; i++) {
        printf("Value of names[%d] = %s\n", i, names[i]);
    }
    for (i = 0; i < 4; i++) {
        printf("Value of names[%d] = %c\n", i, *names[i]);
    }

    return;
}

void pointer_pointer() {
    int V;
    int *Pt1;
    int **Pt2;

    V = 100;

    /* 获取 V 的地址 */
    Pt1 = &V;

    /* 使用运算符 & 获取 Pt1 的地址 */
    Pt2 = &Pt1;

    /* 使用 pptr 获取值 */
    printf("var = %d\n", V);
    printf("Pt1 = %p\n", Pt1);
    printf("*Pt1 = %d\n", *Pt1);
    printf("Pt2 = %p\n", Pt2);
    printf("*Pt2 = %p\n", *Pt2);
    printf("**Pt2 = %d\n", **Pt2);
    return;
}

double getAverage(int *arr, int size) {
    int i, sum = 0;
    double avg;

    for (i = 0; i < size; ++i) {
        sum += arr[i];
    }

    avg = (double) sum / size;

    return avg;
}

void arr_as_pointer() {
    /* 带有 5 个元素的整型数组  */
    int balance[5] = {1000, 2, 3, 17, 50};
    double avg;
    int sss = 2;
    int *testP = &sss;

    /* 传递一个指向数组的指针作为参数 */
    /* C语言中，当一维数组作为函数参数的时候，编译器总是把它解析成一个指向其首元素首地址的指针。*/
    avg = getAverage(testP, 5);

    /* 输出返回值  */
    printf("Average value is: %f\n", avg);
}


void populate_array(int *array, size_t arraySize, int (*getNextValue)(void)) {
    for (size_t i = 0; i < arraySize; i++) {
        array[i] = getNextValue();
    }
}

int getNextRandomValue() {
    return rand();
}

/*
	你到一个商店买东西，刚好你要的东西没有货，于是你在店员那里留下了你的电话，过了几天店里有货了，店员就打了你的电话，然后你接到电话后就到店里去取了货。在这个例子里，你的电话号码就叫回调函数，你把电话留给店员就叫登记回调函数，店里后来有货了叫做触发了回调关联的事件，店员给你打电话叫做调用回调函数，你到店里去取货叫做响应回调事件。
*/
void callback_func() {
    int myarr[10];
    populate_array(myarr, 10, getNextRandomValue);
    for (int i = 0; i < 10; i++) {
        printf("%d ", myarr[i]);
    }
    printf("\n");
    return 0;
}

union Union_Data {
    int i;
    float f;
    char str[20];
};

void union_demo() {
    union Union_Data data;
    //共用体同一时间只能使用一个内存,最后赋值的成员变量的值会占用内存位置
    data.i = 10;
    data.f = 220.5;
    strcpy(data.str, "C Programming");

    printf("data.i : %d\n", data.i);
    printf("data.f : %f\n", data.f);
    printf("data.str : %s\n", data.str);

    //分开使用则可完好输出
    data.i = 10;
    printf("data.i : %d\n", data.i);

    data.f = 220.5;
    printf("data.f : %f\n", data.f);

    strcpy(data.str, "C Programming");
    printf("data.str : %s\n", data.str);
}
