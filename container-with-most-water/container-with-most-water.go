func maxArea(height []int) int {
    var m int
    var z, t int
    var l bool
    var j = len(height) - 1

    for i := 0; i< j; {
        l = true
        z = height[i]
        if z > height[j] {
            l = false
            z = height[j]
        }
        t = (j - i) * z
        if m < t {
            m = t
        }
        if l {
            i++
        } else {
            j--
        }
    }

    return m
}
