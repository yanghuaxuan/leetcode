#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int k = 0;
    int c = 0; /* number of dupes */
    int l = numsSize; /* loop bound */

    while (k < l) {
        /* count dupes */
        int i = k;
        for (; i < l && nums[i] == nums[k]; i++) {
            if (nums[i] == nums[k]) {
                c++;
            }
        }
	if (c > 2) {
            /* i is now first non-duplicate element, so 
            shift all the elements after i to the left.
            We can do this by swapping with element s. */
            int s = k + 2;
            for (; i < l; i++) {  
                int tmp = nums[i];
                nums[i] = nums[s];
                nums[s] = tmp;

                s++;
            }
	    l -= (c - 2);
        } 
	k++;
        c = 0;
    }

    return k;
}

int main() {
    int nums[] = {0,0,1,1,1,1,2,3,3,3}; // Input array
    int expected_nums[] = {0,0,1,1,2,2,3,3};
 
    int k = removeDuplicates(nums, 10); // Calls your implementation

    for (int i = 0; i < k; i++) {
	printf("%d ", nums[i]);
    }
    printf("\n");
}
