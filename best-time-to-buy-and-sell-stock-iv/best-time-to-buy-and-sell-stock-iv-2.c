int max(int a, int b) {
    return a > b ? a : b;
}

int genericMaxProfit(int* prices, int pricesSize, int K) {
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
            t0 = max(dp[k][0], dp[k][1] + prices[i]);
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

    int K = k;
    if (k > pricesSize) {
        K = pricesSize / 2 + 1;
    }

    return genericMaxProfit(prices, pricesSize, K);
}