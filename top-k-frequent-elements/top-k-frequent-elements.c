struct hashTableNode {
    int key;
    int val;
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

int hashGet(hashTable *ht, int key, bool *exists) {
    int val = 0;
    *exists =  false;
    int slot = hashSlot(ht, key);
    struct hashTableNode *node = ht->node[slot];
    while(node != NULL) {
        if (key == node->key) {
            val = node->val;
            *exists = true;
            break;
        }
        node = node->next;
    }
    return val;
}

void hashSet(hashTable *ht, int key, int val) {

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
            return;
        }
    }

    next = malloc(sizeof(struct hashTableNode));
    next->key = key;
    next->val = val;
    next->next = NULL;
    ht->used++;
    if (node == NULL) {
        ht->node[slot] = next;
    } else {
        node->next = next;
    }

    return;
}

typedef struct heapNode {
    int key;
    int val;
} heapNode;

typedef struct {
    heapNode *node;
    int size;
    int used;
} heap;

heap* heapCreate(int size) {
    heap *hp = malloc(sizeof(heap));
    heapNode *node = malloc(sizeof(heapNode) * size);
    hp->node = node;
    hp->size = size;
    hp->used = 0;
    return hp;
}

void heapFree(heap *hp) {
    free(hp->node);
    free(hp);
}

bool heapIsFull(heap *hp) {
    if (hp->used == hp->size) {
        return true;
    }
    return false;
}

bool heapIsEmpty(heap *hp) {
    if (hp->used == 0) {
        return true;
    }
    return false;
}

bool heapAddNodeTail(heap *hp, int key, int val) {
    if (heapIsFull(hp)) {
        return false;
    }

    int cindex = hp->used;
    int pindex = (cindex -1) / 2;
    heapNode *cnode = NULL;
    heapNode *pnode = NULL;
    hp->used++;

    while (pindex >= 0) {
        cnode = &(hp->node[cindex]);
        pnode = &(hp->node[pindex]);

        if (val < pnode->val) {
            cnode->key = pnode->key;
            cnode->val = pnode->val;
            if (pindex == 0) {
                pnode->key = key;
                pnode->val = val;
            }
        } else {
            cnode->key = key;
            cnode->val = val;
            break;
        }

        cindex = pindex;
        pindex = (pindex - 1) / 2;
    }

    return true;
}

bool heapAddNodeHead(heap *hp, int key, int val) {
    if (!heapIsFull(hp)) {
        return false;
    }

    int pindex = 0;
    int cindex = (2 * pindex) + 1;
    int tindex = cindex + 1;
    heapNode *pnode = NULL;
    heapNode *cnode = NULL;
    heapNode *tnode = NULL;

    pnode = &(hp->node[pindex]);
    if (pnode->val >= val) {
        return true;
    }

    pnode->key = key;
    pnode->val = val;

    while (cindex < hp->size) {
        pnode = &(hp->node[pindex]);
        cnode = &(hp->node[cindex]);

        if (tindex < hp->size) {
            tnode = &(hp->node[tindex]);
            if (tnode->val < cnode->val) {
                cnode = tnode;
                cindex = tindex;
            }
        }

        if (cnode->val >= pnode->val) {
            break;
        }

        key = pnode->key;
        val = pnode->val;
        pnode->key = cnode->key;
        pnode->val = cnode->val;
        cnode->key = key;
        cnode->val = val;

        pindex = cindex;
        cindex = (2 * pindex) + 1;
        tindex = cindex + 1;
    }

    return true;
}

bool heapAddNode(heap *hp, int key, int val) {
    if (heapIsFull(hp)) {
        return heapAddNodeHead(hp, key, val);
    } else {
        return heapAddNodeTail(hp, key, val);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    *returnSize = 0;
    int *result = NULL;

    int key = 0, val = 0;
    bool exists = false;
    hashTable *ht = hashCreate(16);
    for (int i = 0; i < numsSize; i++) {
        key = nums[i];
        val = hashGet(ht, key, &exists);
        if (exists) {
            val = val + 1;
        } else {
            val = 1;
        }
        hashSet(ht, key, val);
    }

    heap *hp = heapCreate(k);
    for (int i = 0; i < numsSize; i++) {
        key = nums[i];
        val = hashGet(ht, key, &exists);
        if (val > 0) {
            hashSet(ht,key, -1);
            heapAddNode(hp, key, val);
        }
    }

    *returnSize = k;
    result = malloc(sizeof(int) * (*returnSize));
    heapNode *node;
    for (int i = 0; i < (*returnSize); i++) {
        node = &(hp->node[i]);
        result[i] = node->key;
    }

    hashFree(ht);
    heapFree(hp);

    return result;
}
