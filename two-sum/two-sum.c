

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    for (int i=0; i<numsSize;i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                *returnSize = 2;
                int* s = malloc(sizeof(int) * 2);
                s[0] = i;
                s[1] = j;
                return s;
            }
        }

    }
    return NULL;
}


