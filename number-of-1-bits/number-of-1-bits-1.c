int hammingWeight(uint32_t n) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
        if (n & (1U << i)) {
            result += 1;
        }
    }
    return result;
}