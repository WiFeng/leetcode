void makeSet(int* set, int nums) {
    for (int i = 0; i < nums; i++) {
        set[i] = i;
    }
}

int unionSet(int* set, int s1, int s2) {
    int p1 = find(set, s1);
    int p2 = find(set, s2);

    // compress
    set[s1] = p1;
    set[s2] = p2;

    // union
    if (p1 != p2) {
        set[p1] = p2;
        return 1;
    }
    return 0;
}

int find(int* set, int s) {
    int p = set[s];
    while (p != set[p]) {
        p = set[p];
    }
    return p;
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int result = 0;

    if (gridSize < 1) {
        return result;
    }

    int setSize = gridSize * (*gridColSize);
    int *set = malloc(sizeof(int) * setSize);
    result = setSize;
    makeSet(set, setSize);
    
    for (int row = 0; row < gridSize; row++) {
        for (int col = 0; col < *gridColSize; col++) {
            if (grid[row][col] == '0') {
                result--;
                continue;
            }

            // only looking up the left and up point of the current point   
            if (row > 0 && grid[row-1][col] != '0') {
                int s1 = row * (*gridColSize) + col;
                int s2 = (row -1) * (*gridColSize) + col;
                int diff = unionSet(set, s1, s2);
                if (diff > 0) {
                    result--;
                }
                
            }

            if (col > 0 && grid[row][col-1] != '0') {
                int s1 = row * (*gridColSize) + col;
                int s2 = row * (*gridColSize) + col - 1;
                int diff = unionSet(set, s1, s2);
                if (diff > 0) {
                    result--;
                }
            }
        }
    }

    free(set);
    return result;
}