func sortedSquares(A []int) []int {
    l := len(A)
    if l < 1 {
        return nil
    }

    ra := make([]int, l)
    ri := l - 1;

    x := 0; y := l - 1
    xv := 0; yv := 0
    for ; x <= y; {
        xv = A[x] * A[x]
        yv = A[y] * A[y]
        if yv > xv {
            ra[ri] = yv
            y--
        } else {
            ra[ri] = xv
            x++
        }
        ri--
    }
    return ra
}
