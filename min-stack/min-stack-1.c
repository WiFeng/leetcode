typedef struct {
    int val;
    int minVal;
} Node;

typedef struct {
    Node* pool;
    int size;
    int used;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    int initSize = 8;
    Node *pool = malloc(sizeof(Node) * initSize);

    MinStack *obj = malloc(sizeof(MinStack));
    obj->size = initSize;
    obj->used = 0;
    obj->pool = pool;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->used >= obj->size) {
        int size = obj->size * 2;
        int *pool = realloc(obj->pool, sizeof(Node) * size);
        obj->size = size;
        obj->pool = pool;
    }

    int minVal = x;
    if (obj->used > 0) {
        Node top = obj->pool[obj->used - 1];
        if (top.minVal < x) {
            minVal = top.minVal;
        }
    }
    
    obj->pool[obj->used].val = x;
    obj->pool[obj->used].minVal = minVal;
    obj->used++;
}

void minStackPop(MinStack* obj) {
    if (obj->used < obj->size / 2) {
        int size = obj->size / 2;
        Node *pool = realloc(obj->pool, sizeof(Node) * size);
        obj->size = size;
        obj->pool = pool;
    }

    obj->used--;
}

int minStackTop(MinStack* obj) {
    Node node = obj->pool[obj->used - 1];
    return node.val;
}

int minStackGetMin(MinStack* obj) {
    Node node = obj->pool[obj->used - 1];
    return node.minVal;
}

void minStackFree(MinStack* obj) {
    free(obj->pool);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/