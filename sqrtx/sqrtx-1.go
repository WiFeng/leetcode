func mySqrt(x int) int {
    left := 0
    right := x
    
    for left <= right {
        mid := (left + right) / 2
        var sqrt int64 = int64(mid * mid)
        if sqrt == int64(x) {
            return mid
        } else if sqrt < int64(x) {
            left = mid + 1
        } else {
            right = mid - 1
        }
    }
    return right
}
