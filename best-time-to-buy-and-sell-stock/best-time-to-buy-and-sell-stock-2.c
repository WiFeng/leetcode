/**
 * Dynamic Programming
 * 
 * 第一种情况，不考虑操作次数限制，也就是不限制操作次数
 * 
 * dp[i][1] 第 i 天操作结束后，持有
 * dp[i][0] 第 i 天操作结束后，不持有
 * 
 * dp[0][1] = 0 - prices[0]
 * dp[0][0] = 0
 * 
 * 1. 当天交易完 持有， dp[i][1] = max(a, b) = max(dp[i-1][1], dp[i-1][0] - prices[i])
 *      a. 前一天已经持有，今天未交易 dp[i][1] = dp[i-1][1]
 *      b. 前一天不持有，今天买入 dp[i][1] = dp[i-1][0] - prices[i]
 * 2. 当天交易完 不持有，dp[i][0] = max(a, b) = max(dp[i-1][0], dp[i-1][1] + prices[i])
 *      a. 前一天不持有，今天未交易 dp[i][0] = dp[i-1][0]
 *      b. 前一天持有，今天卖出 dp[i][0] = dp[i-1][1] + prices[i]
 * 
 * 3. 结果，dp[n-1][0]
 * 
 * 第二种情况，考虑操作次数，最大操作次数为 K ，也就是需要再加一维空间，来保存状态
 * 
 * dp[i][k][1]
 * dp[i][k][0]
 * 
 * k=0,1,2
 * dp[i][0][1]
 * dp[i][1][1]
 * dp[i][2][1]
 * 
 * k=0,1,2
 * dp[i][0][0]
 * dp[i][1][0]
 * dp[i][2][0]
 * 
 * 1. 当天交易完 持有， dp[i][k][1] = max(a, b) = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
 *      a. 前一天已经持有，今天未交易 dp[i][k][1] = dp[i-1][k][1]
 *      b. 前一天不持有，今天买入 dp[i][k][1] = dp[i-1][k-1][0] - prices[i]
 * 2. 当天交易完 不持有，dp[i][k][0] = max(a, b) = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
 *      a. 前一天不持有，今天未交易 dp[i][k][0] = dp[i-1][k][0]
 *      b. 前一天持有，今天卖出 dp[i][k][0] = dp[i-1][k][1] + prices[i]
 * 
 */

#define INT_MAX 2^31-1
#define INT_MIN -2^31

int max(int a, int b) {
    return a > b ? a : b;
}

int genericMaxProfit(int* prices, int pricesSize, int fee) {

    if (pricesSize < 1) {
        return 0;
    }

    int result = 0;

    int dp[2];
    dp[0] = 0;
    dp[1] = - prices[0];

    for (int i = 1; i < pricesSize; i++) {
        int t0, t1;
        t0 = max(dp[0], dp[1] + prices[i] - fee);
        t1 = max(dp[1], dp[0] - prices[i]);
        dp[0] = t0;
        dp[1] = t1;
    }

    result = dp[0];
    return result;
}

int genericMaxProfitByK(int* prices, int pricesSize, int fee, int K) {
    int maxProfit = 0;

    if (pricesSize < 1) {
        return 0;
    }

    int **dp = malloc(sizeof(int*) * (K+1));
    int *dpData = calloc(sizeof(int), (2 * (K+1)));
    for (int p = 0; p < (K+1); p++) {
        dp[p] = dpData + (p*2);
    }

    for (int i = 0; i < pricesSize; i++) {
        for (int k = 1; k < K+1; k++) {
            // base case
            if (i == 0) {
                dp[k][0] = 0;
                dp[k][1] = - prices[0];
                continue;
            }

            // dp formula
            int t0, t1;
            t0 = max(dp[k][0], dp[k][1] + prices[i] - fee);
            t1 = max(dp[k][1], dp[k-1][0] - prices[i]);
            dp[k][0] = t0;
            dp[k][1] = t1;
        }
    }

    maxProfit = dp[K][0];

    free(dp);
    free(dpData);

    return maxProfit;
}

int maxProfit(int* prices, int pricesSize){
    int fee = 0;
    int K = 1;
    return genericMaxProfitByK(prices, pricesSize, fee, K);
}