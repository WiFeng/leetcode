/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){

    struct ListNode *result = NULL;
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    for (int i = 0; i < k; i++) {
        if (fast == NULL || fast->next == NULL) {
            fast = head;
            k = k % (i+1);
            i = -1;
            continue;
        }
        fast = fast->next;
    }

    if (slow == fast) {
        return head;
    }

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    result = slow->next;
    fast->next = head;
    slow->next = NULL;

    return result;
}