#include <stdio.h>

void merge(int arr[], int begin, int mid, int end) {
    int left_len = mid - begin + 1;
    int right_len = end - mid;
    int left[left_len], right[right_len];

    // Copy data to temp arrays
    //把指定区间的数据拷贝到 左右两个数组中. 那么arr就可以置换出来了.也就不依赖arr了
    //换言之,arr的[begin,end]区间,可以直接覆盖值.少定义1个目标临时数组
    for (int i = 0; i < left_len; i++)
        left[i] = arr[begin + i];
    for (int j = 0; j < right_len; j++)
        right[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[begin..end]
    //定义目标数字从begin位置开始依次放入数据
    //这里选择新定义1个变量k,并且把begin赋值给k,避免造成begin污染
    //i<做集合的length,同理右边也是.为了防止数组越界
    //当这个循环结束后.说明至少有1边的数组已经全部放入到了目标数组.那么只需要将另外1个数组的剩余部分全部依次放入目标数组即可
    int i = 0, j = 0, k = begin;
    while (i < left_len && j < right_len) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    // Copy remaining elements of left[] if any
    while (i < left_len) {
        arr[k++] = left[i++];
    }

    // Copy remaining elements of right[] if any
    while (j < right_len) {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int begin, int end) {
    if (begin < end) {
        int mid = begin + (end - begin) / 2;  // Avoid potential overflow
        mergeSort(arr, begin, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, begin, mid, end);
    }
}

int main() {
    int arr[] = {90, 1, 10, 5, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}