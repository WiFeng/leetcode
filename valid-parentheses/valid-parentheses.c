struct stackNode {
    char val;
    struct stackNode *next;
};

typedef struct stack {
    struct stackNode *head;
} stack;

void pushStack(stack *s, char val) {
    struct stackNode *node  = malloc(sizeof(struct stackNode));
    node->val = val;
    node->next = s->head;
    s->head = node;
}

void popStack(stack *s) {
    struct stackNode *node = s->head;
    s->head = node->next;
    free(node);
}

void freeStack(stack *s) {
    if (s->head != NULL) {
        popStack(s);
    }
}

bool isValid(char * s){

    int l = 3;
    char lb[3] = {'(', '{', '['};
    char rb[3] = {')', '}', ']'};

    stack st;
    st.head = NULL;

    int k ;
    char v;

    while((v = *s++) != '\0') {
        if (st.head == NULL) {
            pushStack(&st, v);
            continue;
        }

        k = -1;
        for (int i = 0; i < l; i++) {
            if (v == rb[i]) {
                k = i;
                break;
            }
        }

        if (k >= 0) {
            if (st.head->val == lb[k]) {
                popStack(&st);
            } else {
                freeStack(&st);
                return false;
            }
        } else {
            pushStack(&st, v);
        }

    }

    if (st.head == NULL) {
        return true;
    }

    freeStack(&st);
    return false;

}



