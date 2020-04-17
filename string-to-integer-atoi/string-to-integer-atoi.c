int myAtoi(char * str){
    int f = 1, n = 0, i = 0;
    long long r = 0, j = 1;
    int l = 11;
    char s[l + 1], k = 0;

    while ((k = *str++) != NULL) {
        if (i == 0 && k == '0') {
            n = 1;
            continue;
        } else if (k >= '0' && k <= '9') {
            // 0-9
            n = 1;
            s[i++] = k;

            if (i > l) {
                break;
            }
            continue;
        } else if (n < 1) {
            // +/- and ' '
            if (k == '-') {
                n = 1;
                f = -1;
                continue;
            } else if (k == '+') {
                n = 1;
                f = 1;
                continue;
            } else if (k == ' '){
                continue;
            }
        }

        break;
    }

    // s[max_length] = '\0';
    // printf("s:%s\n", s);
    // printf("i:%d\n", i);

    for (i = i - 1; i >= 0; i--, j*=10) {
        r += (s[i] - '0') * j;
    }

    r *= f;
    if (r < -1 * (1LL << 31)) {
        r = -1 * (1LL << 31);
    } else if (r > (1LL << 31) -1) {
        r = (1LL << 31) -1;
    }

    return (int)r;
}
