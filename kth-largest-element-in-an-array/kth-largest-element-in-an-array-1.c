/*
 * @lc app=leetcode.cn id=215 lang=c
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start


void quickSort2(int *nums, int numsSize) {

    if (numsSize < 2) {
        return;
    }

    int alen = 0;
    int blen = 0;
    int *a = malloc(sizeof(int) * numsSize);
    int *b = malloc(sizeof(int) * numsSize);

    int t = numsSize / 2;
    for (int i = 0; i < numsSize; i++) {
        if (i == t) {
            continue;
        }
        if (nums[i] < nums[t]) {
            a[alen++] = nums[i];
        } else {
            b[blen++] = nums[i];
        }
    }

    quickSort2(a, alen);
    quickSort2(b, blen);

    nums[alen] = nums[t];
    memcpy(nums, a, sizeof(int) * alen);
    memcpy(nums+alen+1, b, sizeof(int) *blen);
    
    free(a);
    free(b);
}

void quickSort(int *nums, int numsSize) {
    if (numsSize < 2) {
        return;
    }

    int alen = 0;
    int blen = 0;

    int pivot = numsSize / 2;
    int pivotVal = nums[pivot];
    nums[pivot] = nums[numsSize-1];
    nums[numsSize-1] = pivotVal;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > pivotVal) {
            blen++;
        } else {
            alen++;
            int val = nums[i];
            nums[i] = nums[alen-1];
            nums[alen-1] = val;
        }
    }

    quickSort(nums, alen - 1);
    quickSort(nums + alen, blen);

}

int findKthLargest(int* nums, int numsSize, int k){
    quickSort(nums, numsSize);
    int kk = numsSize - k;
    return nums[kk];
}


// @lc code=end

