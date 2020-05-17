int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    int result = 0;

    if (gSize < 1 || sSize < 1) {
        return 0;
    }

    // quickSort(g, gSize);
    // quickSort(s, sSize);
    qsort(g, gSize, sizeof(int), cmpfunc);
    qsort(s, sSize, sizeof(int), cmpfunc);

    for (int i = 0, j = 0; i < gSize; i++) {
        if (j == sSize) {
            break;
        }
        for (; j < sSize; j++) {
            if (s[j] >= g[i]) {
                result++;
                j++;
                break;
            }
        }
    }
    return result;
}
