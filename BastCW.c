//
// Created by Administrator on 2025/5/2.
//
#include <stdio.h>

// 解释
// int w[3][3] = {
//     {1, 2, 3},  // 部件0 在 供应商0、1、2 的重量
//     {3, 2, 1},  // 部件1 在 供应商0、1、2 的重量
//     {2, 2, 2}   // 部件2 在 供应商0、1、2 的重量
// };

// 变量定义
int n = 3;                  // 机器的部件数
int m = 3;                  // 供应商数
int cc = 4;                 // 价格上限
int w[3][3] = {{1,2,3}, {3,2,1}, {2,2,2}};  // w[i][j]：第j个供应商的第i个部件的重量
int c[3][3] = {{1,2,3}, {3,2,1}, {2,2,2}};  // c[i][j]：第j个供应商的第i个部件的价格
int bestW = 8;              // 满足价格上限的最小机器重量（初始值为足够大的值）
int bestC = 0;              // 最小重量机器的价格
int bestX[3] = {0,0,0};     // 最优解，bestX[i]表示第i个部件来自哪个供应商
int cw = 0;                 // 当前重量
int cp = 0;                 // 当前价格
int x[3] = {0,0,0};         // 当前解，x[i]表示第i个部件来自哪个供应商

// 回溯函数
void backtrack(int i) {      // i：当前考虑的部件，范围0到n-1
    if (i > n-1) {          // 终止条件：i超过n-1（题干明确i的范围是0到n-1）
        if (cp <= cc && cw < bestW) {
            bestW = cw;
            bestC = cp;
            for (int k = 0; k < n; k++) {
                bestX[k] = x[k];
            }
        }
        return;
    }

    for (int j = 0; j < m; j++) {  // 遍历供应商
        x[i] = j;                  // 选择第j个供应商的第i个部件
        cw = cw + w[i][j];             // 更新重量和价格
        cp = cp + c[i][j];
        if (cp <= cc && cw < bestW) {  // 剪枝
            backtrack(i + 1);
        }

        // 回溯
        cw = cw - w[i][j];
        cp = cp - c[i][j];
    }
}

int main() {
    backtrack(0);  // 从第0个部件开始

    // 输出结果
    printf("最小重量: %d\n", bestW);
    printf("对应价格: %d\n", bestC);
    printf("供应商选择: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", bestX[i] + 1);  // 供应商编号从1开始显示
    }
    printf("\n");
    return 0;
}