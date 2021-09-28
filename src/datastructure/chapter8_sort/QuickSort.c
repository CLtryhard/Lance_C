//
// Created by Lance on 2021/9/27.
//

#include "stdlib.h"
#include "math.h"
#include "stdio.h"

void printArr(int arr[]);

void QuickSort(int arr[], int low, int high);

int getPivot(const int *arr, int low, int high);

int main() {
    int arr[] = {87, 38, 65, 49, 76, 13, 27, 97};
    printf("init arr:");
    printArr(arr);
    QuickSort(arr, 0, 7);
}

/* 选择一个元素作为基准元素(枢轴),将待排序序列划分成左右两个部分 */
int Partition(int arr[], int low, int high) {
    if (low == high) return low;
    // 1.从序列头尾和中间三个元素中选取中间元素作为基准元素
    int pivot = arr[low];
//    int pivot_num = getPivot(arr, low, high);
//    int pivot = arr[pivot_num];
    // 2.从两边遍历元素,将比基准元素小的元素移动到左端,大的放在右端,用low,high确定基准元素在序列中的最终位置
    while (low < high) {
        // 从右边往左寻找比基准元素小的元素
        while (low < high && arr[high] >= pivot) high--;
        // 找到后将元素放入左边
        arr[low] = arr[high];
        // 从左边往左寻找比基准元素大的元素
        while (low < high && arr[low] <= pivot) low++;
        // 找到后将元素放入右边
        arr[high] = arr[low];
    }
    // 3.将基准元素放到最终位置
    arr[low] = pivot;
    // 4.返回存放基准元素的最终位置
    return low;
}

void QuickSort(int arr[], int low, int high) {
    if (low >= high) return;
    // 划分
    int pivot_position = Partition(arr, low, high);
    printArr(arr);
    // 划分左子表
    QuickSort(arr, low, pivot_position - 1);
    // 划分右子表
    QuickSort(arr, pivot_position + 1, high);
}

/* 有bug */
int getPivot(const int *arr, int low, int high) {
    int pivot;
    if (high - low > 3) {
        int mid = floor((double) (low + high) / 2);
        if (arr[low] > arr[high]) {
            int pivot_num = arr[mid] > arr[low] ? low : mid;
            return pivot_num;
        }
        int pivot_num = arr[mid] > arr[high] ? low : high;
        return pivot_num;
    }
    return low;
}

void printArr(int arr[]) {
    printf("[");
    for (int i = 0; i < 8; ++i) {
        if (i == 7) {
            printf("%d", arr[i]);
            break;
        }
        printf("%d ", arr[i]);
    }
    printf("]\n");
}
