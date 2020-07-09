char findTheDifference(char * s, char * t){
    int sn[26] = {0};
    int tn[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        int x = s[i] - 'a';
        sn[x]++;
    }

    for (int i = 0; t[i] != '\0'; i++) {
        int x = t[i] - 'a';
        tn[x]++;
    }

    for (int i = 0; i < 26; i++) {
        if (sn[i] != tn[i]) {
            return i + 'a';
        }
    }
    return '\0';
}