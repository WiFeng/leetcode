int min(int a, int b, int c) {
    int t;
    t = a < b ? a : b;
    t = t < c ? t : c;
    return t;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    if (matrixSize < 1 || matrixColSize == NULL || (*matrixColSize) < 1) {
        return 0;
    }

    int maxEdge = 0;
    int maxArea = 0;
    int **dp = malloc(sizeof(int*) * matrixSize);
    int *dpData = malloc(sizeof(int) * matrixSize * (*matrixColSize));

    for (int p = 0; p < matrixSize; p++) {
        dp[p] = dpData + (p * (*matrixColSize));
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < (*matrixColSize); j++) {
            dp[i][j] = 0;
            
            if (matrix[i][j] == '0') {
                continue;
            }

            if (i == 0 || j == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
            }
            
            if (dp[i][j] > maxEdge) {
                maxEdge = dp[i][j];
            }
        }
    }

    free(dp);
    free(dpData);

    maxArea = maxEdge * maxEdge;
    return maxArea;
}