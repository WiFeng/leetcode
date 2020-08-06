int binarySearch(int target, int *nums, int start, int end) {
    int size = end - start;
    int mid = start + (size / 2);
    if (size < 1) {
        return -1;
    } else if (size < 2) {
        if (nums[start] == target) {
            return 0;
        }
        return -1;
    }

    if (nums[mid] < target) {
        return binarySearch(target, nums, mid, end);
    } else if (nums[mid] > target) {
        return binarySearch(target, nums, start, mid);
    } else {
        return mid;
    }
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    if (matrixRowSize < 1 || matrixColSize < 1) {
        return false;
    }

    for (int row = 0; row < matrixRowSize; row++) {
        if (matrix[row][0] > target) {
            break;
        } else if (matrix[row][matrixColSize-1] < target) {
            continue;
        }

        int pos = binarySearch(target, matrix[row], 0, matrixColSize);
        if (pos > -1) {
            return true;
        }
    }

    return false;
}