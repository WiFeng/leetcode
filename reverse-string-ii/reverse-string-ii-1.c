char * reverseStr(char * s, int k){

    int len = 0;
    char *r = NULL;

    if (s == NULL) {
        return r;
    }
    
    while (s[len] != '\0') {
        len++;
    }

    r = malloc(sizeof(char) * (len + 1));
    r[len] = '\0';

    for (int i = 0, j = 0; i < len;) {
        if (j == 0) {
            // reverse
            int t = k - 1;
            if (i + t >= len) {
                t = len - 1 - i;
            }
            for (int m = t, n = i; m >= 0; m--, n++) {
                r[n] = s[i+m];
            }
            i += k;
            j = k;
        } else {
            // normal
            r[i] = s[i];
            i++;
            j--;

        }

        
    }

    return r;
}