typedef struct {
    int *nums;
    int numsSize;
    int *cache;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    
    NumArray *obj = malloc(sizeof(NumArray));
    obj->nums = nums;
    obj->numsSize = numsSize;
    obj->cache = NULL;

    if (numsSize < 1) {
        return obj;
    }

    int *cache = malloc(sizeof(int) * numsSize);
    obj->cache = cache;

    cache[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        cache[i] = cache[i-1] + nums[i];
    }

    return obj;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    int result;

    if (i > 0) {
        result = obj->cache[j] - obj->cache[i-1];
    } else {
        result = obj->cache[j];
    }

    return result;
}

void numArrayFree(NumArray* obj) {
    free(obj->cache);
    free(obj);
}


/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 
 * numArrayFree(obj);
*/