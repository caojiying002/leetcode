#include <stdio.h>

static int nums[] = {-1, 0, 3, 5, 9, 12};

int search(int* nums, int numsSize, int target);
int search_range(int* nums, int low, int high, int target);

int main() {
    int target, index;

    /* expectation: 9 exists in nums and its index is 4 */
    target = 9;
    index = search(nums, sizeof(nums) / sizeof(int), target);
    printf("finding %d in nums, its index is %d\n", target, index);

    /* expectation: 2 does not exist in nums so return -1 */
    target = 2;
    index = search(nums, sizeof(nums) / sizeof(int), target);
    printf("finding %d in nums, its index is %d\n", target, index);

    return 0;
}

int search(int* nums, int numsSize, int target){
    if (nums == (void *)0 || numsSize <= 0) {
        printf("nums is nullptr or empty, return -1\n");
        return -1;
    }
    return search_range(nums, 0, numsSize-1, target);
}

int search_range(int* nums, int low, int high, int target){
    if (low == high)
        return target == nums[low] ? low : -1;

    int mid = (low+high) / 2;
    if (target == nums[mid])
        return mid;
    else if(target > nums[mid])
        return search_range(nums, mid+1, high, target);
    else
        return search_range(nums, low, mid, target);
}

