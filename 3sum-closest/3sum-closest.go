func threeSumClosest(nums []int, target int) int {
    sn := nums
    sort.Ints(sn)
    l := len(sn)

    init := false
    sum := 0; tempSum := 0
    diff := 0; tempDiff := 0

    for x := 0; x < l - 2; x++ {
        y := x + 1
        z := l - 1
        for ;y < z; {
            tempSum = sn[x] + sn[y] + sn[z]
            if tempSum > target {
                z--
                tempDiff = tempSum - target
            } else if tempSum < target {
                y++
                tempDiff = target - tempSum
            } else {
                return target
            }
            if !init {
                init = true
                sum = tempSum
                diff = tempDiff
                continue
            }
            if tempDiff < diff {
                sum = tempSum
                diff = tempDiff
            }
        }
    }

    return sum;
}
