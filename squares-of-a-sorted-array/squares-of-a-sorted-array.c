/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* A, int ASize, int* returnSize){

    int *ra = NULL;
    *returnSize = 0;

    if (ASize < 1) {
        return ra;
    }

    ra = malloc(sizeof(int) * ASize);

    int x = 0, y = ASize - 1;
    int xv = 0, yv = 0;

    for (;x <= y;) {
        xv = A[x] * A[x];
        yv = A[y] * A[y];

        if (yv > xv) {
            ra[ASize - (*returnSize) - 1] = yv;
            y--;
        } else {
            ra[ASize - (*returnSize) - 1] = xv;
            x++;
        }
        *returnSize = *returnSize + 1;
    }

    return ra;
}
