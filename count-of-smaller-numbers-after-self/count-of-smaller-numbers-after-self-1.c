void merge(int *nums, int left, int mid, int right, int* result, int* index, int* temp, int* tempIndex) {
    int i = left, j = mid + 1, p = left;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[p] = nums[i];
            tempIndex[p] = index[i];
            result[index[i]] += j - (mid + 1);
            i++;
            p++;
        } else {
            temp[p] = nums[j];
            tempIndex[p] = index[j];
            j++;
            p++;
        }
    }

    while (i <= mid) {
        temp[p] = nums[i];
        tempIndex[p] = index[i];
        result[index[i]] += right - mid;
        i++;
        p++;
    }

    while (j <= right) {
        temp[p] = nums[j];
        tempIndex[p] = index[j];
        j++;
        p++;
    }

    for (int k = left; k <= right; k++) {
        nums[k] = temp[k];
        index[k] = tempIndex[k];
    }
}

void mergeSort(int* nums, int left, int right, int* result, int* index, int* temp, int* tempIndex) {
    if (left == right) {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid, result, index, temp, tempIndex);
    mergeSort(nums, mid + 1, right, result, index, temp, tempIndex);

    if (nums[mid] <= nums[mid+1]) {
        return;
    }

    merge(nums, left, mid, right, result, index, temp, tempIndex);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countSmaller(int* nums, int numsSize, int* returnSize){

    int* result = calloc(sizeof(int), numsSize);
    *returnSize = numsSize;

    if (nums == NULL || numsSize < 1) {
        return NULL;
    }

    int* index = malloc(sizeof(int) * numsSize);
    int* temp = malloc(sizeof(int) * numsSize);
    int* tempIndex = malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i++) {
        index[i] = i;
    }

    mergeSort(nums, 0, numsSize - 1, result, index, temp, tempIndex);

    free(index);
    free(temp);
    free(tempIndex);

    return result;
}