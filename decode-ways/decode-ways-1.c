int numDecodings(char * s){
    
    if (s == NULL || s[0] == '0') {
        return 0;
    }

    int dp[2] = {1, 1};

    for (int i = 1; s[i] != '\0'; i++) {
        int tmp = 0;
        if (s[i] == '0') {
            if (s[i-1] == '1' || s[i-1] == '2') {
                tmp = dp[0];
            } else {
                return 0;
            }
        } else if (s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '1' && s[i] <= '6')) {
            tmp = dp[0] + dp[1];
        } else {
            tmp = dp[1];
        }
        dp[0] = dp[1];
        dp[1] = tmp;
    }

    return dp[1];
}