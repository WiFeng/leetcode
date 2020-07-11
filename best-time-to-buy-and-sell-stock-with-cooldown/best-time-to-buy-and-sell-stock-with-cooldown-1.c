int max(int a, int b) {
    return a > b ? a : b;
}

int maxProfit(int* prices, int pricesSize){
    if (prices == NULL || pricesSize < 1) {
        return 0;
    }

    int result = 0;
    int dp[3];

    dp[0] = - prices[0];
    dp[1] = 0;
    dp[2] = 0;

    for (int i = 1; i < pricesSize; i++) {
        int t0, t1, t2;
        t0 = max(dp[0], dp[2] - prices[i]);
        t1 = dp[0] + prices[i];
        t2 = max(dp[2], dp[1]);
        dp[0] = t0;
        dp[1] = t1;
        dp[2] = t2;
    }

    result = max(dp[1], dp[2]);
    return result;
}