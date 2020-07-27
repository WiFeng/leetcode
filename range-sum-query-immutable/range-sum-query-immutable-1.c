typedef struct {
    int *nums;
    int numsSize;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *obj = malloc(sizeof(NumArray));
    obj->nums = nums;
    obj->numsSize = numsSize;
    return obj;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    int result = 0;
    for (; i <= j; i++) {
        result += obj->nums[i];
    }
    return result;
}

void numArrayFree(NumArray* obj) {
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 
 * numArrayFree(obj);
*/