

char * longestPalindrome(char * s){

    char *r;
    int a = 0, l = 0, t = 0;
    int i = 0, j = 0, z = 0, k = 0;

    while (s[i] != '\0') {

        if (i == 0) {
            l = 1;
            a = 0;
            goto next;
        }

        if (s[i] == s[i-1] && k < 1) {
            // bb
            t = 2;
            k = 1;
        } else if (s[i-1] == s[i+1] && k < 2) {
            // bab
            t = 3;
            k = 2;
        } else {
            t = 0;
            k = 0;
            goto next;
        }

        j = i - 2;
        if (t > 0 && j >= 0) {
            for ( ; j >= 0; j--) {
                if (s[j+t+1] == '\0' || s[j] != s[j+t+1]) {
                    break;
                }
                t = t + 2;
            }

        }

        if (t >= l) {
            l = t;
            a = j + 1;
        }

        if (k > 0)
            continue;

next:
        i++;

    }

    z = sizeof(char) * l;
    r = malloc(z + 1);
    memcpy(r, s + a, z);

    r[l] = '\0';

    return r;
}


