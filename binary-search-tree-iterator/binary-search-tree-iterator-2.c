/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct {
    struct TreeNode** pool;
    int size;
    int used;
} Stack;

typedef struct {
    Stack *stack;
} BSTIterator;

// -----------------------------
// Stack
// -----------------------------
Stack* StackCreate() {
    int initSize = 4;
    struct TreeNode **pool = malloc(sizeof(struct TreeNode*) * initSize);

    Stack *obj = malloc(sizeof(Stack));
    obj->size = initSize;
    obj->used = 0;
    obj->pool = pool;
    return obj;
}

void StackPush(Stack* obj, struct TreeNode* x) {
    if (obj->used >= obj->size) {
        int size = obj->size * 2;
        struct TreeNode **pool = realloc(obj->pool, sizeof(struct TreeNode*) * size);
        obj->size = size;
        obj->pool = pool;
    }
    
    obj->pool[obj->used] = x;
    obj->used++;
}

struct TreeNode* StackPop(Stack* obj) {
    if (obj->used < obj->size / 2) {
        int size = obj->size / 2;
        struct TreeNode **pool = realloc(obj->pool, sizeof(struct TreeNode*) * size);
        obj->size = size;
        obj->pool = pool;
    }

    if (obj->used < 1) {
        return NULL;
    }

    struct TreeNode *node = obj->pool[obj->used - 1];
    obj->used--;

    return node;
}

struct TreeNode* StackTop(Stack* obj) {
    if (obj->used < 1) {
        return NULL;
    }

    struct TreeNode *node = obj->pool[obj->used - 1];
    return node;
}

void StackFree(Stack* obj) {
    free(obj->pool);
    free(obj);
}

// -----------------------------
// Tree Recursion
// -----------------------------
void traverseTree(struct TreeNode* root, BSTIterator* iterator) {
    Stack *stack = iterator->stack;
    if (root == NULL) {
        return;
    }
    StackPush(stack, root);
    traverseTree(root->left, iterator);
}

// -----------------------------
// BSTIterator
// -----------------------------
BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator *iterator = malloc(sizeof(BSTIterator));
    iterator->stack = StackCreate();
    traverseTree(root, iterator);
    return iterator;
}

/** @return the next smallest number */
int bSTIteratorNext(BSTIterator* obj) {
    Stack *stack = obj->stack;
    struct TreeNode *node = StackPop(stack);
    if (node == NULL) {
        return 0;
    }
    traverseTree(node->right, obj);
    return node->val;
}

/** @return whether we have a next smallest number */
bool bSTIteratorHasNext(BSTIterator* obj) {
    if (obj->stack->used > 0) {
        return true;
    }
    return false;
}

void bSTIteratorFree(BSTIterator* obj) {
    StackFree(obj->stack);
    free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/