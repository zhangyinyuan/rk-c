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
            //如果当前物品的重量已经大于背包的容量，那么当前背包在物品数量为i，并且背包容量为j时的最大价值为dp[i-1][j]
            if(w[i] > j){
                dp[i][j] = dp[i-1][j];
            } else {
                // 第i个物品不放入背包的价值
                int not_take = dp[i-1][j];
                // 第i个物品放入背包的价值
                int take = v[i] + dp[i-1][j-w[i]];
                //比较，如果放入背包后，背包的价值更大，那么在i个物品放入背包，否则不放入背包
                dp[i][j] = take > not_take ? take : not_take;
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
