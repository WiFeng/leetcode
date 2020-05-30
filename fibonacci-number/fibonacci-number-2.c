

int fib(int N){
    int result = 0;
    static int *s = NULL;
    static int n = -1;

    if (N < 2) {
        return N;
    }

    if (s == NULL) {
        s = calloc(N, sizeof(int));
        n = N;
    }

    if (s[N-1] == 0) {
        s[N-1] = fib(N-1) + fib(N-2);
    }

    result = s[N-1];

    if (n == N) {
        free(s);
        s = NULL; // so important!!
    }

    return result;
}


