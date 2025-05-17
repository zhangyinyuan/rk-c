#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#define N 4
// N x N 的棋盘摆放N皇后.用下标1表示第1个皇后的行号,列1表示皇后的列.
// 由于从下标1开始存放皇后,所以要摆放4个皇后, 结合数组的下标从0,得到数组的下标是N+1
int q[N + 1];

/**
 * 检查第i行第j列的皇后位置是否合法
 * @param j 第j个皇后
 * @return 1表示合法,0表示不合法
 */
int check(int j) {
    for (int i = 1; i < j; ++i) {
        if (q[i] == q[j] || abs(i - j) == abs(q[i] - q[j])) {
            return 0;
        }
    }
    return 1;
}

void queue(int j) {
    for (int i = 1; i <= N; ++i) {
        q[j] = i;
        if (check(j)) {
            if (j == N ) {
                //找到一组N皇后解
                for (int i = 1; i <=N ; ++i) {
                    printf("%d, ", q[i]);
                }
                printf("\n");
            } else {
                queue(j + 1);
            }
        }
    }
}

int main() {
    for (int i = 1; i <= N; ++i) {
        q[i] = 0;
    }
    // queue(1);

    int j = 1;
    while (j >=1) {
        q[j] = q[j] +1 ;
        while (q[j] <= N && !check(j)) {
            q[j] = q[j] + 1;
        }
        if (q[j] <= N) {
            if (j == N) {
                for (int i = 1; i <=N ; ++i) {
                    printf("%d, ", q[i]);
                }
                printf("\n");
            } else {
                j ++;
            }
        } else {
            q[j] = 0;
            j--;
        }
    }
    return 0;
}
