/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct Queue {
    int len;
    struct QueueNode *head;
    struct QueueNode *tail;
} Queue;

struct QueueNode {
    struct TreeNode *val;
    struct QueueNode *prev;
    struct QueueNode *next;
};

Queue* createQueue() {
    Queue *q = malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    q->len = 0;
    return q;
}

int queueLen(Queue *q) {
    return q->len;
}

int queuePush(Queue *q, struct TreeNode *val) {
    struct QueueNode *node = malloc(sizeof(struct QueueNode));
    node->val = val;
    node->prev = NULL;
    node->next = q->head;

    if (q->head != NULL) {
        q->head->prev = node;
    }

    q->head = node;
    q->len++;

    if (q->tail == NULL) {
        q->tail = q->head;
    }
    return q->len;
}

struct TreeNode* queuePop(Queue *q) {
    struct QueueNode *node = q->tail;
    if (node == NULL) {
        return NULL;
    }

    if (node->prev != NULL) {
        node->prev->next = NULL;
    }

    q->tail = node->prev;
    q->len--;

    if (q->tail == NULL) {
        q->head = NULL;
    }

    struct TreeNode *val = node->val;
    free(node);

    return val;
}

void freeQueue(Queue *q) {
    struct TreeNode *node = NULL;
    while ((node = queuePop(q)) != NULL) {
        // do nothing
    }
    free(q);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }

    int *columnSizes = NULL;
    int **returnColumns = NULL;

    Queue *q = createQueue();
    queuePush(q, root);

    while (queueLen(q) > 0) {
        int len = queueLen(q);
        int *column = malloc(sizeof(int) * len);
        for (int i = 0, j = len; j > 0; j--) {
            struct TreeNode *val = queuePop(q);
            column[i++] = val->val;
            if (val->left != NULL) queuePush(q, val->left);
            if (val->right != NULL) queuePush(q, val->right);
        }
        *returnSize = (*returnSize) + 1;
        returnColumns = realloc(returnColumns, sizeof(int*) * (*returnSize));
        returnColumns[(*returnSize) - 1] = column;
        columnSizes = realloc(columnSizes, sizeof(int) * (*returnSize));
        columnSizes[(*returnSize) - 1] = len;
    }

    freeQueue(q);
    *returnColumnSizes = columnSizes;
    return returnColumns;
}
