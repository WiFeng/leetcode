/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
  
struct ListNode* mergeList(struct ListNode* node1, struct ListNode* node2) {
    struct ListNode *head = NULL;
    struct ListNode *node = NULL;
    struct ListNode *temp = NULL;

    if (node1 == NULL) {
        return node2;
    }

    if (node2 == NULL) {
        return node1;
    }
    
    while (node1 != NULL && node2 != NULL) {
        if (node1->val < node2->val) {
            temp = node1;
            node1 = node1->next;
        } else {
            temp = node2;
            node2 = node2->next;
        }

        if (node == NULL) {
            node = temp;
            head = node;
        } else {
            node->next = temp;
            node = node->next;
        }
    }

    if (node1 != NULL) {
        node->next = node1;
        node = node->next;
        node1 = node1->next;
    }

    if (node2 != NULL) {
        node->next = node2;
        node = node->next;
        node2 = node2->next;
    }

    return head;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){

    if (listsSize < 1) {
        return NULL;
    } else if (listsSize == 1) {
        return lists[0];
    }

    struct ListNode *result = NULL;
    struct ListNode** tempLists = malloc(sizeof(struct ListNode*) * (listsSize/2 + 1));
    int tempListsSize = 0;
    
    for (int i = 0; i < listsSize; i++) {
        if (i == (listsSize - 1)) {
            tempLists[tempListsSize++] = lists[i];
            break;
        }
        struct ListNode* list1 = lists[i];
        struct ListNode* list2 = lists[++i];
        struct ListNode* list = mergeList(list1, list2);
        tempLists[tempListsSize++] = list;
    }


    result = mergeKLists(tempLists, tempListsSize);
    free(tempLists);

    return result;
}
