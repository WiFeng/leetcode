char * longestCommonPrefix(char ** strs, int strsSize){
    char buf[100], t1, t2, *r;
    int len = 0;

    if (strsSize < 1) {
        return "";
    }

    for (int i = 0; i >= 0; i++) {
        t1 = NULL;
        for (int j = 0; j < strsSize; j++) {
            t2 = strs[j][i];
            if (t2 == '\0') {
                i = -100;
                break;
            }
            if (t1 == NULL) {
                t1 = t2;
            } else if (t1 != t2) {
                i = -100;
                break;
            }
        }

        if (t1 != NULL && i > -100) {
            buf[len++] = t1;
        }
    }

    r = malloc(len+1);
    r[len] = '\0';
    for (int z = 0; z < len; z++) {
        r[z] = buf[z];
    }
    return r;
}
