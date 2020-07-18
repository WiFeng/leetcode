bool isPowerOfFour(int num){
    if (num < 1) {
        return false;
    }

    for (int i = 0; i < 31; i = i+2) {
        if ((num & (1 << i)) == num) {
            return true;
        }
    }
    
    return false;
}