#include <stdio.h>

int arr_size;

void printArr(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int partition(int a[], int low, int high) {
    if (low < high) {
        int pivot = a[high]; // 以最后1个元素为基准元素
        while (low < high) {
            // 从前往后比
            while (low < high) {
                if (a[low] > pivot) {
                    a[high] = a[low];
                    high--;
                    break;
                }
                low++;
            }
            // 从后往前比
            while (low < high) {
                if (a[high] < pivot) {
                    a[low] = a[high];
                    low++;
                    break;
                }
                high--;
            }
        }
        a[low] = pivot;
        printArr(a,arr_size);
    }
    return low;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pivot = partition(a, low, high);
        quickSort(a, low, pivot - 1);
        quickSort(a, pivot + 1, high);
    }
}

int main() {
    // int a[] = {7, 3, 1, 6};
    int a[] = {2,8,7,1,3,5,6,4};
    int size = sizeof(a) / sizeof(a[0]);
    arr_size = size;
    quickSort(a, 0, size - 1);
    printArr(a,size);
    return 0;
}
