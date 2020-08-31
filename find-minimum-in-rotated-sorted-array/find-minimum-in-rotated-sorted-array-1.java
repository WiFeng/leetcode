class Solution {
    public int findMin(int[] nums) {
        if (nums.length < 1) {
            return 0;
        }

        int result = nums[0];
        int lo = 0, hi = nums.length - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[lo] < nums[mid]) {
                if (nums[lo] < result) {
                    result = nums[lo];
                }
                lo = mid + 1;
            } else if (nums[lo] > nums[mid]) {
                if (nums[mid] < result) {
                    result = nums[mid];
                }
                hi = mid - 1;
            } else {
                if (nums[lo] < result) {
                    result = nums[lo];
                }
                lo++;
            }
        }

        return result;
    }
}