char convertChar(char c) {
    if (c >= '0' && c <='9') {
        return c;
    }
    if (c >= 'a' && c <= 'z') {
        return c;
    }
    if (c >= 'A' && c <= 'Z') {
        return 'a' - 'A' + c;
    }
    return -1;
}

bool isPalindrome(char * s){
    int len = strlen(s);
    char a = -1, b = -1;

    for (int i = 0, j = len -1; i < j;) {
        a = convertChar(s[i]);
        b = convertChar(s[j]);

        if (a == -1) {
            i++;
            continue;
        }
        if (b == -1) {
            j--;
            continue;
        }

        if (a != b) {
            return false;
        }

        i++;
        j--;
    }

    return true;
}