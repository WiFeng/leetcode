func findContentChildren(g []int, s []int) int {
    var result int
    if len(g) < 1 || len(s) < 1 {
        return 0
    }

    sort.Ints(g)
    sort.Ints(s)

    var i, j int
    for ; i < len(g); i++ {
        for ; j < len(s); j++ {
            if s[j] >= g[i] {
                result++
                j++
                break
            }
        }
        if j == len(s) {
            break
        }
    }
    return result
}
