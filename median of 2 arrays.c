#include <stdio.h>

float findMedian(int a[], int b[], int sz) 
{
    int n = sz*2; 
    int lft = (sz*2 + 1) / 2; 
    int l = 0, h = sz; 
    while (l <= h) 
	{ 
        int m1 = (l + h) / 2; 
        int m2 = lft - m1; 

        int l1 = (m1 > 0) ? a[m1 - 1] : 0;
        int l2 = (m2 > 0) ? b[m2 - 1] : 0;
        int r1 = (m1 < sz) ? a[m1] : 0;
        int r2 = (m2 < sz) ? b[m2] : 0;

        if (l1 <= r2 && l2 <= r1) 
            	return (float) (l1 > l2 ? (l1 + (r1 < r2 ? r1 : r2)) / 2.0 : (l2 + (r1 < r2 ? r1 : r2)) / 2.0); // even number of elements 
		else if (l1 > r2)
            h = m1 - 1;
        else
            l = m1 + 1;
    } 
}

int main() 
{
    int n, i;
    printf("\n Enter the same-size for 2 Sorted-arrays: ");
    scanf("%d", &n);
    int a[n], b[n];
    
    printf("\n Enter %d elements into the 1st Sorted-array:\n ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
	
	printf("\n Enter %d elements into the 2nd Sorted-array:\n ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);
        
    printf("\n\n The merged & sorted array is...\n\n ");
    for (i = 0; i < n; i++)
    {
    	if(a[i]>b[i])
    		printf("%d, %d, ",b[i],a[i]);
    	else
    		printf("%d, %d, ",a[i],b[i]);
    	
	}
        
    printf("\n\n The median after merging the two arrays is: %.2f\n", findMedian(a, b, n));
}