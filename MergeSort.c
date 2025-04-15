#include <stdio.h>

/**
 * 归并排序分为3部分
 * 1. 拆分
 * 2. 求解
 * 3. 合并
 * @return
 */
void merge(int arr[], int low, int mid, int high) {
    int len = sizeof(arr) / sizeof(arr[0]);
    int tmpArr[len];
    for (int i = low; i <= high; ++i) {
        tmpArr[i] = arr[i];
    }
    int i = low;  //表示左边数组移动的指针(下标)
    int j = mid +1; //表示右边数组移动的指针
    int k = low; //表示目标数组拜访位置的指针
    while (i <= mid && j <= high) {
        if(tmpArr[i] <= tmpArr[j]){
            arr[k++] = tmpArr[i++];
        } else{
            arr[k++] = tmpArr[j++];
        }
    }
    while (i <= mid) arr[k++] = tmpArr[i++];
    while (j <= high) arr[k++] = tmpArr[j++];
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[5] = {4, 3, 6, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr,0, n-1);
    for (int i = 0; i < n; ++i) {
        printf("%d ,", arr[i]);
    }
    return 0;
}
