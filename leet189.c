#include <stdio.h>

/* reverse an array from start (inclusive), to end (exclusive) */
void reverse(int *a, int start, int end) {
    end -= 1;
    while (start < end) {
	int tmp = a[start];
	a[start] = a[end];
	a[end] = tmp;

	end--;
	start++;
    }
}

void rotate(int* nums, int numsSize, int k) {
    int rot = k % numsSize; /* actual rotation relative to numsSize */
    int part = numsSize - rot;

    reverse(nums, 0, part);
    reverse(nums, part, numsSize);
    reverse(nums, 0, numsSize);
}

int main(void) {
    const int arrSize = 7;
    int arr[] = {1,2,3,4,5,6,7};

    rotate(arr, arrSize, 3);

    for(int i = 0; i < arrSize; i++) {
	printf("%d ", arr[i]);
    }

    printf("\n");
}
