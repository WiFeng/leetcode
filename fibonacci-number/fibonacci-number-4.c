

int fib(int N){
    if (N < 2) {
        return N;
    }

    int result = 0;
    int s[3];

    s[0] = 0;
    s[1] = 1;

    for (int i = 2; i <= N; i++) {
        s[2] = s[0] + s[1];
        s[0] = s[1];
        s[1] = s[2];
    }

    return s[2];
}


