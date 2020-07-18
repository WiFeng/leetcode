
bool isPowerOfFour(int num){
    if (num < 1) {
        return false;
    }

    if ((num & (num-1)) == 0 && (num & 0xaaaaaaaa) == 0) {
        return true;
    }
    
    return false;
}