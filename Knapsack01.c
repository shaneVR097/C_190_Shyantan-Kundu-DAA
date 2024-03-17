#include <stdio.h> 

int max(int a, int b) 
{ 
	return (a > b) ? a : b; 
} 

int knapSack(int W, int wt[], int val[], int n) 
{ 
	
	if (n == 0 || W == 0) 
		return 0; 

	
	if (wt[n - 1] > W) 
		return knapSack(W, wt, val, n - 1); 
	else
		return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1)); 
} 

// Driver code 
int main() 
{ 
	int n,wt,i;
	printf("\n Enter no. of Items and weight of Knapsack: ");
	scanf("%d %d",&n,&wt);
	int prf[n], wgt[n];
	
	for(i=0;i<n;i++)
	{
		printf("\n Enter Profit & Weight for Item no. %d: ",i+1);
		scanf("%d %d",&prf[i],&wgt[i]);
	}
	
	printf("\n\nMaximum profit obtainable without btreaking any item is: %d", knapSack(wt, wgt, prf, n)); 
	return 0; 
}
