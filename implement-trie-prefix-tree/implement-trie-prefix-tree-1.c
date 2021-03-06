#define NODE_SIZE 26

struct TrieNode {
    char val;
    bool end;
    struct TrieNode *next;
};

typedef struct {
    struct TrieNode root;
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie *trie = malloc(sizeof(Trie));
    trie->root.val = '\0';
    trie->root.end = false;
    trie->root.next = NULL;
    return trie;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    char w;
    struct TrieNode *node = &(obj->root);
    struct TrieNode *next = node->next;
    struct TrieNode *temp = NULL;

    while ((w = *(word++)) != '\0') {
        if (next == NULL) {
            struct TrieNode *next = calloc(sizeof(struct TrieNode), NODE_SIZE);
            node->next = next;
        }

        temp = &(node->next[w - 'a']);
        if (temp->val == '\0') {
            temp->val = w;
            temp->next = NULL;
        }
        
        node = temp;
        next = node->next;
    }
    node->end = true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    char w;
    struct TrieNode *node = &(obj->root);
    struct TrieNode *next = node->next;
    struct TrieNode *temp = NULL;

    while ((w = *(word++)) != '\0') {
        if (next == NULL) {
            return false;
        }
        
        temp = &(node->next[w - 'a']);
        if (temp->val != w) {
            return false;
        }

        node = temp;
        next = node->next;
    }

    // full matched
    if (node->end) {
        return true;
    }

    // prefix matched
    return false;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    char w;
    struct TrieNode *node = &(obj->root);
    struct TrieNode *next = node->next;
    struct TrieNode *temp = NULL;

    while ((w = *(prefix++)) != '\0') {
        if (next == NULL) {
            return false;
        }
        
        temp = &(node->next[w - 'a']);
        if (temp->val != w) {
            return false;
        }

        node = temp;
        next = node->next;
    }

    return true;
}

void trieNodeFree(struct TrieNode *node) {
    // recursion teminator
    if (node == NULL) {
        return;
    }

    if (node->next == NULL) {
        return;
    }

    struct TrieNode *temp = NULL;
    for (int i = 0; i < NODE_SIZE; i++) {
        temp = &(node->next[i]);
        trieNodeFree(temp);
    }

    free(node->next);
}

void trieFree(Trie* obj) {
    trieNodeFree(obj->root.next);
    free(obj);
}