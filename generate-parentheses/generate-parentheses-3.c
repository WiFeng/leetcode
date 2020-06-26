int nextPowVal(int val) {
    int result = 1;
    while (result < val) {
        result *= 2;
    }
    return result;
}

void generate(int n, char*** result, int* returnSize, int* returnCap, int left, int right, char* str, int strLen) {
    if (strLen == 2 * n) {
        if (*result == NULL) {
            *returnCap = 1;
            *result = malloc(sizeof(char*));
        } else if (*returnSize + 1 > *returnCap) {
            *returnCap = nextPowVal(*returnSize + 1);
            *result = realloc(*result, sizeof(char*) * (*returnCap));
        }

        int newStrLen = strLen + 1;
        char *newStr = malloc(sizeof(char) * newStrLen);
        memcpy(newStr, str, newStrLen);
        (*result)[(*returnSize)++] = newStr;
        return;
    }

    if (left < n) {
        str[strLen] = '(';
        generate(n, result, returnSize, returnCap, left + 1, right, str, strLen + 1);
    }

    if (right < left) {
        str[strLen] = ')';
        generate(n, result, returnSize, returnCap, left, right + 1, str, strLen + 1);
    }
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** generateParenthesis(int n, int* returnSize){
    char **result = NULL;
    *returnSize = 0;
    int returnCap = 0;

    if (n < 1) {
        return result;
    }
    
    int strLen = n * 2 + 1;
    char *str = malloc(sizeof(char) * strLen);
    str[strLen - 1] = '\0';
    str[0] = '(';
    generate(n, &result, returnSize, &returnCap, 1, 0, str, 1);

    free(str);
    result = realloc(result, sizeof(char*) * (*returnSize));

    return result;
}