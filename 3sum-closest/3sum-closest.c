void quickSort(int* nums, int size) {

    int a[size], b[size], alen = 0, blen = 0;

    int r = rand() % size;
    int v = nums[r];

    for (int i = 0; i < size; i++) {
        if (r == i) continue;
        if (nums[i] < nums[r]) {
            a[alen++] = nums[i];
        } else {
            b[blen++] = nums[i];
        }
    }

    if (alen > 1) {
        quickSort(a, alen);
    }
    if (blen > 1) {
        quickSort(b, blen);
    }
    for (int j = 0; j < alen; j++) {
        nums[j] = a[j];
    }
    nums[alen] = v;
    for (int j = 0; j < blen; j++) {
        nums[alen + 1 + j] = b[j];
    }
}

int threeSumClosest(int* nums, int numsSize, int target){
    int r = 0, t = -1;
    // array sort
    quickSort(nums, numsSize);

    // double pointers
    for (int i = 0; i < numsSize && t != 0; i++) {
        int x = i + 1, y = numsSize -1;
        int v = 0, tmp = 0;
        while (x < y && t != 0) {
            tmp = nums[i] + nums[x] + nums[y];
            //printf("%d  %d,%d,%d\n", tmp, nums[i], nums[x], nums[y]);
            if (target > tmp) {
                v = target - tmp;
                x++;
            } else {
                v = tmp - target;
                y--;
            }

            if (t == -1) {
                t = v;
                r = tmp;
            } else if (v < t) {
                t = v;
                r = tmp;
            }
        }
    }

    return r;

}
