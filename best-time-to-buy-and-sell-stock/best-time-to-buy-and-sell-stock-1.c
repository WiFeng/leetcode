int max(int a, int b) {
    return a > b ? a : b;
}

int maxProfit(int* prices, int pricesSize){
    if (pricesSize < 1) {
        return 0;
    }

    int result = 0;

    int dp[2];
    dp[0] = 0;
    dp[1] = - prices[0];

    for (int i = 1; i < pricesSize; i++) {
        int t0, t1;
        t0 = max(dp[0], dp[1] + prices[i]);
        t1 = max(dp[1], - prices[i]);
        dp[0] = t0;
        dp[1] = t1;
    }

    result = dp[0];
    return result;
}