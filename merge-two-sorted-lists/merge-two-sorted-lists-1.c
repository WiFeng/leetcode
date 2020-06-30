/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* result = NULL;

    struct ListNode* l1Next = NULL;
    struct ListNode* l2Next = NULL;
    struct ListNode* prev = NULL;

    while (l1 != NULL && l2 != NULL) {
        l1Next = l1;
        l2Next = l2;
        if (l1->val < l2->val) {
            l1Next = l1->next;
            if (prev != NULL) {
                prev->next = l1;
            }
            l1->next = NULL;
            prev = l1;
        } else {
            l2Next = l2->next;
            if (prev != NULL) {
                prev->next = l2;
            }
            l2->next = NULL;
            prev = l2;
        }

        if (result == NULL) {
            result = prev;
        }

        l1 = l1Next;
        l2 = l2Next;
    }

    if (l1 != NULL) {
        if (prev != NULL) {
            prev->next = l1;
        } else {
            result = l1;
        }
    }

    if (l2 != NULL) {
        if (prev != NULL) {
            prev->next = l2;
        } else {
            result = l2;
        }
    }

    return result;
}