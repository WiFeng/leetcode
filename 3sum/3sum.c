void quickSort(int* nums, int size) {

    int a[size], b[size], alen = 0, blen = 0;

    int r = rand() % size;
    int v = nums[r];

    for (int i = 0; i < size; i++) {
        if (r == i) continue;
        if (nums[i] < nums[r]) {
            a[alen++] = nums[i];
        } else {
            b[blen++] = nums[i];
        }
    }

    if (alen > 1) {
        quickSort(a, alen);
    }
    if (blen > 1) {
        quickSort(b, blen);
    }
    for (int j = 0; j < alen; j++) {
        nums[j] = a[j];
    }
    nums[alen] = v;
    for (int j = 0; j < blen; j++) {
        nums[alen + 1 + j] = b[j];
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

    int **returnColumn = NULL;
    int *columnSizes = NULL;

    int *column = NULL;
    int *size = NULL;

    *returnSize = 0;

    // check array length
    if (numsSize < 3) {
        return returnColumn;
    }

    // array sort
    quickSort(nums, numsSize);

    // first pointer
    int x = 0, y = 0, z = 0, t = 0;
    for (x = 0; x < numsSize - 2; x++) {
        // break;

        // check x repeat
        if (x > 0 && nums[x] == nums[x-1]) {
            continue;
        }

        // check x > 0
        if (nums[x] > 0) {
            break;
        }

        // other two pointer
        y = x + 1;
        z = numsSize - 1;
        while (y < z) {

            // check x + y > 0
            if (nums[x] +  nums[y] > 0) {
                break;
            }

            t = nums[x] + nums[y] + nums[z];
            if (t > 0) {
                z--;
            } else if (t < 0) {
                y++;
            } else {
                column = malloc(3 * sizeof(int));
                column[0] = nums[x];
                column[1] = nums[y];
                column[2] = nums[z];

                if ((*returnSize) == 0) {
                    *returnSize = 1;
                    returnColumn = malloc(sizeof(int*));
                    columnSizes = malloc(sizeof(int));
                } else {
                    *returnSize = (*returnSize) + 1;
                    returnColumn = realloc(returnColumn, sizeof(int*) * (*returnSize));
                    columnSizes = realloc(columnSizes, sizeof(int) * (*returnSize));
                }
                returnColumn[*returnSize - 1] = column;
                columnSizes[*returnSize - 1] = 3;

                // check y repeat
                y++;
                while(y < numsSize - 1 && nums[y-1] == nums[y]) {
                    y++;
                }
                // check z repeat
                while(z > y && nums[z-1] == nums[z]) {
                    z--;
                }

            }
        }
    }

    *returnColumnSizes = columnSizes;
    return returnColumn;
}
