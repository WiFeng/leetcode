func removeDuplicates(nums []int) int {
    l := len(nums)
    if l < 2 {
        return l
    }

    k := 0
    v := nums[0]
    for i := 1; i < l; i++ {
        if nums[i] != v {
            k++
            v = nums[i]
            if k != i {
                nums[k] = v
            }
        }
    }
    return k+1
}
