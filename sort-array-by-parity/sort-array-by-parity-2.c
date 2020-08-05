/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    
    *returnSize = ASize;

    for (int slow = -1, fast = 0; fast < ASize; fast++) {
        if (A[fast] % 2 == 0) {
            if (slow == -1) {
                continue;
            }
            int temp = A[fast];
            A[fast] = A[slow];
            A[slow] = temp;
            slow++;
        } else {
            if (slow == -1) {
                slow = fast;
            }
        }
    }

    return A;
}