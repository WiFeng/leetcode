void generate(int n, char*** result, int* returnSize, int left, int right, char* str, int strLen) {
    if (strLen == 2 * n) {
        if (*result == NULL) {
            *result = malloc(sizeof(char*));
        } else {
            *result = realloc(*result, sizeof(char*) * (*returnSize + 1));
        }

        int newStrLen = strLen + 1;
        char *newStr = malloc(sizeof(char) * newStrLen);
        memcpy(newStr, str, newStrLen);
        
        (*result)[(*returnSize)++] = newStr;
        
        return;
    }

    if (left < n) {
        str[strLen] = '(';
        generate(n, result, returnSize, left + 1, right, str, strLen + 1);
    }

    if (right < left) {
        str[strLen] = ')';
        generate(n, result, returnSize, left, right + 1, str, strLen + 1);
    }
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