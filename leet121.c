#include <stdio.h>
#include <limits.h>

int maxProfit(int* prices, int pricesSize) {
    int max_profit = 0;
    int cheapest_buy = INT_MAX;
    for (int i = 0; i < pricesSize; i++) {
	if (prices[i] < cheapest_buy)	 {
	    cheapest_buy = prices[i];
	} else if (prices[i] - cheapest_buy > max_profit) {
	    max_profit = prices[i] - cheapest_buy;
	}
    }

    return max_profit;
}

int main(void) {
    int arr[] = {4,1,5,2,7};

    printf("%d\n", maxProfit(arr, 5));
}

