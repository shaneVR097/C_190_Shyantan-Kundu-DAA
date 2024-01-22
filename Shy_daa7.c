#include<stdio.h>
void merge(int a[], int lb, int mid, int ub)
{
	int i=lb,j=mid+1,k=lb,b[ub+1];
	while(i<=mid && j<=ub)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			i++;
		}
		else
		{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	
	while(i<=mid)
	{
		b[k]=a[i];
		i++;
		k++;
	}
	
	while(j<=ub)
	{
		b[k]=a[j];
		j++;
		k++;
	}
	
	for(i=lb;i<=ub;i++)
	{
		a[i]=b[i];
	}	
}

void Mergesort(int a[],int lb, int ub)
{
	if(lb<ub)
	{
		int mid=(lb+ub)/2;
		Mergesort(a, lb, mid);
		Mergesort(a, mid+1, ub);
		merge(a, lb, mid, ub);
	}
}

int main()
{
	int n,i;
	printf("\n Enter number of elements in array: ");
	scanf("%d",&n);
	int a[n], lb=0,ub=n-1;
	printf("\n Enter %d elements into the array:\n ",n);
	for(i=lb;i<=ub;i++)
	{
		scanf("%d",&a[i]);
	}
	Mergesort(a, lb, ub);
	printf("\n Sorted elements of the array:\n ");
	for(i=0;i<n;i++)
	{
		printf("%d, ",a[i]);
	}
	printf("\n 2nd smallest element is: %d\n 2nd greatest element: %d \n",a[1],a[n-2]);
}

/*
output:
Enter number of elements in array: 10

 Enter 10 elements into the array:
 3 5 6 7 1 8 9 0 2 4

 Sorted elements of the array:
 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
 2nd smallest element is: 1
 2nd greatest element: 8 
*/
