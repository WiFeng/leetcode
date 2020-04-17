int reverse(int x){
    int f = x >= 0 ? 1: -1;
    int r = 0, i = 0, j = 0;
    long long tmp = 0, k = 0;

    for (int m = 1000000000; m > 0; m /= 10, k *= 10) {
        i = x / m;
        x = x % m;

        if (i>=0) {
            j = i;
        } else if (i<0) {
            j = -1 * i;
        }

        if (k == 0 && i !=0 ) {
            k = 1;
        }

        tmp += k*j;
    }

    tmp *= f;
    if (tmp > (1LL<<31) -1 || tmp < -1*(1LL<<31)) {
        r = 0;
    } else {
        r = (int)tmp;
    }

    return r;
}
