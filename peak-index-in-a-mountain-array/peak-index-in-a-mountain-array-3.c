int peakIndexInMountainArray(int* A, int ASize){
    int lo = 0, hi = ASize - 1;
    while (lo < hi) {
        int mi = lo + (hi - lo) / 2;
        if (A[mi] < A[mi + 1]) {
            lo = mi + 1;
        } else {
            hi = mi;
        }
    }
    // return lo;
    return hi;
}