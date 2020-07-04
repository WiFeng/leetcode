int dp(char *s1, char *s2, int i, int j) {
    if (s1[i] == '\0' || s2[j] == '\0') {
        return 0;
    }

    if (s1[i] == s2[j]) {
        return dp(s1, s2, i + 1, j + 1) + 1;
    }

    int m1 = dp(s1, s2, i, j + 1);
    int m2 = dp(s1, s2, i + 1, j);
    if (m1 > m2) {
        return m1;
    } else {
        return m2;
    }
}

int longestCommonSubsequence(char * text1, char * text2){
    return dp(text1, text2, 0, 0);
}