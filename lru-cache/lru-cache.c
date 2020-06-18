/**
 * HashTable
 */
struct hashTableNode {
    int key;
    int val;
    void *ptr;
    struct hashTableNode *next;
} hashTableNode;

typedef struct {
    struct hashTableNode **node;
    int used;
    int size;
} hashTable;

hashTable* hashCreate(int defaultSize) {
    hashTable *ht = malloc(sizeof(hashTable));
    // ht->node = malloc(sizeof(struct hashTableNode*) * defaultSize);
    ht->node = calloc(sizeof(struct hashTableNode*), defaultSize);
    ht->used = 0;
    ht->size = defaultSize;
    return ht;
}

void hashFreeNode(hashTable *ht) {
    struct hashTableNode *node, *tmp;
    for (int slot = 0; slot < ht->size; slot++) {
        node = ht->node[slot];
        while(node != NULL) {
            tmp = node;
            node = node->next;
            free(tmp);
        }
    }
    free(ht->node);
}

void hashFree(hashTable *ht) {
    hashFreeNode(ht);
    free(ht);
}

void hashExpand(hashTable *ht) {
    if (ht->used <= ht->size) {
        return;
    }

    int nextSize = 1;
    while (ht->used > nextSize) {
        nextSize *= 2;
    }

    hashTable *ht2 = hashCreate(nextSize);
    struct hashTableNode *node = NULL;
    for (int i = 0; i < ht->size; i++) {
        node = ht->node[i];
        while (node != NULL) {
            hashSet(ht2, node->key, node->val);
            node = node->next;
        }
    }

    hashFreeNode(ht);
    ht->node = ht2->node;
    ht->size = nextSize;
}

int hashSlot(hashTable *ht, int key) {
    int slot = key % ht->size;
    if (slot < 0) {
        slot *= -1;
    }
    return slot;
}

struct hashTableNode* hashGet(hashTable *ht, int key, bool *exists) {
    *exists = false;
    int slot = hashSlot(ht, key);
    struct hashTableNode *node = ht->node[slot];
    while(node != NULL) {
        if (key == node->key) {
            *exists = true;
            break;
        }
        node = node->next;
    }
    return node;
}

int hashSet(hashTable *ht, int key, int val, void *ptr) {

    hashExpand(ht);

    int slot = hashSlot(ht, key);
    struct hashTableNode *next = NULL;
    struct hashTableNode *node = ht->node[slot];

    next = node;
    while(next != NULL) {
        node = next;
        next = node->next;
        if (node->key == key) {
            node->val = val;
            return 0;
        }
    }

    next = malloc(sizeof(struct hashTableNode));
    next->key = key;
    next->val = val;
    next->ptr = ptr;
    next->next = NULL;
    ht->used++;
    if (node == NULL) {
        ht->node[slot] = next;
    } else {
        node->next = next;
    }

    return 1;
}

void hashDel(hashTable *ht, int key) {
    int slot = hashSlot(ht, key);
    struct hashTableNode *node = ht->node[slot];
    struct hashTableNode *prev = NULL;
    while(node != NULL) {
        if (key == node->key) {
            break;
        }
        prev = node;
        node = node->next;
    }

    if (node == NULL) {
        return;
    }

    if (prev == NULL) {
        ht->node[slot] = node->next;
    } else {
        prev->next = node->next;
    }

    free(node);
    ht->used--;
}

/**
 * Double Linked List
 * 
 */
typedef struct doubleLinkedList {
    int len;
    struct doubleLinkedListNode *head;
    struct doubleLinkedListNode *tail;
} doubleLinkedList;

struct doubleLinkedListNode {
    int val;
    struct doubleLinkedListNode *prev;
    struct doubleLinkedListNode *next;
};

doubleLinkedList* dllCreate() {
    doubleLinkedList *dll = malloc(sizeof(doubleLinkedList));
    dll->head = NULL;
    dll->tail = NULL;
    dll->len = 0;
    return dll;
}

int dllLen(doubleLinkedList *l) {
    return l->len;
}

struct doubleLinkedListNode* dllPush(doubleLinkedList *dll, int val) {
    struct doubleLinkedListNode *node = malloc(sizeof(struct doubleLinkedListNode));
    node->val = val;
    node->prev = NULL;
    node->next = dll->head;

    if (dll->head != NULL) {
        dll->head->prev = node;
    }

    dll->head = node;
    dll->len++;

    if (dll->tail == NULL) {
        dll->tail = dll->head;
    }
    return node;
}

int dllPop(doubleLinkedList *dll) {
    struct doubleLinkedListNode *node = dll->tail;
    if (node == NULL) {
        return -1;
    }

    if (node->prev != NULL) {
        node->prev->next = NULL;
    }

    dll->tail = node->prev;
    dll->len--;

    if (dll->tail == NULL) {
        dll->head = NULL;
    }

    int val = node->val;
    free(node);

    return val;
}

void dllPopNode(doubleLinkedList *dll, struct doubleLinkedListNode *node) {
    if (node == NULL) {
        return;
    }

    if (node->prev == NULL) {
        dll->head = node->next;
    } else {
        node->prev->next = node->next;
    }

    if (node->next == NULL) {
        dll->tail = node->prev;
    } else {
        node->next->prev = node->prev;
    }

    dll->len--;
}

void dllPushNode(doubleLinkedList *dll, struct doubleLinkedListNode *node) {
    struct doubleLinkedListNode *head = dll->head;

    if (node == NULL) {
        return;
    }

    if (head != NULL) {
        head->prev = node;
    }

    node->prev = NULL;
    node->next = head;
    dll->head = node;
    
    if (dll->tail == NULL) {
        dll->tail = dll->head;
    }

    dll->len++;
}

void dllFree(doubleLinkedList *dll) {
    int val;
    while ((val = dllPop(dll)) > -1) {
        // do nothing
    }
    free(dll);
}

void dllPrint(doubleLinkedList *dll) {
    struct doubleLinkedListNode *node;
    
    printf(" val ->: ");
    node = dll->head;
    while (node != NULL) {
        printf("%d,", node->val);
        node = node->next;
    }

    printf(" val <-: ");
    node = dll->tail;
    while (node != NULL) {
        printf("%d,", node->val);
        node = node->prev;
    }
    printf("\n");
}

/**
 * LRU Cache
 */
typedef struct {
    hashTable *ht;
    doubleLinkedList *list;
    int cap;
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *lc = malloc(sizeof(LRUCache));
    lc->ht = hashCreate(capacity * 3);
    lc->list = dllCreate();
    lc->cap = capacity;
    return lc;
}

int lRUCacheGet(LRUCache* obj, int key) {
    hashTable *ht = obj->ht;
    doubleLinkedList *list = obj->list;

    bool existed = false;
    struct hashTableNode *htNode = hashGet(ht, key, &existed);

    if (!existed) {
        return -1;
    }

    struct doubleLinkedListNode *lnode = htNode->ptr;
    dllPopNode(list, lnode);
    dllPushNode(list, lnode);

    return htNode->val;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    hashTable *ht = obj->ht;
    doubleLinkedList *list = obj->list;

    bool existed = false;
    struct hashTableNode *htNode = hashGet(ht, key, &existed);

    struct doubleLinkedListNode *lnode = NULL;
    if (!existed) {
        if (dllLen(list) >= obj->cap) {
            int lastKey = dllPop(list);
            hashDel(ht, lastKey);
        }

        lnode = dllPush(list, key);
    } else {
        struct doubleLinkedListNode *lnode = htNode->ptr;
        dllPopNode(list, lnode);
        dllPushNode(list, lnode);
    }

    hashSet(ht, key, value, lnode);
}

void lRUCacheFree(LRUCache* obj) {
    hashFree(obj->ht);
    dllFree(obj->list);
    free(obj);
}