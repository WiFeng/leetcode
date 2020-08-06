bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {

    for (int row = matrixRowSize - 1, col = 0; row >=0 && col < matrixColSize;) {
        if (target < matrix[row][col]) {
            row--;
        } else if (target > matrix[row][col]) {
            col++;
        } else {
            return true;
        }
    }

    return false;
}