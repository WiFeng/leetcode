

// ========================
// Trie
// ========================
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

bool _trieSearchAdv(struct TrieNode* node, char * word) {
    struct TrieNode *next = NULL;
    char w = *(word++);

    if (node == NULL) {
        return false;
    }
    
    if (w == '\0') {
        if (node->end) {
            return true;
        }
        return false;
    }

    if (node->next == NULL) {
        return false;
    }

    if (w == '.') {
        for (int i = 0; i < NODE_SIZE; i++) {
            next = &(node->next[i]);
            bool match = _trieSearchAdv(next, word);
            if (match) {
                return true;
            }
        }
        return false;
    } else if (w >= 'a' && w <= 'z') {
        next = &(node->next[w - 'a']);
        // if (next->next == NULL) {
        if (next->val != w) {
            return false;
        }
        return _trieSearchAdv(&(node->next[w - 'a']), word);
    }

    return false;
}

bool trieSearchAdv(Trie* obj, char * word) {
    return _trieSearchAdv(&(obj->root), word);
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


// =========================
// WordDictionary
// =========================

typedef struct {
    Trie *trie;
} WordDictionary;

/** Initialize your data structure here. */

WordDictionary* wordDictionaryCreate() {
    WordDictionary *dict = malloc(sizeof(WordDictionary));
    dict->trie = trieCreate();
    return dict;
}

/** Adds a word into the data structure. */
void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    trieInsert(obj->trie, word);
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool wordDictionarySearch(WordDictionary* obj, char * word) {
    return trieSearchAdv(obj->trie, word);
}

void wordDictionaryFree(WordDictionary* obj) {
    trieFree(obj->trie);
    free(obj);
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 
 * bool param_2 = wordDictionarySearch(obj, word);
 
 * wordDictionaryFree(obj);
*/