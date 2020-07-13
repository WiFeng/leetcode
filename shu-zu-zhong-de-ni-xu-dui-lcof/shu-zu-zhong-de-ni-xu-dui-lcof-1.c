
int merge(int* nums, int left, int mid, int right, int* temp) {

    int c = 0;
    int i = left, j = mid + 1, p = left;
    
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[p] = nums[i];
            c += j - mid - 1;
            i++;
            p++;
        } else {
            temp[p] = nums[j];
            j++;
            p++;
        }
    }

    while (i <=  mid) {
        temp[p] = nums[i];
        c += right - mid;
        i++;
        p++;
    }

    while (j <= right) {
        temp[p] = nums[j];
        j++;
        p++;
    }

    for (int k = left; k <= right; k++) {
        nums[k] = temp[k];
    }

    return c;
}

int mergeSort(int* nums, int left, int right, int* temp) {
    if (left == right) {
        return 0;
    }

    int c1, c2, c3;
    int mid = left + (right - left) / 2;

    c1 = mergeSort(nums, left, mid, temp);
    c2 = mergeSort(nums, mid + 1, right, temp);

    if (nums[mid] <= nums[mid+1]) {
        return c1 + c2;
    }

    c3 = merge(nums, left, mid, right, temp);
    return c1 + c2 + c3;
}

int reversePairs(int* nums, int numsSize){
    if (numsSize < 2) {
        return 0;
    }

    int result = 0;
    int *temp = malloc(sizeof(int) * numsSize);

    result = mergeSort(nums, 0, numsSize - 1, temp);
    free(temp);

    return result;
}