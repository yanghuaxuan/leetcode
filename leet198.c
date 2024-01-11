#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct hash_node {
    int id, val;
    struct hash_node* next;
} hash_node_t;

#define HASH_SIZE 20
hash_node_t** memoize = NULL;

static int hash(int id) {
    return id % HASH_SIZE;
}

static int get(int id) {
    hash_node_t* n = memoize[hash(id)];
    while (n != NULL) {
	if (n->id == id)
	    return n->val; /* noop */
	n = n->next;
    }
    return -1;
}

static void insert(int id, int val) {
    if (get(id) >= 0) {
	return;
    }

    hash_node_t* tmp = memoize[hash(id)];
    hash_node_t* new = malloc(sizeof(hash_node_t));
    if (new == NULL)
	return;
    new->id = id;
    new->val = val;
    new->next = tmp;
    memoize[hash(id)] = new;
}

static void destroy() {
    for (int i = 0; i < HASH_SIZE; i++) {
	hash_node_t* n = memoize[i];
	while (n != NULL) {
	    hash_node_t* tmp = n->next;
	    free(n);
	    n = tmp;
	}
    }
    free(memoize);
    memoize = NULL;
}

int peek(int* nums, int pos, int numsSize) {
    if (pos >= numsSize) {
        return 0;
    }
    int c = get(pos);
    if (c >= 0)
	return c;

    int a = nums[pos] + peek(nums, pos+2, numsSize);
    int b = peek(nums, pos+1, numsSize);
    int r = (a > b) ? a : b;
    insert(pos, r);
    return r;
}

int rob(int* nums, int numsSize) {
    memoize = malloc(HASH_SIZE * sizeof(hash_node_t *));
    if (memoize == NULL)
	exit(1);
    for (int i = 0; i < HASH_SIZE; i++) {
	memoize[i] = NULL;
    }
    int r = peek(nums, 0, numsSize);
    destroy();
    return r;
}

int main(void) {
    int nums[] = {2,7,9,3,1};
    int nums2[] = {226,174,214,16,218,48,153,131,128,17,157,142,88,43,37,157,43,221,191,68,206,23,225,82,54,118,111,46,80,49,245,63,25,194,72,80,143,55,209,18,55,122,65,66,177,101,63,201,172,130,103,225,142,46,86,185,62,138,212,192,125,77,223,188,99,228,90,25,193,211,84,239,119,234,85,83,123,120,131,203,219,10,82,35,120,180,249,106,37,169,225,54,103,55,166,124};
    int nums3[] = {6,3,10,8,2,10,3,5,10,5,3};

    
    int r = rob(nums, 5);
    printf("r: %d\n", r);
    assert(r == 12);
    int r2 = rob(nums2,  55);
    printf("r2: %d\n", r2);
    int r3 = rob(nums2,  sizeof(nums2) / sizeof(int));
    printf("r3: %d\n", r3);
//    int r3 = rob(nums3, sizeof(nums3) / sizeof(int));
//    printf("r3: %d\n", r3);
}
