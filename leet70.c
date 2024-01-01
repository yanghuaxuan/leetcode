#include <stdlib.h>
#include <stdio.h>

int *mem = NULL; /* memoization table */

/* disguised fibonacci */
int _climbStairs(int n) {
    if (n <= 1)
        return 1;
    if (mem[n] != 0) {
	return mem[n];
    }
    for (int i = n; i <= n; i++) {
        mem[i] = _climbStairs(n-1) + _climbStairs(n-2);
    }
    return mem[n];
}

int climbStairs(int n) {
    mem = calloc(sizeof(int), n+1);
    if (mem == NULL) 
        exit(1);
    mem[0] = 1;
    mem[1] = 1;
    int f = _climbStairs(n);
    free(mem);
    return f;
}

int main(void) {
    printf("%d\n", climbStairs(3));
}
