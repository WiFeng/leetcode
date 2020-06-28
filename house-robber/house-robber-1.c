int rob(int* nums, int numsSize){
    if (nums == NULL || numsSize < 1) {
        return 0;
    }

    int result = nums[0];
    int dp[2] = {0, nums[0]};

    for (int i = 1; i < numsSize; i++) {
        int temp = 0;
        if (dp[0] + nums[i] > dp[1]) {
            temp = dp[0] + nums[i];
        } else {
            temp = dp[1];
        }
        if (temp > result) {
            result = temp;
        }
        dp[0] = dp[1];
        dp[1] = temp;
    }

    return result;
}