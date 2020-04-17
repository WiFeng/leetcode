char * convert(char * s, int numRows){

    int len = 0;
    while (s[len++] != '\0') {}

    int k1 = 0, k2 = 0;
    char *r = malloc(len);

    int t = 2 * numRows-2;
    t = t > 1 ? t : 1;

    for (int i = 0; i < numRows; i++) {
        if (i >= len-1) break;
        int j= 2 * i;
        for (k2 = i; k2 < len - 1; k2 += j) {
            r[k1++] = s[k2];
            if (j == 0 || j == t) {
                j = t;
            } else {
                j = t - j;
            }
        }
    }

    r[len-1] = '\0';
    return r;
}
