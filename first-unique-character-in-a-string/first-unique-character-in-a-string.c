int firstUniqChar(char * s){

    int r = -1;
    int m[26] = {};
    int n[26] = {};

    char c;
    int i = 0, j = 0;

    while ((c = *(s++)) != '\0') {
        i = c - 'a';
        m[i]++;
        if (m[i] == 1) {
            n[i] = j;
        }
        j++;
    }

    for (i = 0; i < 26; i++) {
        if (m[i] != 1) {
            continue;
        }

        if (r == -1 || n[i] < r) {
            r = n[i];
        }
    }

    return r;
}