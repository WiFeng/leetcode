struct queueNode {
    int val;
    struct queueNode *prev;
    struct queueNode *next;
};

typedef struct {
    int capacity;
    int length;
    struct queueNode *head;
    struct queueNode *tail;
} MyCircularDeque;

/** Initialize your data structure here. Set the size of the deque to be k. */

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *circularDeque = malloc(sizeof(MyCircularDeque));
    circularDeque->capacity = k;
    circularDeque->length = 0;
    circularDeque->head = NULL;
    circularDeque->tail = NULL;
    return circularDeque;
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {

    if (obj->length >= obj->capacity) {
        return false;
    }

    struct queueNode *head = obj->head;
    struct queueNode *node = malloc(sizeof(struct queueNode));
    node->val = value;
    node->next = head;
    node->prev = NULL;
    if (head != NULL) {
        head->prev = node;
    }

    obj->length++;
    obj->head = node;
    if (obj->length <= 1) {
        obj->tail = node;
    }
    return true;
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->length >= obj->capacity) {
        return false;
    }

    struct queueNode *tail = obj->tail;
    struct queueNode *node = malloc(sizeof(struct queueNode));
    node->val = value;
    node->prev = tail;
    node->next = NULL;
    if (tail != NULL) {
        tail->next = node;
    }

    obj->length++;
    obj->tail = node;
    if (obj->length <= 1) {
        obj->head = node;
    }
    return true;
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->length < 1) {
        return false;
    }

    struct queueNode *head = obj->head;
    struct queueNode *next = head->next;

    obj->length--;
    obj->head = next;
    free(head);

    if (obj->length <=1) {
        obj->tail = next;
    }

    if (next != NULL) {
        next->prev = NULL;
    }

    return true;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->length < 1) {
        return false;
    }

    struct queueNode *tail = obj->tail;
    struct queueNode *prev = tail->prev;

    obj->length--;
    obj->tail = prev;
    free(tail);

    if (obj->length <=1) {
        obj->head = prev;
    }

    if (prev != NULL) {
        prev->next = NULL;
    }
    return true;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->length < 1) {
        return -1;
    }
    int val = obj->head->val;
    return val;
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->length < 1) {
        return -1;
    }
    int val = obj->tail->val;
    return val;
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if (obj->length > 0) {
        return false;
    }
    return true;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj) {
    if (obj->length < obj->capacity) {
        return false;
    }
    return true;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    struct queueNode *node, *next;
    node = obj->head;
    while (node != NULL) {
        next = node->next;
        free(node);
        node = next;
    }
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);

 * bool param_2 = myCircularDequeInsertLast(obj, value);

 * bool param_3 = myCircularDequeDeleteFront(obj);

 * bool param_4 = myCircularDequeDeleteLast(obj);

 * int param_5 = myCircularDequeGetFront(obj);

 * int param_6 = myCircularDequeGetRear(obj);

 * bool param_7 = myCircularDequeIsEmpty(obj);

 * bool param_8 = myCircularDequeIsFull(obj);

 * myCircularDequeFree(obj);
*/
