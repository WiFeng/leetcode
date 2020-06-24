class Solution {
    public int findNumberOfLIS(int[] nums) {
        int numsSize = nums.length;

        if (numsSize <= 1) {
            return numsSize;
        }

        int[] lengths = new int[numsSize];
        int[] counts = new int[numsSize];

        for (int i = 0; i < numsSize; i++) {
            lengths[i] = 1;
            counts[i] = 1;
            
            for (int j = 0; j < i; j++) {
                if (nums[i] <= nums[j]) {
                    continue;
                }
                if (lengths[j] >= lengths[i]) {
                    lengths[i] = lengths[j] + 1;
                    counts[i] = counts[j];
                } else if (lengths[j] + 1 == lengths[i]) {
                    counts[i] += counts[j];
                }
            }
        }

        int result = 0;
        int longest = 0;

        for (int i = 0; i < numsSize; i++) {
            if (lengths[i] > longest) {
                longest = lengths[i];
            }
        }

        for (int i = 0; i < numsSize; i++) {
            if (lengths[i] == longest) {
                result += counts[i];
            }
        }

        return result;
    }
}