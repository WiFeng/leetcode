

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){

    double r = 0;

    int t = nums1Size + nums2Size;
    int t1 = nums1Size - 1, t2 = nums2Size - 1;
    int e[t];

    for (int i = t - 1; i >= 0; i--) {
        if (t1 >= 0 && t2 >= 0) {
            if (nums1[t1] > nums2[t2]) {
                e[i] = nums1[t1];
                t1--;
            } else {
                e[i] = nums2[t2];
                t2--;
            }
        } else if (t1 >= 0) {
            e[i] = nums1[t1--];
        } else if (t2 >= 0) {
            e[i] = nums2[t2--];
        } else {
            continue;
        }
    }

    if (t < 2) {
        r = e[0];
    } else if (t % 2 > 0) {
        r = e[(t / 2) ];
    } else {
        r = (e[(t / 2) - 1] + e[t / 2]) / 2.0;
    }

    return r;
}


