/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char m[8][4] = {
    {'a', 'b', 'c'},
    {'d', 'e', 'f'},
    {'g', 'h', 'i'},
    {'j', 'k', 'l'},
    {'m', 'n', 'o'},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v'},
    {'w', 'x', 'y', 'z'}
};

char ** letterCombinations(char * digits, int* returnSize){
    char **rc = NULL;
    *returnSize = 0;

    if (digits == NULL || digits[0] == '\0') {
        return rc;
    }

    char v;
    char s = digits[0] - '2';
    char *x = m[s];

    for (int i = 0; i < 4; i++) {
        v = x[i];
        if (v == '\0') {
            break;
        }

        char **temprc = NULL; int temprs = 0;
        int sublen = strlen(digits+1);
        temprc = letterCombinations(digits+1, &temprs);

        if (temprs < 1) {
            char *r = malloc(sizeof(char) * 2);
            int size = *returnSize + 1;
            if (rc == NULL) {
                rc = malloc(sizeof(char*));
            } else {
                rc = realloc(rc, size * sizeof(char*));
            }

            r[0] = v;
            r[1] = '\0';
            rc[*returnSize] = r;
            *returnSize = size;

        } else {

            char *r = malloc(sizeof(char) * temprs * (sublen + 2));
            if (rc == NULL) {
                rc = malloc(temprs * sizeof(char*));
            } else {
                rc = realloc(rc, (*returnSize  + temprs) * sizeof(char*));
            }

            int l = 0;
            for (int j = 0; j < temprs; j++) {
                r[0] = v;
                l = sizeof(char) * (sublen + 1);
                memcpy(r+1, temprc[j], l);

                rc[*returnSize] = r;
                *returnSize = *returnSize + 1;

                r += l + 1;
                // free(temprc[j]);
            }

            free(temprc);
        }
    }
    return rc;
}


