/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){

    *returnSize = ASize;
    if (A == NULL) {
        return NULL;
    }
    
    int *result = malloc(sizeof(int) * ASize);
    if (ASize < 2) {
        result[0] = A[0];
        return result;
    }

    for (int slow = -1, fast = 0; fast < ASize; fast++) {
        if (A[fast] % 2 == 0) {
            if (slow == -1) {
                result[fast] = A[fast];
                continue;
            }
            result[fast] = result[slow];
            result[slow] = A[fast];
            slow++;
        } else {
            if (slow == -1) {
                slow = fast;
            }
            result[fast] = A[fast];
        }
    }

    return result;
}