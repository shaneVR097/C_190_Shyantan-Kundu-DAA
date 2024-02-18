#include <stdio.h>

int partition(int arr[],int p,int q)
{
	int t,s=p,e=q,piv=arr[p];
	while(s<e)
	{
		while(arr[s]<=piv)
			s++;
		while(arr[e]>piv)
			e--;
		if(s<e)
		{
			t=arr[s];
			arr[s]=arr[e];
			arr[e]=t;
		}
	}
	t=arr[e];
	arr[e]=arr[p];
	arr[p]=t;
	return e;
}

void quick(int arr[], int p, int q, int n) 
{
	float med='\0';
	int med_bfr,med_aftr;
    if (p < q) 
	{
        int mid;
		mid = partition(arr, p, q);
        
		if (n % 2 == 1 && mid == n / 2) 
            med=(float)arr[mid], med_bfr=arr[mid-1], med_aftr=arr[mid+1];
		else if (n % 2 == 0 && (mid == n / 2 - 1 || mid == n / 2) )
        	if(mid == n / 2 - 1)
            	med=(float)(arr[mid] + arr[mid+1]) / 2, med_bfr=arr[mid-1], med_aftr=arr[mid];
        	else if(mid == n / 2 )
        		med=(float)(arr[mid-1] + arr[mid]) / 2, med_bfr=arr[mid-1], med_aftr=arr[mid];
        else
        	med='\0';
        	
        if(med!='\0')
        	printf("\n\n The Median is: %.2f with neighbours,\n before median: %d & after median: %d\n", med, med_bfr, med_aftr );
        	
        quick(arr, p, mid - 1, n);
        quick(arr, mid + 1, q, n);
    }
}

int main() 
{
    int p, q, i, sz, n;
    printf("\n Enter no. of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("\n Enter %d elements into the array:\n ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sz = sizeof(arr) / sizeof(arr[0]);
    q = sz - 1;
    p = 0;
    printf("\n The array is...\n\n ");
    for (i = 0; i < sz; i++)
        printf("%d, ", arr[i]);
    quick(arr, p, q, n);
    printf("\n\n The Sorted array is...\n\n ");
    for (i = 0; i < sz; i++)
        printf("%d, ", arr[i]);
    return 0;
}