

int mySqrt(int x){
    int left = 0, right = x;
    while (left <= right) {
        long mid = (left + right) / 2;
        long sqrt = mid * mid;
        if (sqrt == x) {
            return mid;
        } else if (sqrt < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return right;
}


