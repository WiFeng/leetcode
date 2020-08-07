int peakIndexInMountainArray(int* A, int ASize){
    int result = 0;
    for (int i = 1; i < ASize; i++) {
        if (A[i] < A[i-1]) {
            result = i-1;
            break;
        }
    }
    return result;
}