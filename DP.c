#include <stdio.h>

// 定义商品的数量为4
#define N 4
// 定义背包的容量为5
#define W  5

// 定义4个商品的重量
int w[] = {0, 1, 2, 3, 4};
// 定义4个商品的价值
int v[] = {0, 2, 4, 5, 6};

int dp[N+1][W+1];

int max(int a, int b) { return a >= b ? a : b; }

int main() {
    // 当背包容量为j时,商品有N个时,背包的最大价值
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= W; ++j) {
            // 默认第i个商品不放入背包的时候,背包的最大价值
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i]) {
                dp[i][j] = max(dp[i][j], v[i] + dp[i - 1][j - w[i]]);
            }
        }
    }

    for (int i = 0; i <= N; ++i) {
        for (int k = 0; k <= W; ++k) {
            printf("%d ",dp[i][k]);
        }
        printf("\n");
    }
    printf("%d",dp[N][W]);
    return 0;
}
