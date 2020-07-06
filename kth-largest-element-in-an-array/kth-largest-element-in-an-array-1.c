void quickSort(int *num, int numsSize) {

    if (numsSize < 2) {
        return;
    }

    int alen = 0;
    int blen = 0;
    int *a = malloc(sizeof(int) * numsSize);
    int *b = malloc(sizeof(int) * numsSize);

    int t = numsSize / 2;
    for (int i = 0; i < numsSize; i++) {
        if (i == t) {
            continue;
        }
        if (num[i] < num[t]) {
            a[alen++] = num[i];
        } else {
            b[blen++] = num[i];
        }
    }

    quickSort(a, alen);
    quickSort(b, blen);

    num[alen] = num[t];
    memcpy(num, a, sizeof(int) * alen);
    memcpy(num+alen+1, b, sizeof(int) *blen);
    
    free(a);
    free(b);
}

int findKthLargest(int* nums, int numsSize, int k){
    quickSort(nums, numsSize);
    int kk = numsSize - k;
    return nums[kk];
}