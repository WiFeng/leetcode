

int uniquePaths(int m, int n){
    int result = 0;
    int *s = calloc(m * n, sizeof(int));

    for (int x = m; x > 0; x--) {
        for (int y = n; y > 0; y--) {
            int z = 0;
            if (y < 2) {
                z = x - 1;
            } else {
                z = (y - 1) * m + x - 1;
            }
            if (x == m && y == n) {
                s[z] = 1;
            } else {
                int path1 = 0, path2 = 0;
                if (x < m) {
                    path1 = s[z + 1];
                }
                if (y < n) {
                    path2 = s[z + m];
                }
                s[z] = path1 + path2;
            }
        }
    }

    result = s[0];
    free(s);

    return result;
}


