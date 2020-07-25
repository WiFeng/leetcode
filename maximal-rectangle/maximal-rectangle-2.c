struct stackNode {
    int val;
};

typedef struct stack {
    struct stackNode *head;
    struct stackNode *node;
    int size;
    int used;

} stack;

stack* createStack(int size) {
    stack *s = malloc(sizeof(stack));
    s->size = size;
    s->used = 0;

    struct stackNode *node  = malloc(sizeof(struct stackNode) * (s->size));
    s->node = node;
    s->head = NULL;

    return s;
}

void pushStack(stack *s, int val) {
    struct stackNode *head = s->head;

    if (s->used < 1) {
        head = s->node;
    } else {
        head++;
    }

    head->val = val;
    s->head = head;
    s->used++;
}

void popStack(stack *s) {
    struct stackNode *head = s->head;
    if (s->used < 1) {
        return NULL;
    } else {
        head--;
    }

    s->head = head;
    s->used--;
}

void freeStack(stack *s) {
    free(s->node);
    free(s);
}

int largestRectangleArea(int* heights, int heightsSize){
    int maxArea = 0;
    int currArea = 0;

    stack *s = createStack(heightsSize+1);
    pushStack(s, -1);

    for (int x = 0; x < heightsSize; x++) {
        while (s->used >=2 && heights[x] < heights[s->head->val]) {
            struct stackNode *next = s->head - 1;
            currArea = (x - next->val - 1) * heights[s->head->val];
            popStack(s);
            if (currArea > maxArea) {
                maxArea = currArea;
            }
        }
        pushStack(s, x);
    }

    while (s->used >= 2) {
        struct stackNode *next = s->head - 1;
        currArea = (heightsSize - next->val - 1) * heights[s->head->val];
        popStack(s);
        if (currArea > maxArea) {
            maxArea = currArea;
        }
    }

    freeStack(s);

    return maxArea;
}

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
            if (i == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i-1][j] + 1;
            }
        }

        int area = largestRectangleArea(dp[i], (*matrixColSize));
        if (area > maxArea) {
            maxArea = area;
        }
    }

    free(dp);
    free(dpData);

    return maxArea;
}
