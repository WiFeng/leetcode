/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){

    *returnSize = ASize;

    for (int left = 0, right = ASize - 1; left < right;) {
        if (A[left] % 2 > A[right] % 2) {
            int temp = A[left];
            A[left] = A[right];
            A[right] =  temp;
            left++;
            right--;
        }
        if (A[left] % 2 == 0) left++;
        if (A[right] % 2 == 1) right--;
    }

    return A;
}
