int climbStairs(int n){
    if (n <= 2) {
        return n;
    }

    int result = 0;
    static int *m = NULL;
    static int s = 0;
    
    if (m == NULL) {
        m = calloc(sizeof(int), n + 1);
        m[1] = 1;
        m[2] = 2;
        s = n;
    }

    if (m[n-1] == 0) {
        m[n-1]= climbStairs(n-1);
    }

    if (m[n-2] == 0) {
        m[n-2]= climbStairs(n-2);
    }
    
    result = m[n-1] + m[n-2];

    if (n == s) {
        free(m);
        m = NULL;
        s = 0;
    }

    return result;
}