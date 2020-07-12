class Solution {

    private int[] index;
    private int[] temp;
    private int[] tempIndex;
    private int[] res;

    public List<Integer> countSmaller(int[] nums) {
        List<Integer> result = new ArrayList<>();

        this.index = new int[nums.length];
        this.temp = new int[nums.length];
        this.tempIndex = new int[nums.length];
        this.res = new int[nums.length];

        for (int i = 0; i < nums.length; i++) {
            index[i] = i;
        }

        int l = 0, r = nums.length - 1;
        mergeSort(nums, l, r);

        for (int i = 0; i < nums.length; i++) {
            result.add(res[i]);
        }

        return result;
    }

    private void mergeSort(int[] a, int l, int r) {
        if (l >= r) {
            return;
        }

        int mid = (l + r) >> 1;
        mergeSort(a, l, mid);
        mergeSort(a, mid+1, r);
        merge(a, l, mid, r);
    }

    private void merge(int[] a, int l, int mid, int r) {
        int i = l, j = mid + 1, p = l;
        while (i <= mid && j <= r) {
            if (a[i] <= a[j]) {
                temp[p] = a[i];
                tempIndex[p] = index[i];
                res[index[i]] += (j - mid - 1);
                i++;
                p++;
            } else {
                temp[p] = a[j];
                tempIndex[p] = index[j];
                j++;
                p++;
            }
        }

        while (i <= mid) {
            temp[p] = a[i];
            tempIndex[p] = index[i];
            res[index[i]] += (j - mid - 1);
            i++;
            p++;
        }

        while (j <= r) {
            temp[p] = a[j];
            tempIndex[p] = index[j];
            j++;
            p++;
        }

        for (int k = l; k <= r; k++) {
            index[k] = tempIndex[k];
            a[k] = temp[k];
        }
    }
}