

int lengthOfLongestSubstring(char * s){

    int h[256] = {0};
    int k, i = 0, j = 0, r = 0, t = 0, p = 0;

    while (s[i] != '\0') {
        k = s[i];
        if (h[k] > 0) {
            p = h[k] - 1;
            h[k] = i + 1;

            j = i - t;
            while (j < p) {
                k = s[j];
                h[k] = 0;
                j++;
            }

            if (t > r) r = t;
            t = i - p;
        } else {
            h[k] = i + 1;
            t++;
        }
        i++;
    }

    if (t > r)
        r = t;

    return r;
}


