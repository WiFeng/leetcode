void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void dfs(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int **result) {
    static int slow = 0;
    int fast = 0;

    if (slow == numsSize) {
        result[*returnSize] = malloc(sizeof(int) * numsSize);
        memcpy(result[*returnSize], nums, sizeof(int) * numsSize);
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
    } else {
        for (fast = slow; fast < numsSize; fast++) {
            swap(nums + slow, nums + fast);
            slow++;

            dfs(nums, numsSize, returnSize, returnColumnSizes, result);

            slow--;
            swap(nums+ slow, nums + fast);

        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (numsSize < 1) {
        return NULL;
    }

    int rs = 1;
    for (int i = numsSize; i > 0; i--) {
        rs *= i;
    }

    int **result = malloc(sizeof(int*) * rs);
    *returnColumnSizes = malloc(sizeof(int) * rs);

    dfs(nums, numsSize, returnSize, returnColumnSizes, result);

    return result;
}


