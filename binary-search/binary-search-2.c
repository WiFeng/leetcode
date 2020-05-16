int search(int* nums, int numsSize, int target){
    int left = 0, right = numsSize;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target && left != mid) {
            left = mid;
        } else if (nums[mid] > target && right != mid) {
            right = mid;
        } else {
            break;
        }
    }
    return -1;
}
