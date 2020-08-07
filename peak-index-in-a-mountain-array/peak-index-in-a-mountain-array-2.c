int peakIndexInMountainArray(int* A, int ASize){
    int result = 0;
    for (int i = 1, j = ASize - 2; i <= j + 2 && j >= 0 && i < ASize; i++, j--) {
        if (A[i] < A[i-1]) {
            result = i-1;
            break;
        }
        if (A[j] < A[j+1]) {
            result = j+1;
            break;
        }
    }
    return result;
}