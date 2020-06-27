/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    *returnSize = 0;

    if (digits == NULL || digitsSize < 1) {
        return NULL;
    }

    *returnSize = digitsSize;
    int *result = malloc(sizeof(int) * (*returnSize));
    int flag = 1;

    for (int i = digitsSize - 1; i >= 0; i--) {
        if (flag < 0) {
            result[i] = digits[i];
            continue;
        }

        int val = digits[i] + flag;
        if (val > 9) {
            flag = 1;
            val = val - 10;
        } else {
            flag = 0;
        }

        result[i] = val;
    }

    if (flag > 0) {
        (*returnSize)++;
        result = realloc(result, sizeof(int) * (*returnSize));
        memmove(result + 1, result, sizeof(int) * ((*returnSize) - 1));
        result[0] = 1;
    }

    return result;
}