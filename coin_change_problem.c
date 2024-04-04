#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minCoins(int coins[], int m, int V);

int main()
{
	int m,V;
	printf("\n No. of coin-denominations available: ");
	scanf("%d",&m);
	int coins[m];
	printf("\n Enter amount of money which has to be changed with coins: ");
	scanf("%d",&V);
	
	for(int i=0;i<m;i++)
		coins[i]=i+1;
    
    printf("\n\n Minimum number of coins required: %d\n", minCoins(coins, m, V));
    return 0;
}

int minCoins(int coins[], int m, int V)
{
    int *dp = (int *)malloc((V + 1) * sizeof(int));

    dp[0] = 0;
    for (int i = 1; i <= V; i++) {
        dp[i] = INT_MAX;
    }

    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < m; j++) {
            if (coins[j] <= i) {
                int sub_res = dp[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < dp[i]) {
                    dp[i] = sub_res + 1;
                }
            }
        }
    }

    int result = dp[V];
    free(dp);
    return result;
}