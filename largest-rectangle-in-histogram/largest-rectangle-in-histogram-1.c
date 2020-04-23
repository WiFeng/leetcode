int largestRectangleArea(int* heights, int heightsSize){
    int maxArea = 0;

    if (heightsSize < 1) {
        return 0;
    } else if (heightsSize < 2) {
        return heights[0];
    }

    for (int x = 0; x < heightsSize; x++) {
        for (int y = x; y < heightsSize; y++) {
            int currArea = 0;
            int minHeight = heights[x];
            for (int z = x + 1; z <= y; z++) {
                if (heights[z] < minHeight) {
                    minHeight = heights[z];
                }
            }
            currArea = (y - x + 1) * minHeight;
            if (currArea > maxArea) {
                maxArea = currArea;
            }
        }
    }

    return maxArea;
}
