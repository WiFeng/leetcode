void generate(int n, char*** result, int* returnSize, int left, int right, char* str, int strLen) {
    if (strLen == 2 * n) {
        if (*result == NULL) {
            *result = malloc(sizeof(char*));
        } else {
            *result = realloc(*result, sizeof(char*) * (*returnSize + 1));
        }
        (*result)[(*returnSize)++] = str;
        
        return;
    }

    if (left < n) {
        int newStr1Len =  n * 2 + 1;
        char *newStr1 = malloc(sizeof(char) * newStr1Len);
        memcpy(newStr1, str, newStr1Len);
        newStr1[strLen] = '(';
        generate(n, result, returnSize, left + 1, right, newStr1, strLen + 1);
    }

    if (right < left) {
        int newStr2Len =  n * 2 + 1;
        char *newStr2 = malloc(sizeof(char) * newStr2Len);
        memcpy(newStr2, str, newStr2Len);
        newStr2[strLen] = ')';
        generate(n, result, returnSize, left, right + 1, newStr2, strLen + 1);
    }

    free(str);
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** generateParenthesis(int n, int* returnSize){
    char **result = NULL;
    *returnSize = 0;

    if (n < 1) {
        return result;
    }

    int strLen = n * 2 + 1;
    char *str = malloc(sizeof(char) * strLen);
    str[strLen - 1] = '\0';
    str[0] = '(';
    generate(n, &result, returnSize, 1, 0, str, 1);

    return result;
}