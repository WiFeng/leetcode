void moveZeroes(int* nums, int numsSize){

    if (numsSize < 2) {
        return;
    }
    
    for (int i = 0, j = 1, z = 0; j < numsSize; j++) {
        if (nums[i] != 0) {
            i++;
        } else {
            if (nums[j] == 0) {
                continue;
            }
            z = nums[i];
            nums[i] = nums[j];
            nums[j] = z;
            i++;
        }
    }
}