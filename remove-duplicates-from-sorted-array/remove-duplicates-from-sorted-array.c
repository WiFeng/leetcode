int removeDuplicates(int* nums, int numsSize){
    if (numsSize < 2) {
        return numsSize;
    }

    int k = 0, v = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != v) {
            k++;
            v = nums[i];
            if (k != i) {
                nums[k] = v;
            }
        }
    }

    return k+1;
}


