double myPow(double x, int n){
    if (n == 0) {
        return 1;
    } else if (n > 0 && n < 2) {
        return x;
    } else if (n < 0 && n > -2) {
        return 1 / x;
    }

    double r = myPow(x, n / 2);
    r = r * r;
    if (n % 2 == -1) {
        r = r * (1 / x);
    } else if (n % 2 == 1) {
        r = r * x;
    }
    return r;
}
