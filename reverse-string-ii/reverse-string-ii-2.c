char * reverseStr(char * s, int k){
    int len = strlen(s);
    for (int i = 0; ; i += 2 * k) {
        if (i >= len) {
            break;
        }
        if (i + k > len) {
            k = len - i;
        }
        for (int j = 0; j < k / 2; j++) {
            char c = s[i+j];
            s[i+j] = s[i+k-j-1];
            s[i+k-j-1] = c;
        }
    }
    return s;
}