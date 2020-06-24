/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumberOfLIS = function(nums) {
    numsSize = nums.length;

    if (numsSize <= 1) {
        return numsSize;
    }

    lengths = [];
    counts = [];

    for (i = 0; i < numsSize; i++) {
        lengths[i] = 1;
        counts[i] = 1;
        for (j = 0; j < i; j++) {
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

    result = 0;
    longest = 0;

    for (i = 0; i < numsSize; i++) {
        if (lengths[i] > longest) {
            longest = lengths[i];
        }
    }

    for (i = 0; i < numsSize; i++) {
        if (lengths[i] == longest) {
            result += counts[i];
        }
    }

    return result;
};