//
// Created by Administrator on 2025/5/17.
//
#include <stdio.h>
#include <stdlib.h>

void shellSort(int data[], int n) {
    int *delta, k, i, t, dk, j;
    k = n;
    delta = (int *) malloc(sizeof(int) * (n / 2));
    i = 0;
    int count = 0;
    do {
        k = k / 2;
        delta[count] = k;
        ++count;
    } while (k > 1);
    i = 0;
    while (i < count) {
        dk = delta[i];
        for (k = dk; k < n; ++k) {
            if (data[k - dk] > data[k]) { // 前面的数值大于后面的数值
                t = data[k]; // 临时变量存小的数值(后面的小, 存后面的值)
                for (j = k - dk; j >= 0 && t < data[j]; j -= dk) { // 对之前的数值扫描一遍, 对比执行直接插入
                    data[j + dk] = data[j];
                }
                data[j + dk] = t;
            }
        }
        printf("第%d趟后序列为: ", (i + 1));
        for (int l = 0; l < n; ++l) {
            printf("%d ", data[l]);
        }
        printf("\n");
        ++i;
    }
}

int main() {
    int arr[] = {15, 9, 7, 8, 20, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    shellSort(arr, n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}
