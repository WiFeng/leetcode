int maxSubArray(int* nums, int numsSize){
    
    int result = 0;
    int temp = 0;

    if (nums == NULL || numsSize < 1) {
        return 0;
    }

    result = nums[0];
    temp = nums[0];

    for (int i = 1; i < numsSize; i++) {
        // f(i) = max{f(i-1) + nums[i], nums[i]}
        if (temp + nums[i] < nums[i]) {
            temp = nums[i];
        } else {
            temp = temp + nums[i];
        }

        if (temp > result) {
            result = temp;
        }
    }
    return result;
}