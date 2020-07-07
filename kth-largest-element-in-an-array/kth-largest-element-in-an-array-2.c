int quickSelect(int *nums, int start, int numsSize, int kk) {
    if (numsSize < 2) {
        return nums[start];
    }

    int alen = 0;
    int blen = 0;

    int pivot = start + (numsSize / 2);
    int pivotVal = nums[pivot];
    nums[pivot] = nums[start+numsSize-1];
    nums[start+numsSize-1] = pivotVal;

    for (int i = start; i < start + numsSize; i++) {
        if (nums[i] > pivotVal) {
            blen++;
        } else {
            alen++;
            int val = nums[i];
            nums[i] = nums[start+alen-1];
            nums[start+alen-1] = val;
        }
    }

    int kkk = start + alen - 1;
    if (kkk == kk) {
        return nums[kkk];
    } else if (kkk > kk) {
        return quickSelect(nums, start, alen - 1, kk);
    } else {
        return quickSelect(nums, start + alen, blen, kk);
    }
}

int findKthLargest(int* nums, int numsSize, int k){
    return quickSelect(nums, 0, numsSize, numsSize - k);
}