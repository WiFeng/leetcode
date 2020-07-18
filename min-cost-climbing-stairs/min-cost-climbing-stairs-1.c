int min(int a, int b) {
    return a < b ? a : b;
}

int minCostClimbingStairs(int* cost, int costSize){
    int result = 0;
    int dp[2] = {0};
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < costSize; i++) {
        int t = min(dp[0], dp[1]) + cost[i];
        dp[0] = dp[1];
        dp[1] = t;
    }

    result = min(dp[0], dp[1]);
    return result;
}