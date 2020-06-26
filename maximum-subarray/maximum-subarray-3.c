int maxSubArray(int* nums, int numsSize){
    
    int result = 0;
    int temp = 0;

    if (nums == NULL || numsSize < 1) {
        return 0;
    }

    result = nums[0];
    temp = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (temp > 0) {
            temp += nums[i];
        } else {
            temp = nums[i];
        }

        if (temp > result) {
            result = temp;
        }
    }
    return result;
}