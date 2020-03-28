int maxArea(int* height, int heightSize){
    int m = 0;
    int z = 0, t = 0;
    bool l = true;

    for (int i = 0, j = heightSize - 1; i < j;) {
        z = height[i];
        l = true;
        if (height[i] > height[j]) {
            z = height[j];
            l = false;
        }
        t = (j -i) * z;
        if (t > m) {
            m = t;
        }
        if (l) {
            i++;
        } else {
            j--;
        }
    }

    return m;
}
