int maxSubArray(int* nums, int numsSize){
    
    int result = 0;
    int temp = 0;

    if (nums == NULL || numsSize < 1) {
        return 0;
    }

    result = nums[0];
    temp = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (temp < 0) {
            if (nums[i] > result) {
                temp = nums[i];
            }
        } else if (temp >= 0 && temp + nums[i] > 0) {
            temp = temp + nums[i];
        } else {
            temp = 0;
        }

        if (temp > result) {
            result = temp;
        }
       
    }
    return result;
}