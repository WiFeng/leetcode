/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int r, r1, r2, f = 0;
    struct ListNode *prev, *node, *head = NULL;
    while (l1 != NULL || l2 != NULL || f > 0) {
        r1 = r2 = 0;
        if (l1 != NULL) {
            r1 = l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            r2 = l2->val;
            l2 = l2->next;
        }

        r = r1 + r2 + f;
        if (r > 9) {
            r -= 10;
            f = 1;
        } else {
            f = 0;
        }

        node = malloc(sizeof(*node));
        node->val = r;
        node->next = NULL;

        if (head == NULL) {
           head = node;
        } else {
            prev->next = node;
        }

        prev = node;
    }

    return head;
}


