int dpCache(int *m, char *s1, char *s2, int l1, int l2, int i, int j) {
    if (i >= l1 || j >= l2) {
        return 0;
    }

    int x = i * l2 + j;
    if (m[x] == -1) {
        m[x] = dp(m, s1, s2, l1, l2, i, j);
    }
    return m[x];
}

int dp(int *m, char *s1, char *s2, int l1, int l2, int i, int j) {
    if (s1[i] == '\0' || s2[j] == '\0') {
        return 0;
    }

    if (s1[i] == s2[j]) {
        return dpCache(m, s1, s2, l1, l2, i + 1, j + 1) + 1;
    }

    int m1 = dpCache(m, s1, s2, l1, l2, i, j + 1);
    int m2 = dpCache(m, s1, s2, l1, l2, i + 1, j);
    if (m1 > m2) {
        return m1;
    } else {
        return m2;
    }
}

int longestCommonSubsequence(char * text1, char * text2){
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    int len = len1 * len2;
    int *m = malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        m[i] = -1;
    }

    int result = dpCache(m, text1, text2, len1, len2, 0, 0);
    free(m);
    return result;
}