#include <stdio.h>
#include <math.h>

# define N 4
// 皇后的位置从1开始, 元素的下标表示行号, 元素的值表示列
int q[N + 1];

int check(int j) {
    for (int i = 1; i < j; ++i) {
        //拿当前皇后跟它之前的每一个皇后作比较. 如果位置在同一列或者同一斜线上,则不合法
        if (q[i] == q[j] || (abs(i - j) == abs(q[i] - q[j]))) {
            return 0;
        }
    }
    return 1;
}

void queue() {
    int j = 1;
    while (j >= 1) {
        q[j] = q[j] + 1;
        while (q[j] <= N && !check(j)) {
            q[j] = q[j] + 1;
        }
//        printf("[%d,%d]",j, q[j]);
        if (q[j] <= N) { //表示第j个皇后的位置小于等于N
            if (j == N) {//最后1个皇后
                //找到一组解
                printf("找到一组解: ");
                for (int i = 1; i <= N; ++i) {
                    printf("%d ", q[i]);
                }
                printf("\n");
            } else {
                j++;
            }
        } else {
            q[j] = 0;
            j--;
        }
    }
}

int main() {
    for (int i = 1; i <= N; ++i) {
        q[i] = 0;
    }
    queue();
    return 0;
}


