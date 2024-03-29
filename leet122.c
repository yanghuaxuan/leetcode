#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <stdbool.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0)
        return 0;

    int cheapest_buy = prices[0];
    int cur_max_profit = 0;
    int max_profit = 0;
    for (int i = 1; i < pricesSize; i++) {
	if (cur_max_profit > prices[i] - cheapest_buy) { /* sell */
	    max_profit += cur_max_profit;
	    cur_max_profit = 0;
	    cheapest_buy = prices[i];
	}  else if (cur_max_profit <= prices[i] - cheapest_buy) { /* hold */
	    cur_max_profit = prices[i] - cheapest_buy;
	}  else {
	    cheapest_buy = prices[i];
	}
    }

    if (cur_max_profit > 0) {
	max_profit += cur_max_profit;
    }

    return max_profit;
}

int main(void) {
    int arr[] = {7, 1, 5, 3, 6, 4};
//    int arr2[] = {3, 3};
//    int arr3[] = {6,1,3,2,4,7};
    int arr4[] = {2,1,2,0,1};

//    printf("%d\n", maxProfit(arr4, 5));

    printf("profif: %d\n", maxProfit(arr, 6));
    assert(maxProfit(arr, 6) == 7);
//    assert(maxProfit(arr2, 2) == 0);
//    assert(maxProfit(arr3, 6) == 7);
    printf("profif 2: %d\n", maxProfit(arr4, 5));
    assert(maxProfit(arr4, 5) == 2);
}

