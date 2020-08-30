class Solution {
    public int search(int[] nums, int target) {
        if (nums.length < 1) {
            return -1;
        }

        int lo = 0, hi = nums.length - 1;
        while (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid;
            } else if (nums[mid] > target) {
                hi = mid;
            } else {
                return mid;
            }
        }

        if (nums[lo] == target) {
            return lo;
        } else if (nums[hi] == target) {
            return hi;
        }

        return -1;
    }
}