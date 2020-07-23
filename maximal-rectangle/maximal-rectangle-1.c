int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    if (matrixSize < 1 || matrixColSize == NULL || (*matrixColSize) < 1) {
        return 0;
    }

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

            // if (i == 0 || j == 0) {
            if (j == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i][j-1] + 1;
            }

            int minWidth = dp[i][j];
            for (int k = i; k >= 0; k--) {
                if (dp[k][j] < minWidth) {
                    minWidth = dp[k][j];
                }
                int area = (i - k + 1) * minWidth;
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }
        
    }

    free(dp);
    free(dpData);

    return maxArea;
}