#include <stdio.h>
#include <stdlib.h>

// Structure for an item which stores weight and corresponding value of Item
struct Item 
{
    int profit, weight;
};

// Main greedy function to solve problem
double fractionalKnapsack(int wt, struct Item knp[], int n)
{
    // Selection sort to sort items based on profit/weight ratio
    for (int i = 0; i < n - 1; i++) 
	{
        for (int j = i + 1; j < n; j++) 
		{
            double r1 = (double)knp[i].profit / (double)knp[i].weight;
            double r2 = (double)knp[j].profit / (double)knp[j].weight;
            if (r1 < r2) 
			{
                struct Item t = knp[i];
                knp[i] = knp[j];
                knp[j] = t;
            }
        }
    }

    double finalprofit = 0.0;

    for (int i = 0; i < n; i++) 
	{
        if (knp[i].weight <= wt) 
		{
            wt -= knp[i].weight;
            finalprofit += knp[i].profit;
        }
        else 
		{
            finalprofit += knp[i].profit * ((double)wt / (double)knp[i].weight);
            break;
        }
    }

    return finalprofit;
}

int main()
{
    int n,wt;
    printf("\n\tEnter the Number of Items and Weight of Knapsack: ");
    scanf("%d %d", &n, &wt);

    struct Item* knp = (struct Item*)malloc(n * sizeof(struct Item));

    for (int i = 0; i < n; i++) 
	{
        printf("\n\tEnter profit and weight for item %d: ", i + 1);
        scanf("%d %d", &knp[i].profit, &knp[i].weight);
    }
    
    printf("\n\n\tMaximum value in knapsack = %.2f\n", (double)fractionalKnapsack(wt, knp, n));

    free(knp);
    return 0;
}
