bool isPalindrome(int x){

    if (x < 0) {
        return false;
    } else if (x < 10) {
        return true;
    }

    long long t = 0;
    int i = 0, v = 0, w = 0;

    for (i = 10; i < 1000000000; i*=10) {
        if (x/i < 10) {
            break;
        }
    }

    for (v = x; i > 0; i/=10) {
        w = v % 10;
        v = v / 10;
        t = w * (long long)i;
        if (t > INT_MAX) {
            return false;
        }
        x -= t;
    }

    if (x != 0) return false;

    return true;
}
