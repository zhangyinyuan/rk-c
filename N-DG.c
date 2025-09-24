#include <math.h>
#include <stdio.h>

#define N 4

int answer = 0;

// 定义1个一维数组
// 假设有4个皇后, 每个皇后占1行,
// j从1开始, 下标j表示第j个皇后,q[j]的值表示皇后的位置列.所以1个皇后的位置可以表示为 j,q[j].
// 即第j个皇后在第j行的第q[j]列
int q[N + 1];

/**
 * 检查当前皇后的位置是否合法
 * @param j 从1开始,表示当前正在被摆放的皇后的位置列
 * @return 1 表示合法;0表示不合法
 */
int check(int j) {
    for (int i = 1; i < j; i++) { //这里为什么是 i < j, 因为当前是在摆放第j个皇后,只需要与小于当前行的皇后做比较即可
        // 当前摆放的皇后的列和以往的每一个皇后在同一列,则认为不合法;
        // 或者
        // 当当前皇后的行号-每一个皇后的行号的绝对值等于两个皇后的列号的绝对值,同样认为不合法
        if (q[i] == q[j] || abs(i - j) == abs(q[i] - q[j])) {
            return 0;
        }
    }
    return 1;
}

/**
 * 求解N皇后问题
 * j  表示第j个皇后
 */
void queue(int j) {
    for (int i = 1; i <= N; ++i) {
        q[j] = i;
        if (check(j)) {
            if (j == N) {
                printf("得到一组解: ");
                for (int k = 1; k <= N; ++k) {
                    printf("%d ",q[k]);
                }
                printf("\n");
            } else {
                queue(j+1);
            }
        }
    }
}

int main() {
    // 一开始将第一个皇后放入到第一行的第一列
    queue(1);
    return 0;
}
