void makeSet(int *set, int nums) {
    for (int i = 0; i < nums; i++) {
        set[i] = i;
    }
}

int unionSet(int *set, int stu1, int stu2) {
    int p1 = find(set, stu1);
    int p2 = find(set, stu2);

    // compress
    set[stu1] = p1;
    set[stu2] = p2;

    if (p1 != p2) {
        set[p1] = p2;
        return 1;
    }

    return 0;
}

int find(int *set, int stu) {
    int p = set[stu];
    while (set[p] != p) {
        p = set[p];
    }

    return p;
}

int findCircleNum(int** M, int MSize, int* MColSize){
    
    int result = 0;
    int set[200] = {0};

    makeSet(set, MSize);
    result = MSize;

    for (int i = 0; i < MSize; i++) {
        for (int j = i + 1; j < MSize; j++) {
            if (M[i][j] != 1) {
                continue;
            }
            int diff = unionSet(set, i, j);
            if (diff > 0) {
                result--;
            }
        }
    }

    return result;
}