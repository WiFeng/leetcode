int longestCommonSubsequence(char * text1, char * text2){
    
    int len1 = strlen(text1) + 1;
    int len2 = strlen(text2) + 1;
    int len = len1 * len2;
    int *dp = calloc(sizeof(int), len);

    for (int i = 1; i < len1; i++) {
        for (int j = 1; j < len2; j++) {
            int z = (i * len2) + j;
            if (text1[i - 1] == text2[j - 1]) {
                // dp[z] = dp[i-1][j-1] + 1;
                int t = ((i-1) * len2) + (j-1);
                dp[z] = dp[t] + 1;
            } else {
                // int m1 = dp[i][j-1];
                // int m2 = dp[i-1][j];
                int t1 = (i * len2) + (j-1);
                int t2 = ((i-1) * len2) + j;
                int m1 = dp[t1];
                int m2 = dp[t2];
                if (m1 > m2) {
                    dp[z] = m1;
                } else {
                    dp[z] = m2;
                }
            }
        }
    }

    int result = dp[len1 * len2 - 1];
    free(dp);

    return result;
}