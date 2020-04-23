struct stackNode {
    int val;
    struct stackNode *next;
};

typedef struct stack {
    struct stackNode *head;
} stack;

void pushStack(stack *s, int val) {
    struct stackNode *node  = malloc(sizeof(struct stackNode));
    node->val = val;
    node->next = s->head;
    s->head = node;
}

void popStack(stack *s) {
    struct stackNode *node = s->head;
    if (node != NULL) {
        s->head = node->next;
        free(node);
    }
}

void freeStack(stack *s) {
    while (s->head != NULL) {
        popStack(s);
    }
}

int largestRectangleArea(int* heights, int heightsSize){
    int maxArea = 0;
    int currArea = 0;

    stack s;
    s.head = NULL;
    pushStack(&s, -1);

    for (int x = 0; x < heightsSize; x++) {
        while (s.head->next != NULL && heights[x] < heights[s.head->val]) {
            currArea = (x - s.head->next->val - 1) * heights[s.head->val];
            popStack(&s);
            if (currArea > maxArea) {
                maxArea = currArea;
            }
        }
        pushStack(&s, x);
    }

    while (s.head->next != NULL) {
        currArea = (heightsSize - s.head->next->val - 1) * heights[s.head->val];
        popStack(&s);
        if (currArea > maxArea) {
            maxArea = currArea;
        }
    }

    freeStack(&s);

    return maxArea;
}




