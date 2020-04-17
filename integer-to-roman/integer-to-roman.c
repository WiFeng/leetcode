char * intToRoman(int num){
    char *r, buf[16];
    int len = 0, val = 0;

    char s[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int  v[7] = {1,   5,   10,  50,  100, 500, 1000};

    for (int i = 6; i >= 0; i -= 2) {
        val = num / v[i];
        num = num % v[i];
        if (val < 1) {
        } else if (val < 4) {
            for (int j = 0; j < val; j++) {
                buf[len++] = s[i];
            }
        } else if (val < 5) {
            buf[len++] = s[i];
            buf[len++] = s[i+1];
        } else if (val < 9) {
            buf[len++] = s[i+1];
            for (int j = 0; j < val - 5; j++) {
                buf[len++] = s[i];
            }
        } else {
            buf[len++] = s[i];
            buf[len++] = s[i+2];
        }
    }

    r = malloc(len + 1);
    r[len] = '\0';
    for (int z = 0; z < len; z++) {
        r[z] = buf[z];
    }

    return r;
}
