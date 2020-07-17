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

int maxProfit(int k, int* prices, int pricesSize){
    int fee = 0;
    int K = k;
    if (k > pricesSize / 2) {
       return genericMaxProfit(prices, pricesSize, fee);
    }
    return genericMaxProfitByK(prices, pricesSize, fee, K);
}