int dpPath(int startX, int startY, int m, int n) {
    int result = 0;

    static int *s = NULL;
    static int x = -1;
    static int y = -1;

    if (startX == m && startY == n) {
        return 1;
    }

    if (s == NULL) {
        s = calloc(m * n, sizeof(int));
        x = startX;
        y = startY;
    }

    int z = 0;
    if (startY < 1) {
        z = startX;
    } else {
        z = (startY - 1) * m + startX;
    }

    if (s[z] == 0) {
        int path1 = 0, path2 = 0;
        if (startX < m) {
            path1 = dpPath(startX + 1, startY, m, n);
        }
        if (startY < n) {
            path2 = dpPath(startX, startY + 1, m, n);
        }
        s[z] = path1 + path2;
    }

    result = s[z];

    if (x == startX && y == startY) {
        free(s);
        s = NULL;
    }

    return result;
}

int uniquePaths(int m, int n){
    return dpPath(1, 1, m, n);
}


