struct ListNode* reverseList(struct ListNode* head){

    if (head == NULL) {
        return head;
    }

    struct ListNode *next = head->next;
    head->next = NULL;
    
    while (next != NULL) {
        struct ListNode *nnext = next->next;

        next->next = head;
        head = next;

        next = nnext;
    }

    return head;
}