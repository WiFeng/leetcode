int climbStairs(int n){
    if (n <=2) {
        return n;
    }

    int m[2] = {1, 2};
    int t = 0;

    for (int i = 3; i <= n; i++) {
        t = m[0] + m[1];
        m[0] = m[1];
        m[1] = t;
    }
    
    return t;
}