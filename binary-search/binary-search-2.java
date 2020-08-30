class Solution {
    public int search(int[] nums, int target) {
        if (nums.length < 1) {
            return -1;
        }

        int lo = 0, hi = nums.length - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else if (nums[mid] > target) {
                hi = mid - 1;
            } else {
                return mid;
            }
        }

        if (hi >= 0 && nums[hi] == target) {
            return hi;
        }

        return -1;
    }
}