int min(int a, int b) {
    return a < b ? a : b;
}

int getKey(int len1, int len2, int x, int y) {
    int z = (x * len2) + y;
    return z;
}

int minDistance(char * word1, char * word2){
    int result = 0;

    int len1 = strlen(word1) + 1;
    int len2 = strlen(word2) + 1;
    int len = len1 * len2;
    int *dp = malloc(sizeof(int) * len);

    // init dp status
    for (int i = 0; i < len1; i++) {
        int z = getKey(len1, len2, i, 0);
        dp[z] = i;
    }
    for (int i = 0; i < len2; i++) {
        int z = getKey(len1, len2, 0, i);
        dp[z] = i;
    }

    // dp formula
    for (int i = 1; i < len1; i++) {
        for (int j = 1; j < len2; j++) {
            int z = getKey(len1, len2, i, j);
            if (word1[i-1] == word2[j-1]) {
                int z1 = getKey(len1, len2, i-1, j-1);
                dp[z] = dp[z1];
            } else {
                int z1 = getKey(len1, len2, i-1, j-1);
                int z2 = getKey(len1, len2, i-1, j);
                int z3 = getKey(len1, len2, i, j-1);
                dp[z] = min(min(dp[z1], dp[z2]), dp[z3]) + 1;
            }
        }
    }

    result = dp[len - 1];
    free(dp);

    return result;
}