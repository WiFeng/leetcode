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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    if (nums1Size < 1 || nums2Size < 1) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = nums1Size > nums2Size ? nums2Size : nums1Size;
    int *result = malloc(sizeof(int) * (*returnSize));
    int actualSize = 0;
    
    quickSort(nums1, nums1Size);
    quickSort(nums2, nums2Size);

    for (int i = 0, j = 0; i < nums1Size && j < nums2Size;) {
        if (i > 0 && nums1[i] == nums1[i-1]) {
            i++;
            continue;
        }
        if (j > 0 && nums2[j] == nums2[j-1]) {
            j++;
            continue;
        }
        if (nums1[i] == nums2[j]) {
            result[actualSize++] = nums1[i];
            i++;
            j++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            i++;
        }
    }

    *returnSize = actualSize;
    result = realloc(result, sizeof(int) * (*returnSize));

    return result;
}