/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorder(struct Node* root, int* returnSize) {
    int *r = NULL;
    *returnSize = 0;

    if (root == NULL) {
        return r;
    }

    r = malloc(sizeof(int));
    r[0] = root->val;
    *returnSize = 1;

    int rs = 0;
    for (int i = 0; i < root->numChildren; i++) {
        int *is = preorder(root->children[i], &rs);
        r = realloc(r, sizeof(int) * (*returnSize + rs));

        int *dst = r + *returnSize;
        int len = sizeof(int) * rs;

        *returnSize = *returnSize + rs;

        memcpy(dst, is, len);
        free(is);
    }

    return r;
}
