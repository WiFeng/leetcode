char findTheDifference(char * s, char * t){
    char result = 0;

    int i;
    for (i = 0; s[i] != '\0'; i++) {
        result ^= s[i] ^ t[i];
    }
    result ^= t[i];

    return result;
}