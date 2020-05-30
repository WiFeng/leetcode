

int fib(int N){
    int result = 0;
    int *s = NULL;

    if (N < 2) {
        return N;
    }

    s = malloc(sizeof(int) * (N + 1));
    s[0] = 0;
    s[1] = 1;

    for (int i = 2; i <= N; i++) {
        s[i] = s[i-1] + s[i-2];
    }

    result = s[N];
    free(s);

    return result;
}


