int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (numsSize < 4) {
        return NULL;
    }

    int unit = 4;
    int cap = 16;

    int **result = malloc(sizeof(int*) * cap);
    *returnColumnSizes = malloc(sizeof(int) * cap);

    // sort
    qsort(nums, numsSize, sizeof(int), cmpfunc);

    // loop and two pointers
    for (int i = 0; i < numsSize - 3; i++) {
        // check i repeat
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        for (int j = i + 1; j < numsSize - 2; j++) {
            // check j repeat
            if (j > i + 1 && nums[j] == nums[j-1]) {
                continue;
            }
            // two pointers
            for (int x = j + 1, y = numsSize - 1; x < y;) {
                int sum = nums[i] + nums[j] + nums[x] + nums[y];
                if (sum == target) {
                    // expand
                    if (cap == (*returnSize)) {
                        cap = cap * 2;
                        result = realloc(result, sizeof(int*) * cap);
                        *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * cap);
                    }
                    int *colums = malloc(sizeof(int) * unit);
                    result[*returnSize] = colums;
                    (*returnColumnSizes)[*returnSize] = unit;
                    (*returnSize)++;

                    colums[0] = nums[i];
                    colums[1] = nums[j];
                    colums[2] = nums[x];
                    colums[3] = nums[y];

                    x++;
                    while (x < y) {
                        if (nums[x] != nums[x-1]) {
                            break;
                        }
                        x++;
                    }

                } else if (sum < target) {
                    x++;
                } else {
                    y--;
                }
            }
        }
    }

    result = realloc(result, sizeof(int*) * (*returnSize));
    *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * (*returnSize));

    return result;
}
