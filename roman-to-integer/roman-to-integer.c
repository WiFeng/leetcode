int romanToInt(char * s){

    int m[26], r = 0;
    char t;

    m['I'-'A'] = 1;
    m['V'-'A'] = 5;
    m['X'-'A'] = 10;
    m['L'-'A'] = 50;
    m['C'-'A'] = 100;
    m['D'-'A'] = 500;
    m['M'-'A'] = 1000;

    // solution 1:
    /*
    while ((t = *s++) != '\0') {
        switch (t) {
            case 'C':
                if (*s == 'D') {
                    r += m['D'-'A'] - m['C'-'A'];
                    s++;
                } else if (*s == 'M') {
                    r += m['M'-'A'] - m['C'-'A'];
                    s++;
                } else {
                    r += m['C'-'A'];
                }
                break;
            case 'X':
                if (*s == 'L') {
                    r += m['L'-'A'] - m['X'-'A'];
                    s++;
                } else if (*s == 'C') {
                    r += m['C'-'A'] - m['X'-'A'];
                    s++;
                } else {
                    r += m['X'-'A'];
                }
                break;
            case 'I' :
                if (*s == 'V') {
                    r += m['V'-'A'] - m['I'-'A'];
                    s++;
                } else if (*s == 'X') {
                    r += m['X'-'A'] - m['I'-'A'];
                    s++;
                } else {
                    r += m['I'-'A'];
                }
                break;
            default :
                r += m[t - 'A'];
        }
    }
    */

    // solution 2:
    while ((t = *s++) != '\0') {
        if (*s > 'A' && m[t - 'A'] < m[*s - 'A']) {
            r += m[*s - 'A'] - m[t - 'A'];
            s++;
        } else {
           r += m[t - 'A'];
        }
    }

    return r;

}
